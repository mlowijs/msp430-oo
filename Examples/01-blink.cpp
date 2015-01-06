/*
 * Blink the Launchpad LED on P1.0
 */

#include "Core/Clock.hpp"
#include "IO/Pin.hpp"
#include "Timers/WatchdogTimer.hpp"

void main(void) {
    WatchdogTimer::Hold();

    Pin led(1, 0);
    led.Write(false);

    while (true) {
    	led.Toggle();
    	Clock::Sleep(1000);
    }
}
