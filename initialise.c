/** @file   initialise.c
    @author Mary Hongthongkhan and Saman Ighani
    @date   16/10/2018
    @brief 	initialises all modules and variables
    @note 	This module is in charge of initialising all variables and 
			modules for the main game.
*/

#include "button.h"
#include "led.h"
#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

#define PACER_RATE 1000
#define MESSAGE_RATE 10

int i = 0;
int player1_chose=1;
int player1 = 0;
int player2 = 0;
char win_draw_lose= 0;
char player2_chose = 0;
int choose = 0;
static const char choices[3] =
{
    'R', 'P', 'S'
};
void initialize_func(void)
{
    led_init ();
    button_init ();
    system_init ();
    navswitch_init ();
    ir_uart_init ();
    pacer_init (PACER_RATE);
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
}
