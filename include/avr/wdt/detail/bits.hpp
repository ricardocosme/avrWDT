#pragma once

#include "avr/wdt/detail/global.hpp"

#include <avr/io.hpp>

namespace avr { namespace wdt { namespace detail {

#if __AVR_ATtiny25__ || __AVR_ATtiny45__ || __AVR_ATtiny85__
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdie_t, _wdie)
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdtcr_t, _wdtcr)
AVR_WDT_INLINE_GLOBAL_T(avr::io::mcusr_t, _mcusr)
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdce_t, _wdce)
#elif defined(__AVR_ATmega328P__)                       \
    || defined(__AVR_ATmega328__)                        
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdie_t, _wdie)
AVR_WDT_INLINE_GLOBAL_T(avr::io::wdtcsr_t, _wdtcr)
AVR_WDT_INLINE_GLOBAL_T(avr::io::mcusr_t, _mcusr)
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
