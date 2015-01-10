#ifndef CORE_FLASH_HPP_
#define CORE_FLASH_HPP_

#include <msp430.h>

class Flash {
private:
	static unsigned char *_flashStart;

	Flash();

public:
	static void EraseSegment(unsigned char segment) {
		while (FCTL3 & BUSY);

		FCTL2 = FWKEY | FSSEL_2 | 0x02;
		FCTL3 = FWKEY;
		FCTL1 = FWKEY | ERASE;
		*(_flashStart + (segment * 64)) = 0;
		FCTL3 = FWKEY | LOCK;

		while (FCTL3 & BUSY);
	}


	static unsigned char Read(unsigned char position) {
		return *(_flashStart + position);
	}

	static void Write(unsigned char position, unsigned char value) {
		while (FCTL3 & BUSY);

		FCTL2 = FWKEY | FSSEL_2 | 0x02;
		FCTL3 = FWKEY;
		FCTL1 = FWKEY | WRT;
		*(_flashStart + position) = value;
		FCTL1 = FWKEY;
		FCTL3 = FWKEY | LOCK;

		while (FCTL3 & BUSY);
	}
};

#endif
