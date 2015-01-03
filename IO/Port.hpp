#ifndef IO_PORT_H_
#define IO_PORT_H_

#include <msp430.h>

#include "ResistorMode.h"

class Port {
private:
	volatile unsigned char *_dir, *_in, *_out, *_ren, *_sel, *_sel2;
public:
	Port(unsigned char num) {
#ifdef __MSP430_HAS_PORT1_R__
		if (num == 1) {
			_dir = &P1DIR;
			_in = &P1IN;
			_out = &P1OUT;
			_ren = &P1REN;
			_sel = &P1SEL;
			_sel2 = &P1SEL2;
		}
#endif

#ifdef __MSP430_HAS_PORT2_R__
		if (num == 2) {
			_dir = &P2DIR;
			_in = &P2IN;
			_out = &P2OUT;
			_ren = &P2REN;
			_sel = &P3SEL;
			_sel2 = &P3SEL2;
		}
#endif

#ifdef __MSP430_HAS_PORT3_R__
		if (num == 3) {
			_dir = &P3DIR;
			_in = &P3IN;
			_out = &P3OUT;
			_ren = &P3REN;
			_sel = &P3SEL;
			_sel2 = &P3SEL2;
		}
#endif
	}


	void AsInput(unsigned char pin, ResistorMode resistorMode) {
		*_sel &= ~(1 << pin);
		*_sel2 &= ~(1 << pin);

		if (resistorMode == Off)
			*_ren &= ~(1 << pin);
		else
			Write(pin, resistorMode == PullUp);

		*_dir &= ~(1 << pin);
	}

	void AsOutput(unsigned char pin) {
		*_sel &= ~(1 << pin);
		*_sel2 &= ~(1 << pin);

		*_dir |= (1 << pin);
	}


	bool Read(unsigned char pin) {
		return *_in & (1 << pin);
	}

	void Write(unsigned char pin, bool state) {
		if (state)
			*_out |= (1 << pin);
		else
			*_out &= ~(1 << pin);
	}
};

#endif
