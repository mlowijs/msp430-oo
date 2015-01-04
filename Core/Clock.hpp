#ifndef CORE_CLOCK_HPP_
#define CORE_CLOCK_HPP_

#include <msp430.h>

#include "DcoClockSpeed.h"

class Clock {
private:
	static unsigned char _clockSpeedMhz;

	Clock();

public:
	static void SetDcoClockSpeed(DcoClockSpeed clockSpeed) {
		_clockSpeedMhz = clockSpeed;

		switch (clockSpeed) {
#ifdef CAL_DCO_1MHZ
			case Dco1MHz:
				BCSCTL1 = CALBC1_1MHZ;
				DCOCTL = CALDCO_1MHZ;
				break;
#endif

#ifdef CAL_DCO_8MHZ
			case Dco8MHz:
				BCSCTL1 = CALBC1_8MHZ;
				DCOCTL = CALDCO_8MHZ;
				break;
#endif

#ifdef CAL_DCO_12MHZ
			case Dco12MHz:
				BCSCTL1 = CALBC1_12MHZ;
				DCOCTL = CALDCO_12MHZ;
				break;
#endif

#ifdef CAL_DCO_16MHZ
			case Dco16MHz:
				BCSCTL1 = CALBC1_16MHZ;
				DCOCTL = CALDCO_16MHZ;
				break;
#endif
		}
	}

	static void Sleep(unsigned char ms) {
		for (unsigned char i = 0; i < _clockSpeedMhz; i++) {
			for (unsigned char j = 0; j < ms; j++)
				__delay_cycles(1000);
		}
	}
};

unsigned char Clock::_clockSpeedMhz = 1;

#endif
