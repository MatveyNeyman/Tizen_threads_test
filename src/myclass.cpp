/*
 * myclass.cpp
 *
 *  Created on: Dec 11, 2016
 *      Author: Administrator
 */

#include "myclass.h"
#include <dlog.h>

void MyClass::timerPrinter() {
	set_notifier(calc_done);
	Input *input = new Input();
	input->count = 10;
	start_calcs(input);
}

void MyClass::calc_done(Output *output) {
	dlog_print(DLOG_INFO, "MY_CLASS", "Printing count: %d", output->result);
}
