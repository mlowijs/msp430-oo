#ifndef TIMERS_WATCHDOGTIMER_H_
#define TIMERS_WATCHDOGTIMER_H_

#include <msp430.h>

#ifdef __MSP430_HAS_WDT__
class WatchdogTimer {
private:
	WatchdogTimer();

public:
	static void Hold() {
		WDTCTL = WDTPW | WDTHOLD;
	}

	static void Reset() {
		WDTCTL |= WDTCNTCL;
	}
};
#endif

#endif
