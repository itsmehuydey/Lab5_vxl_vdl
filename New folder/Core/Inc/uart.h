/*
 * uart.h
 *
 *  Created on: Nov 11, 2024
 *      Author: pc
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "main.h"
#include "software_timer.h"
#include "stdio.h"
#include "stdlib.h"
#include "global.h"
#include "parser.h"

void uart_communiation_fsm(ADC_HandleTypeDef hadc1, UART_HandleTypeDef huart2);


#endif /* INC_UART_H_ */
