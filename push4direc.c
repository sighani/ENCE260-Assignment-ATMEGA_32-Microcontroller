/** @file   push4direc.c
    @author Mary Hongthongkhan and Saman Ighani
    @date   16/10/2018
    @brief 	Action Select
    @note 	This module is in charge of selection of an action depending
			on the direction of the navswitch.
*/

#include "system.h"
#include "navswitch.h"
#include "initialise.h"

void push_4direc(void)
{
    int select = 0;
    int choose  = 1;
    if (player1 == 0) {
            if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
                choose ++;
                select = 1;
                if (choose > 4) {
                    choose = 0;
                }
            }
            if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
                choose --;
                select = 1;
                if (choose <0) {
                    choose = 4;
                }
            }
            if (navswitch_push_event_p (NAVSWITCH_EAST)) {
                choose ++;
                select = 1;
                if (choose > 4) {
                    choose = 0;
                }
            }
            if (navswitch_push_event_p (NAVSWITCH_WEST)) {
                choose --;
                select = 1;
                if (choose <0) {
                    choose = 4;
                }
            }
            if(select == 1) {
                display_character(choices[choose]);
            }
        }
}
