/*
 * calc_thread.h
 *
 *  Created on: Dec 12, 2016
 *      Author: Administrator
 */

#ifndef CALC_THREAD_H_
#define CALC_THREAD_H_

#include "Eina.h"
#include "Ecore.h"
#include <dlog.h>

#define INTERVAL 5

typedef struct {
	int count;
} Input;

typedef struct {
	int result;
} Output;

typedef void(*result_callback)(Output *output);
void set_notifier(result_callback rc);
void start_calcs(Input *input);
void stop_calcs();

#endif /* CALC_THREAD_H_ */
