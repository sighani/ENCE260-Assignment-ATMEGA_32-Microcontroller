/** @file   send_recieve.h
    @author Mary Hongthongkhan and Saman Ighani
    @date   16/10/2018
    @brief 	Infrared send and recieve
    @note 	This module is in charge of sending and receiving characters
			that have been selected by both units throught the infrared.
*/
#ifndef SEND_RECEIVE_H
#define SEND_RECEIVE_H

#include "navswitch.h"
#include "ir_uart.h"
#include "led.h"


void send_recieve(void);
#endif
