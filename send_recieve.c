/** @file   send_recieve.c
    @author Mary Hongthongkhan and Saman Ighani
    @date   16/10/2018
    @brief 	Infrared send and recieve
    @note 	This module is in charge of sending and receiving characters
			that have been selected by both units throught the infrared.
*/

#include "navswitch.h"
#include "ir_uart.h"
#include "led.h"
#include "initialise.h"


void send_recieve(void)
{
    if (navswitch_push_event_p (NAVSWITCH_PUSH)&& i != 0) {
            ir_uart_putc(choices[choose]);
            player1 = 1;
            led_on ();
        }

    if (ir_uart_read_ready_p ()) {
        player2_chose = ir_uart_getc ();
        if(player2_chose != '\0') {
            player2 = 1;
            }
        }
}
