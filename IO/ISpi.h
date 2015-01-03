#ifndef IO_SPI_H_
#define IO_SPI_H_

#include "SpiMode.h"

class ISpi {
public:
	virtual void SetupSpi(SpiMode mode, bool msbFirst) = 0;

	virtual unsigned char *SpiWrite(unsigned char data[], unsigned char length) = 0;
	virtual unsigned char SpiWriteByte(unsigned char data) = 0;
};

#endif
