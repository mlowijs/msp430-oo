#ifndef CORE_DCOCLOCKSPEED_H_
#define CORE_DCOCLOCKSPEED_H_

#include <msp430.h>

enum DcoClockSpeed {
#ifdef CAL_DCO_1MHZ
	Dco1MHz = 0,
#endif

#ifdef CAL_DCO_8MHZ
	Dco8MHz = 1,
#endif

#ifdef CAL_DCO_12MHZ
	Dco12MHz = 2,
#endif

#ifdef CAL_DCO_16MHZ
	Dco16MHz = 3
#endif
};

#endif
