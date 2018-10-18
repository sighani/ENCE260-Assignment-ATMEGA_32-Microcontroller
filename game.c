/** @file   game.c
    @author Saman Ighani and Mary Hongthongkhan
    @date   16/10/2018
    @brief 	main game file
	@note 	Paper, Scissors, Rock! A game that simulates the real life 
			classic on a LED display!
*/
#include "button.h"
#include "led.h"
#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "compare.h"
#include "initialise.h"
#include "push4direc.h"
#include "send_recieve.h"

#define PACER_RATE 1000
#define MESSAGE_RATE 10


//display function
void display_character (char character)
{
    char buffer[6];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

void startgame(void)
{
    tinygl_text("start!");
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
}

void game_reset (void)
{
    if (button_pressed_p ()) {
        player1_chose = 0;
        player2_chose = 0;
        choose = 0;
        led_off();
    }
}

//main function for the game
int main (void)
{
    initialize_func(); // initialized the functions.
    startgame(); // start game by message.

    while (1) {
        pacer_wait ();
        tinygl_update ();
        navswitch_update ();

        push_4direc(); // choosing the three choices by pushing 4 directions
        send_recieve(); // send and recieve the selection of each player
        compare_2P(); //compare two players then return the result
    }
    game_reset();
}
