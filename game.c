#include "button.h"
#include "led.h"
#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include <stdbool.h>

#define PACER_RATE 1000
#define MESSAGE_RATE 25

static int p1_is_ready = 0;
static int p2_is_ready = 0;
static char p2_choice;
static char result;
static char p2_choice;
static int choice = 1;
static const char item_select[3] =
{
	'R', 'P', 'S'
};

//display function
void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

void welcome (void)
{

    tinygl_text("Move stick to start");
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
}


static char select_item(void)
{
    int i = 0;


    while (1) {
		pacer_wait ();
		tinygl_update ();
        navswitch_update ();        
        if (p1_is_ready == 0) {
            if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
                choice++;
                i=1;
                if (choice > 2) {
                    choice = 0;
                }
            } else if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
                choice--;
                i=1;
                if (choice <0) {
                    choice = 2;
                }
            } else if (navswitch_push_event_p (NAVSWITCH_EAST)) {
                choice++;
                i=1;
                if (choice > 2) {
                    choice = 0;
                }
            } else if (navswitch_push_event_p (NAVSWITCH_WEST)) {
                choice--;
                i=1;
                if (choice <0) {
                    choice = 2;
                }
            } else if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
				ir_uart_putc(item_select[choice]);
				p1_is_ready = 1;
				led_on ();
				
			}
			if(i == 1) {
                display_character(item_select[choice]);
            }
        }
	}
	return item_select[choice];
}

static char get_player2_state (void)
{
    //receive from p2
    if (ir_uart_read_ready_p ()) {
        p2_choice = ir_uart_getc ();
        if(p2_choice != '\0') {
            p2_is_ready = 1;
        }
    }
    return p2_choice;
}

void end_result (char player1_state, char p2_choice)
{
    //compare the tow choice and display the result
    if (p1_is_ready == 1 && p2_is_ready == 1) {
        if(player1_state == p2_choice) {
            result = 'D';
        } else if (player1_state == 'P' && p2_choice == 'S') {
            result = 'L';
        } else if (player1_state == 'S' && p2_choice == 'R') {
            result = 'L';
        } else if (player1_state == 'R' && p2_choice == 'P') {
            result = 'L';
        } else if (player1_state == 'S' && p2_choice == 'P') {
            result = 'W';
        } else if (player1_state == 'R' && p2_choice == 'S') {
            result = 'W';
        } else if (player1_state == 'P' && p2_choice == 'R') {
            result = 'W';
        }

        //display the result
        display_character(result);
    }
}

static void game_reset (void)
{
    if (button_pressed_p()) {
        p1_is_ready = 0;
        p2_is_ready = 0;
        choice = 0;
        led_off();
    }
}



//main function for the game
int main (void)
{
    //initilized for all function
    led_init ();
    button_init ();
    system_init ();
    navswitch_init ();
    ir_uart_init ();
    pacer_init (PACER_RATE);
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);


    welcome();

    //while loop for the game
    while (1) {

        char player1_state = '\0';
        char player2_state = '\0';
        player1_state = select_item();
        player2_state = get_player2_state();
        end_result(player1_state, player2_state);
        game_reset();
    }
}
