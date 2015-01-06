/*
 * Send 2 bytes over SPI and read back the returned data
 */

#include "Core/Clock.hpp"
#include "IO/UsciA.hpp"
#include "Timers/WatchdogTimer.hpp"

void main(void) {
    WatchdogTimer::Hold();

    UsciA spi;
    spi.SetupSpi(Mode0, false, 2);

    unsigned char writeBuffer[] = { 0x12, 0x34 };
    unsigned char readBuffer[2];

    spi.SpiTransfer(writeBuffer, readBuffer, 2);

    // Do something with the read bytes

    while (true) ;
}
