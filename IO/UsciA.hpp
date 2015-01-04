#ifndef IO_USCIA_H_
#define IO_USCIA_H_

#include <msp430.h>

#include "ISpi.h"

#ifdef __MSP430_HAS_USCI__
class UsciA : public ISpi {
public:
	/* SPI */
	void SetupSpi(SpiMode mode, bool msbFirst, unsigned char clockDivider = 2) {
		UCA0CTL1 = UCSWRST; // Hold in reset mode

		// Enable pin USCI functions
		P1SEL |= 0x16;
		P1SEL2 |= 0x16;

		UCA0CTL0 = (mode << 6) | (msbFirst << 5) | UCMST | UCSYNC;
		UCA0CTL1 |= UCSSEL_2; // Use SMCLK
		UCA0BR0 = clockDivider; // SMCLK / clockDivider
		UCA0BR1 = 0;
		UCA0MCTL = 0;

		UCA0CTL1 &= ~UCSWRST; // Release from reset mode
	}


	void SpiWrite(unsigned char writeBuffer[], unsigned char *readBuffer, unsigned char length) {
		for (unsigned char i = 0; i < length; i++) {
			UCA0TXBUF = writeBuffer[i];

			while (UCA0STAT & UCBUSY) ;

			readBuffer[i] = UCA0RXBUF;
		}
	}

	unsigned char SpiWriteByte(unsigned char data) {
		UCA0TXBUF = data;

		while (UCA0STAT & UCBUSY) ;

		return UCA0RXBUF;
	}
};
#endif

#endif
