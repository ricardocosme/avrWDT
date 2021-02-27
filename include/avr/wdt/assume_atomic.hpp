#pragma once

#include "avr/wdt/detail/global.hpp"

namespace avr { namespace wdt { 

struct assume_atomic_t{};
struct dont_assume_atomic_t{};

AVR_WDT_INLINE_GLOBAL(assume_atomic);
AVR_WDT_INLINE_GLOBAL(dont_assume_atomic);

}}
