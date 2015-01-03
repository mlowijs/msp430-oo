#ifndef CORE_CLOCK_HPP_
#define CORE_CLOCK_HPP_

#include <msp430.h>

#include "DcoClockSpeed.h"

class Clock {
private:
	Clock();

public:
	static void SetDcoClockSpeed(DcoClockSpeed clockSpeed) {
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
};

#endif
