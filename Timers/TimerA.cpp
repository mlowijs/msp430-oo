#include "TimerA.h"

void TimerA::Reset() {
	TACTL |= TACLR;
	P1SEL &= ~(1 << 1);
}


void TimerA::StartTimer(TimerMode mode) {
	TACTL |= mode << 4;
}

void TimerA::StopTimer() {
	TACTL |= MC_0;
}


void TimerA::SetClockSource(TimerClockSource clockSource, InputDivider divider) {
	TACTL |= (clockSource << 8) | (divider << 6);
}

#ifdef TACCR0
/*
 * Timer A0
 */

void TimerA::SetCaptureCompareRegister0Value(unsigned int value) {
	TACCR0 = value;
}

void TimerA::EnableOutputPin0() {
	P1DIR |= (1 << 1);
	P1SEL |= (1 << 1);
}
#endif

#ifdef TACCR1
/*
 * Timer A1
 */

void TimerA::SetCaptureCompareRegister1Value(unsigned int value) {
	TACCR1 = value;
}

void TimerA::SetOutputMode1(OutputMode outputMode) {
	TACCTL1 |= outputMode << 5;
}

void TimerA::EnableOutputPin1() {
	P1DIR |= (1 << 2);
	P1SEL |= (1 << 2);
}
#endif

#ifdef TACCR2
/*
 * Timer A2
 */

void TimerA::SetCaptureCompareRegister2Value(unsigned int value) {
	TACCR2 = value;
}

void TimerA::SetOutputMode2(OutputMode outputMode) {
	TACCTL2 |= outputMode << 5;
}

#ifdef P3SEL
void TimerA::EnableOutputPin2() {
	P3DIR |= (1 << 0);
	P3SEL |= (1 << 0);
}
#endif

#endif
