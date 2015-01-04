#ifndef IO_SPI_H_
#define IO_SPI_H_

#include "SpiMode.h"

class ISpi {
public:
	virtual void SetupSpi(SpiMode mode, bool msbFirst, unsigned char clockDivider = 2) = 0;

	virtual void SpiWrite(unsigned char writeBuffer[], unsigned char *readBuffer, unsigned char length) = 0;
	virtual unsigned char SpiWriteByte(unsigned char data) = 0;
};

#endif
