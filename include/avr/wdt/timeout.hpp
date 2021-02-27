#pragma once

#if __AVR_AT94K__
#include "avr/wdt/timeout/at94k.hpp"
#elif defined(__AVR_AT43USB320__) || defined(__AVR_AT43USB355__)
#include "avr/wdt/timeout/at43usb320.hpp"
#elif defined (__AVR_AT76C711__)
#include <avr/wdt/timeout/at76c711.hpp>
#elif defined (__AVR_AT86RF401__)
#include <avr/wdt/timeout/at86rf401.hpp>
#elif defined (__AVR_AT90PWM81__) || defined(__AVR_AT90PWM161__)
#include <avr/wdt/timeout/at90pwm81.hpp>
#elif defined (__AVR_ATmega128__) || defined(__AVR_ATmega128A__)
#include <avr/wdt/timeout/atmega128.hpp>
#else
#include "avr/wdt/timeout/common.hpp"
#endif

//TODO: ATmega{8,16,32}U
