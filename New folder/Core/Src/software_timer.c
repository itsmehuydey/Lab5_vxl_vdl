/*
 * software_timer.c
 *
 *  Created on: Nov 11, 2024
 *      Author: pc
 */


#include "software_timer.h"

int TIME_CYCLE = 10; // Time cycle

// Khoi tao cac mang timer_counter va timer_flag voi so luong phan tu moi mang bang NUM_OF_TIMERS
int timer_counter[NUM_OF_TIMERS] = {0};
int timer_flag[NUM_OF_TIMERS] = {0};
int timer_counter0 = 0, timer_flag0 = 0 ;
// setTimer (index: Timer duoc xet toi; duration: Thoi gian setTimer (don vi: ms))
void setTimer(int index, int duration) {
	timer_counter[index] = duration / TIME_CYCLE;
	timer_flag[index] = 0;
}

//void setTimer0(int duration) {
//	timer_counter0 = duration / TIME_CYCLE;
//	timer_flag0 = 0;
//}

// clearTimer (timer_flag[index] = 0, timer_counter[index] = 0)
void clearTimer(int index) {
	timer_counter[index] = 0;
	timer_flag[index] = 0;
}

// timerRun
//void timerRun0(){
//		if (timer_counter0 > 0){
//			timer_counter0--;
//			if (timer_counter0 <= 0){
//				timer_flag0 = 1;
//			}
//		}
//	}

void timerRun(){
	for (int i = 0; i < NUM_OF_TIMERS; i++) {
		if (timer_counter[i] > 0){
			timer_counter[i]--;
			if (timer_counter[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}
