#ifndef TIMERA_H_
#define TIMERA_H_

#include <msp430.h>

#include "InputDivider.h"
#include "OutputMode.h"
#include "TimerClockSource.h"
#include "TimerMode.h"

class TimerA {
public:
	void Reset();

	void StartTimer(TimerMode mode);
	void StopTimer();

	void SetClockSource(TimerClockSource clockSource, InputDivider divider);

#ifdef TACCR0
	void SetCaptureCompareRegister0Value(unsigned int value);
	void EnableOutputPin0();
#endif

#ifdef TACCR1
	void SetCaptureCompareRegister1Value(unsigned int value);
	void SetOutputMode1(OutputMode outputMode);
	void EnableOutputPin1();
#endif

#ifdef TACCR2
	void SetCaptureCompareRegister2Value(unsigned int value);
	void SetOutputMode2(OutputMode outputMode);

#ifdef P3SEL
	void EnableOutputPin2();
#endif

#endif
};

#endif
