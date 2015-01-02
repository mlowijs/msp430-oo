#ifndef WATCHDOGTIMER_H_
#define WATCHDOGTIMER_H_

#include <msp430.h>

class WatchdogTimer {
public:

	static void Hold() {
		WDTCTL = WDTPW | WDTHOLD;
	}
};

#endif
