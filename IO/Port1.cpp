#include "Port1.h"

void Port1::SetDirection(unsigned char pin, Direction direction) {
	if (direction == Input)
		P1DIR &= ~(1 << pin);
	else
		P1DIR |= (1 << pin);
}


void Port1::DisableResistor(unsigned char pin) {
	P1REN &= ~(1 << pin);
}

void Port1::EnableResistor(unsigned char pin, ResistorMode resistorMode) {
	SetDirection(pin, Input);

	P1REN |= (1 << pin);

	Write(pin, resistorMode == PullUp);
}


bool Port1::Read(unsigned char pin) {
	return P1IN & (1 << pin);
}

void Port1::Write(unsigned char pin, bool state) {
	if (state)
		P1OUT |= (1 << pin);
	else
		P1OUT &= ~(1 << pin);
}
