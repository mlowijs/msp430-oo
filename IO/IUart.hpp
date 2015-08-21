#ifndef IO_IUART_HPP_
#define IO_IUART_HPP_

#define UART_RX_BUFFER_SIZE 16

#include "Parity.h"
#include "StopBits.h"

class IUart {
public:
	unsigned char _rxBuffer[UART_RX_BUFFER_SIZE];
	volatile unsigned char _rxIndex;

	IUart() {
		_rxIndex = 0;
	}

	virtual void SetupUart(Parity parity, StopBits stopBits) = 0;

	virtual void UartWrite(unsigned char writeBuffer[], unsigned char length) = 0;
	virtual void UartWriteByte(unsigned char data) = 0;

	virtual unsigned char UartRead(unsigned char *readBuffer) = 0;
};

#endif
