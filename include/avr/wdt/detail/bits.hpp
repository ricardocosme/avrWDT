#pragma once

#include "avr/wdt/detail/global.hpp"

#include <avr/io.hpp>

namespace avr { namespace wdt { namespace detail {

#if __AVR_AT94K__
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdtcr_t, _wdtcr)
AVR_WDT_INLINE_GLOBAL_T(avr::io::mcur_t, _mcusr)
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdtoe_t, _wdce)
#elif defined(__AVR_AT43USB320__)               \
    || defined(__AVR_AT43USB355__)              \
    || defined(__AVR_AT76C711__)                        \
    || defined(__AVR_AT86RF401__)                        
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdtcr_t, _wdtcr)
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdtoe_t, _wdce)
#elif __AVR_ATtiny25__ || __AVR_ATtiny45__ || __AVR_ATtiny85__
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdie_t, _wdie)
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdtcr_t, _wdtcr)
AVR_WDT_INLINE_GLOBAL_T(avr::io::mcusr_t, _mcusr)
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdce_t, _wdce)
#elif defined(__AVR_ATmega328P__)                       \
    || defined(__AVR_ATmega328__)                        \
    || defined(__AVR_AT90PWM1__)                        \
    || defined(__AVR_AT90PWM2__)                        \
    || defined(__AVR_AT90PWM2B__)                       \
    || defined(__AVR_AT90PWM3__)                        \
    || defined(__AVR_AT90PWM3B__)                       \
    || defined(__AVR_AT90PWM81__)                       \
    || defined(__AVR_AT90PWM161__)                      \
    || defined(__AVR_ATmega16M1__)                      \
    || defined(__AVR_ATmega32M1__)                      \
    || defined(__AVR_ATmega64M1__)                      \
    || defined(__AVR_ATmega16U4__)                      \
    || defined(__AVR_ATmega32U4__)                      \
    || defined(__AVR_ATmega32C1__)                      \
    || defined(__AVR_ATmega64C1__)                      \
    || defined(__AVR_ATmega32U6__)                      \
    || defined(__AVR_ATmegaUSB646__)                    \
    || defined(__AVR_ATmegaUSB647__)                    \
    || defined(__AVR_ATmegaUSB1286__)                   \
    || defined(__AVR_ATmegaUSB1287__)                   \
    || defined(__AVR_ATmega1280__)                   
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdie_t, _wdie)
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdtcsr_t, _wdtcr)
AVR_WDT_INLINE_GLOBAL_T(avr::io::mcusr_t, _mcusr)
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdce_t, _wdce)
#elif defined (__AVR_ATmega128__) || defined(__AVR_ATmega128A__)
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdtcr_t, _wdtcr)
AVR_WDT_INLINE_GLOBAL_T(avr::io::mcucsr_t, _mcusr)
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdce_t, _wdce)
#elif __AVR_ATtiny13A__
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdtie_t, _wdie)
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdtcr_t, _wdtcr)
AVR_WDT_INLINE_GLOBAL_T(avr::io::mcusr_t, _mcusr)
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdce_t, _wdce)
#else
#error "AVR device doesn't supported"
#endif

}}}
