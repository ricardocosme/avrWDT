#pragma once

#include "avr/wdt/timeout/common.hpp"

#if __cplusplus >= 201703L
#define AVR_WDT_REQUIRES_TIMEOUT requires(is_timeout<Timeout>::value)
#else
#define AVR_WDT_REQUIRES_TIMEOUT
#endif
