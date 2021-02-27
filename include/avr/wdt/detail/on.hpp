#pragma once

#if __AVR_AT94K__
#include "avr/wdt/detail/on/at94k.hpp"
#elif defined(__AVR_AT43USB320__) \
    || defined(__AVR_AT43USB355__)
#include "avr/wdt/detail/on/at43usb320.hpp"
#elif defined(__AVR_AT76C711__)
#include "avr/wdt/detail/on/at76c711.hpp"
#elif defined(__AVR_AT86RF401__)
#include "avr/wdt/detail/on/at86rf401.hpp"
#elif defined (__AVR_AT90PWM81__) || defined(__AVR_AT90PWM161__)
#include "avr/wdt/detail/on/at90pwm81.hpp"
#elif defined (__AVR_ATmega128__) || defined(__AVR_ATmega128A__)
#include "avr/wdt/detail/on/atmega128.hpp"
#else
#include "avr/wdt/detail/on/common.hpp"
#endif
