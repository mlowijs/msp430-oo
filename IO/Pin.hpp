#ifndef IO_PORT_H_
#define IO_PORT_H_

#include <msp430.h>

#include "InterruptEdge.h"
#include "ResistorMode.h"

class Pin {
private:
	volatile unsigned char *_dir, *_ie, *_ies, *_ifg, *_in, *_out, *_ren, *_sel, *_sel2;
	unsigned char _pin;

public:
	Pin(unsigned char port, unsigned char pin) {
		_pin = pin;

#ifdef __MSP430_HAS_PORT1_R__
		if (port == 1) {
			_dir = &P1DIR;
			_ie = &P1IE;
			_ies = &P1IES;
			_ifg = &P1IFG;
			_in = &P1IN;
			_out = &P1OUT;
			_ren = &P1REN;
			_sel = &P1SEL;
			_sel2 = &P1SEL2;
		}
#endif

#ifdef __MSP430_HAS_PORT2_R__
		if (port == 2) {
			_dir = &P2DIR;
			_ie = &P2IE;
			_ies = &P2IES;
			_ifg = &P2IFG;
			_in = &P2IN;
			_out = &P2OUT;
			_ren = &P2REN;
			_sel = &P2SEL;
			_sel2 = &P2SEL2;
		}
#endif

#ifdef __MSP430_HAS_PORT3_R__
		if (port == 3) {
			_dir = &P3DIR;
			_in = &P3IN;
			_out = &P3OUT;
			_ren = &P3REN;
			_sel = &P3SEL;
			_sel2 = &P3SEL2;
		}
#endif

		AsOutput();
	}


	void AsInput(ResistorMode resistorMode, InterruptEdge interruptEdge) {
		*_sel &= ~(1 << _pin);
		*_sel2 &= ~(1 << _pin);

		if (resistorMode == ResistorOff)
			*_ren &= ~(1 << _pin);
		else
			Write(resistorMode == PullUp);

		if (interruptEdge == InterruptOff) {
			*_ie &= ~(1 << _pin);
		} else {
			if (interruptEdge == LowToHigh)
				*_ies &= ~(1 << _pin);
			else
				*_ies |= 1 << _pin;

			*_ifg &= ~(1 << _pin);
			*_ie |= 1 << _pin;
		}

		*_dir &= ~(1 << _pin);
	}

	void AsOutput() {
		*_sel &= ~(1 << _pin);
		*_sel2 &= ~(1 << _pin);

		*_dir |= (1 << _pin);
	}


	bool Read() {
		return *_in & (1 << _pin);
	}

	void Write(bool state) {
		if (state)
			*_out |= (1 << _pin);
		else
			*_out &= ~(1 << _pin);
	}
};

#endif
