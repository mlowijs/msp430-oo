#ifndef PORTA_H_
#define PORTA_H_

#include <msp430.h>

#include "Direction.h"
#include "ResistorMode.h"

class Port1 {
public:
	void SetDirection(unsigned char pin, Direction direction);

	void DisableResistor(unsigned char pin);
	void EnableResistor(unsigned char pin, ResistorMode resistorMode);

	bool Read(unsigned char pin);
	void Write(unsigned char pin, bool state);
};

#endif
