/** @file   initialise.h
    @author Mary Hongthongkhan and Saman Ighani
    @date   16/10/2018
    @brief 	initialises all modules and variables
    @note 	This module is in charge of initialising all variables and 
			modules for the main game.
*/
#ifndef INITIALISE_H
#define INITIALISE_H

#include "button.h"
#include "led.h"
#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"

int i;
int player1_chose;
int player1;
int player2;
char win_draw_lose;
char player2_chose;
int choose;

static const char choices[3];

void initialize_func(void);
#endif
