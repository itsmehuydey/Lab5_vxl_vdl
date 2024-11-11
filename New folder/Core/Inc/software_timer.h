/*
 * software_timer.h
 *
 *  Created on: Nov 11, 2024
 *      Author: pc
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define NUM_OF_TIMERS 	2  				// Number of Timers to use

extern int TIME_CYCLE, timer_counter0, timer_flag0  ;					// Time cycle

extern int timer_flag[NUM_OF_TIMERS];

void setTimer(int index, int duration);
void clearTimer(int index);
void timerRun();
void setTimer0();
void timerRun0();
#endif /* INC_SOFTWARE_TIMER_H_ */
