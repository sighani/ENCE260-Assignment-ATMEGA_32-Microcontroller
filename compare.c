/** @file   compare.c
    @author Mary Hongthongkhan and Saman Ighani
    @date   16/10/2018
    @brief 	result calculation
    @note 	This module is in charge of calculating and displaying an 
			end result depending on the chosen selection from both
			players
*/

#include "system.h"
#include "pacer.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "initialise.h"

void compare_2P(void)
{

    if (player1 == 1 && player2 == 1) {
            if(choices[player1_chose] == player2_chose) {
                win_draw_lose = 'E';
            }  else if (choices[player1_chose] == 'S' && player2_chose == 'P') {
                win_draw_lose = 'W';
            } else if (choices[player1_chose] == 'R' && player2_chose == 'S') {
                win_draw_lose = 'W';
            } else if (choices[player1_chose] == 'P' && player2_chose == 'R') {
                win_draw_lose = 'W';
            } else if (choices[player1_chose] == 'P' && player2_chose == 'S') {
                win_draw_lose = 'L';
            } else if (choices[player1_chose] == 'S' && player2_chose == 'R') {
                win_draw_lose = 'L';
            } else if (choices[player1_chose] == 'R' && player2_chose == 'P') {
                win_draw_lose = 'L';
            }
            display_character(win_draw_lose);
        }
}
