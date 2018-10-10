#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

#define PACER_RATE 2000
#define MESSAGE_RATE 10

void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}


int main (void)
{
    system_init ();
    ir_uart_init ();
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    navswitch_init ();

    /* TODO: Initialise IR driver.  */
    tinygl_text("START!\0");

    while (1)
    {
        //int count =0;
        pacer_wait ();
        tinygl_update ();
        navswitch_update();
        /* TODO: Call the navswitch update function.  */
        if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
            display_character ('R');
            ir_uart_putc('R');
            count++;
            if (ir_uart_read_ready_p()) {
                if (ir_uart_getc() == 'R') {
                    display_character('0');
                } else if (ir_uart_getc() == 'S') {
                    display_character('W');
                } else if (ir_uart_getc() == 'P') {
                    display_character('L');
                }
            }
        } else if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {
            display_character ('P');
            ir_uart_putc('P');
            count++;
            if (ir_uart_read_ready_p()) {
                if (ir_uart_getc() == 'P') {
                    display_character('0');
                } else if (ir_uart_getc() == 'S') {
                    display_character('L');
                } else if (ir_uart_getc() == 'R') {
                    display_character('W');
                }
            }
        } else if (navswitch_push_event_p(NAVSWITCH_WEST)) {
            display_character ('S');
            ir_uart_putc('S');
            count++;
            if (ir_uart_read_ready_p()) {
                if (ir_uart_getc() == 'S') {
                    display_character('0');
                } else if (ir_uart_getc() == 'P') {
                    display_character('W');
                } else if (ir_uart_getc() == 'R') {
                    display_character('L');
                    }
                    }
                    }
                }
        return 0;
}