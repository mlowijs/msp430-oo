#ifndef CORE_LOWPOWERMODE_H_
#define CORE_LOWPOWERMODE_H_

#include <msp430.h>

enum LowPowerMode {
	Mode0 = LPM0_bits,
	Mode1 = LPM1_bits,
	Mode2 = LPM2_bits,
	Mode3 = LPM3_bits,
	Mode4 = LPM4_bits
};

#endif
