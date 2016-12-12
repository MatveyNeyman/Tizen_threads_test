/*
 * myclass.h
 *
 *  Created on: Dec 11, 2016
 *      Author: Administrator
 */

#ifndef MYCLASS_H_
#define MYCLASS_H_

extern "C" {
#include "calc_thread.h"
}

class MyClass {
public:
	void timerPrinter();

private:
	static void calc_done(Output *output);
};



#endif /* MYCLASS_H_ */
