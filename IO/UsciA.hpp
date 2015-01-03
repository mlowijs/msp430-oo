#ifndef IO_USCIA_H_
#define IO_USCIA_H_

#include <msp430.h>

#include "ISpi.h"

#ifdef __MSP430_HAS_USCI__
class UsciA : public ISpi {
public:
	/* SPI */
	void SetupSpi(SpiMode mode, bool msbFirst) {
		UCA0CTL1 = UCSWRST; // Hold in reset mode

		UCA0CTL0 = (mode << 6) | (msbFirst << 5) | UCMST | UCSYNC;
		UCA0CTL1 |= UCSSEL_1; // Use SMCLK

		// Enable pin USCI functions
		P1SEL = 0x16;
		P1SEL2 = 0x16;

		UCA0CTL1 &= ~UCSWRST; // Release from reset mode
	}


	unsigned char *SpiWrite(unsigned char data[], unsigned char length) {
		unsigned char *readBuffer = new unsigned char[length];

		for (unsigned char i = 0; i < length; i++) {
			UCA0TXBUF = data[i];

			while (UCA0STAT & UCBUSY) ;

			readBuffer[i] = UCA0RXBUF;
		}

		return readBuffer;
	}

	unsigned char SpiWriteByte(unsigned char data) {
		UCA0TXBUF = data;

		while (UCA0STAT & UCBUSY) ;

		return UCA0RXBUF;
	}
};
#endif

#endif
