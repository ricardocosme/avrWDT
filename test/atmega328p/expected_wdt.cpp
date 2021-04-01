#include <avr/interrupt.hpp>
#include <avr/io.hpp>
#include <avr/io.h>

using namespace avr::io;

namespace reset {
void on_16ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde};
}
void on_32ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdp0};
}
void on_64ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdp1};
}
void on_125ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdp1,wdp0};
}
void on_250ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdp2};
}
void on_500ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdp2,wdp0};
}
void on_1s() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdp2,wdp1};
}
void on_2s() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdp2,wdp1,wdp0};
}
void on_4s() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdp3};
}
void on_8s() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdp3,wdp0};
}
}

namespace interrupt {
void on_16ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wdie};
}
void on_32ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wdie,wdp0};
}
void on_64ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wdie,wdp1};
}
void on_125ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wdie,wdp1,wdp0};
}
void on_250ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wdie,wdp2};
}
void on_500ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wdie,wdp2,wdp0};
}
void on_1s() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wdie,wdp2,wdp1};
}
void on_2s() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wdie,wdp2,wdp1,wdp0};
}
void on_4s() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wdie,wdp3};
}
void on_8s() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wdie,wdp3,wdp0};
}
}

namespace interrupt_reset {
void on_16ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdie};
}
void on_32ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdie,wdp0};
}
void on_64ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdie,wdp1};
}
void on_125ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdie,wdp1,wdp0};
}
void on_250ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdie,wdp2};
}
void on_500ms() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdie,wdp2,wdp0};
}
void on_1s() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdie,wdp2,wdp1};
}
void on_2s() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdie,wdp2,wdp1,wdp0};
}
void on_4s() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdie,wdp3};
}
void on_8s() {
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde,wdie,wdp3,wdp0};
}
}

void on_dont_assume_atomic() {
    avr::interrupt::atomic<> s;
    asm("wdr");
    wdtcsr = {wde,wdce};
    wdtcsr = {wde};
}

void off_assume_atomic() {
    asm("wdr");
    mcusr.clear(wdrf);
    set(wdce,wde);
    wdtcsr = 0x00;
}

void off_dont_assume_atomic() {
    avr::interrupt::atomic<> s;
    asm("wdr");
    mcusr.clear(wdrf);
    set(wdce,wde);
    wdtcsr = 0x00;
}

void wdt_reset()
{ asm("wdr"); }
