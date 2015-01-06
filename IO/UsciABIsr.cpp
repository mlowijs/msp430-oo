#include <msp430.h>

#include "UsciA.hpp"

#ifdef USCIAB0RX_VECTOR

#pragma vector=USCIAB0RX_VECTOR
__interrupt void UsciAB0RXIsr() {

#ifdef UCA0RXIFG
	if (IFG2 & UCA0RXIFG) {
		UsciA *inst = UsciA::__0;

		if (inst->_rxIndex < UART_RX_BUFFER_SIZE)
			inst->_rxBuffer[inst->_rxIndex++] = UCA0RXBUF;
	}
#endif

#ifdef UCB0RXIFG
	if (IFG2 & UCB0RXIFG) {

	}
#endif

}

#endif
