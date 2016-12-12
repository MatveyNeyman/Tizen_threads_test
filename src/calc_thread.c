/*
 * calc_thread.c
 *
 *  Created on: Dec 12, 2016
 *      Author: Administrator
 */

#include "calc_thread.h"

Ecore_Timer *timer;
result_callback res_cb = NULL;
Input *inputData;
Output *outputData;

void run_timer();
Eina_Bool ecore_task_cb(void *data);
void func_blocking(void *data, Ecore_Thread *thread);
void func_end(void *data, Ecore_Thread *thread);
void calculate(int i);

void set_notifier(result_callback rc) {
	res_cb = rc;
}

void start_calcs(Input *input) {
	dlog_print(DLOG_INFO, "CALC", "start_calcs Input: %d", input->count);
	inputData = input;
	run_timer();
}

void stop_calcs() {
	ecore_timer_del(timer);
}

void run_timer() {
	const void *data = NULL;
	timer = ecore_timer_add(INTERVAL, ecore_task_cb, data);
}

Eina_Bool ecore_task_cb(void *data /*NULL*/) {
	const void *dataToCalc = inputData;

	dlog_print(DLOG_INFO, "CALC", "ecore_task_cb Input: %d", inputData->count);

	ecore_thread_run(func_blocking, func_end, NULL, dataToCalc);

	return ECORE_CALLBACK_RENEW;
}



void func_blocking(void *data, Ecore_Thread *thread) {
	Input *inputData = (Input *)data;

	dlog_print(DLOG_INFO, "CALC", "func_blocking Input: %d", inputData->count);

	calculate(inputData->count);

	dlog_print(DLOG_INFO, "CALC", "func_blocking calculated Input: %d", inputData->count);
}

void calculate(int i) {
	outputData = malloc(sizeof *outputData);
	outputData->result = i * 2;
}

void func_end(void *data, Ecore_Thread *thread) {
	dlog_print(DLOG_INFO, "CALC", "func_end Input: %d", inputData->count);

	res_cb(outputData);
	free(outputData);
}
