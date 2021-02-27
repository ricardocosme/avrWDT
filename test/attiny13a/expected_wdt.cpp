#include <avr/interrupt.hpp>
#include <avr/io.hpp>
using namespace avr::io;

namespace reset {
void on_16ms() {
    asm("wdr");
    wdtcr = {wde};
}
void on_32ms() {
    asm("wdr");
    wdtcr = {wde,wdp0};
}
void on_64ms() {
    asm("wdr");
    wdtcr = {wde,wdp1};
}
void on_125ms() {
    asm("wdr");
    wdtcr = {wde,wdp1,wdp0};
}
void on_250ms() {
    asm("wdr");
    wdtcr = {wde,wdp2};
}
void on_500ms() {
    asm("wdr");
    wdtcr = {wde,wdp2,wdp0};
}
void on_1s() {
    asm("wdr");
    wdtcr = {wde,wdp2,wdp1};
}
void on_2s() {
    asm("wdr");
    wdtcr = {wde,wdp2,wdp1,wdp0};
}
void on_4s() {
    asm("wdr");
    wdtcr = {wde,wdp3};
}
void on_8s() {
    asm("wdr");
    wdtcr = {wde,wdp3,wdp0};
}
}

namespace interrupt {
void on_16ms() {
    asm("wdr");
    wdtcr = {wdtie};
}
void on_32ms() {
    asm("wdr");
    wdtcr = {wdtie,wdp0};
}
void on_64ms() {
    asm("wdr");
    wdtcr = {wdtie,wdp1};
}
void on_125ms() {
    asm("wdr");
    wdtcr = {wdtie,wdp1,wdp0};
}
void on_250ms() {
    asm("wdr");
    wdtcr = {wdtie,wdp2};
}
void on_500ms() {
    asm("wdr");
    wdtcr = {wdtie,wdp2,wdp0};
}
void on_1s() {
    asm("wdr");
    wdtcr = {wdtie,wdp2,wdp1};
}
void on_2s() {
    asm("wdr");
    wdtcr = {wdtie,wdp2,wdp1,wdp0};
}
void on_4s() {
    asm("wdr");
    wdtcr = {wdtie,wdp3};
}
void on_8s() {
    asm("wdr");
    wdtcr = {wdtie,wdp3,wdp0};
}
}

namespace interrupt_reset {
void on_16ms() {
    asm("wdr");
    wdtcr = {wde,wdtie};
}
void on_32ms() {
    asm("wdr");
    wdtcr = {wde,wdtie,wdp0};
}
void on_64ms() {
    asm("wdr");
    wdtcr = {wde,wdtie,wdp1};
}
void on_125ms() {
    asm("wdr");
    wdtcr = {wde,wdtie,wdp1,wdp0};
}
void on_250ms() {
    asm("wdr");
    wdtcr = {wde,wdtie,wdp2};
}
void on_500ms() {
    asm("wdr");
    wdtcr = {wde,wdtie,wdp2,wdp0};
}
void on_1s() {
    asm("wdr");
    wdtcr = {wde,wdtie,wdp2,wdp1};
}
void on_2s() {
    asm("wdr");
    wdtcr = {wde,wdtie,wdp2,wdp1,wdp0};
}
void on_4s() {
    asm("wdr");
    wdtcr = {wde,wdtie,wdp3};
}
void on_8s() {
    asm("wdr");
    wdtcr = {wde,wdtie,wdp3,wdp0};
}
}

void on_dont_assume_atomic() {
    auto s = avr::interrupt::make_atomic();
    asm("wdr");
    wdtcr = {wde};
}

void off_assume_atomic() {
    asm("wdr");
    mcusr.clear(wdrf);
    set(wdce,wde);
    wdtcr = 0x00;
}

void off_dont_assume_atomic() {
    auto s = avr::interrupt::make_atomic();
    asm("wdr");
    mcusr.clear(wdrf);
    set(wdce,wde);
    wdtcr = 0x00;
}

void wdt_reset()
{ asm("wdr"); }
