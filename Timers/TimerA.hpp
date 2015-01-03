#ifndef TIMERS_TIMERA_H_
#define TIMERS_TIMERA_H_

#include <msp430.h>

#include "InputDivider.h"
#include "OutputMode.h"
#include "TimerClockSource.h"
#include "TimerMode.h"

unsigned char timerACcrOutputPort[] = { 1, 1, 3 };
unsigned char timerACcrOutputPin[] = { 1, 2, 0 };

#ifdef __MSP430_HAS_TA3__
class TimerA {
private:
	volatile unsigned int *_ccr0, *_ccr1, *_ccr2, *_cctl0, *_cctl1, *_cctl2, *_ctl;
public:
	TimerA(unsigned char num) {
		if (num == 0) {
			_ccr0 = &TA0CCR0;
			_ccr1 = &TA0CCR1;
			_ccr2 = &TA0CCR2;
			_cctl0 = &TA0CCTL0;
			_cctl1 = &TA0CCTL1;
			_cctl2 = &TA0CCTL2;
			_ctl = &TA0CTL;
		}

#ifdef __MSP430_HAS_T1A3__
		if (num == 1) {
			_ccr0 = &TA1CCR0;
			_ccr1 = &TA1CCR1;
			_ccr2 = &TA1CCR2;
			_cctl0 = &TA1CCTL0;
			_cctl1 = &TA1CCTL1;
			_cctl2 = &TA1CCTL2;
			_ctl = &TA1CTL;
		}
#endif
	}


	void Start(TimerMode mode) {
		*_ctl |= mode << 4;
	}

	void Stop() {
		*_ctl |= MC_0;
	}

	void Reset() {
		*_ctl |= TACLR;
		P1SEL &= ~(1 << 1);
	}


	void SetClockSource(TimerClockSource clockSource, InputDivider divider) {
		*_ctl |= (clockSource << 8) | (divider << 6);
	}


	void EnableOutputPin(unsigned char ccrNum) {
		unsigned char pin = timerACcrOutputPin[ccrNum];

		switch (timerACcrOutputPort[ccrNum]) {
			case 1:
				P1DIR |= (1 << pin);
				P1SEL |= (1 << pin);
				break;
			case 2:
				P2DIR |= (1 << pin);
				P2SEL |= (1 << pin);
				break;
			case 3:
				P3DIR |= (1 << pin);
				P3SEL |= (1 << pin);
				break;
		}
	}

	void SetCaptureCompareRegister(unsigned char ccrNum, unsigned int value) {
		switch (ccrNum) {
			case 0:
				*_ccr0 = value;
				break;
			case 1:
				*_ccr1 = value;
				break;
			case 2:
				*_ccr2 = value;
				break;
		}
	}

	void SetOutputMode(unsigned char ccrNum, OutputMode outputMode) {
		switch (ccrNum) {
			case 0:
				*_cctl0 |= outputMode << 5;
				break;
			case 1:
				*_cctl1 |= outputMode << 5;
				break;
			case 2:
				*_cctl2 |= outputMode << 5;
				break;
		}
	}
};
#endif

#endif
