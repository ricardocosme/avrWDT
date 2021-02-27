#pragma once

#include "avr/wdt/detail/global.hpp"
#include "avr/wdt/detail/is_same.hpp"

namespace avr { namespace wdt { 

struct at_16K_t{};
struct at_32K_t{};
struct at_64K_t{};
struct at_128K_t{};
struct at_256K_t{};
struct at_512K_t{};
struct at_1024K_t{};
struct at_2048K_t{};

AVR_WDT_INLINE_GLOBAL(at_16K)
AVR_WDT_INLINE_GLOBAL(at_32K)
AVR_WDT_INLINE_GLOBAL(at_64K)
AVR_WDT_INLINE_GLOBAL(at_128K)
AVR_WDT_INLINE_GLOBAL(at_256K)
AVR_WDT_INLINE_GLOBAL(at_512K)
AVR_WDT_INLINE_GLOBAL(at_1024K)
AVR_WDT_INLINE_GLOBAL(at_2048K)

template<typename Timeout>
struct is_timeout {
    static constexpr bool value =
        detail::is_same<Timeout, at_16K_t>::value
        | detail::is_same<Timeout, at_32K_t>::value
        | detail::is_same<Timeout, at_64K_t>::value
        | detail::is_same<Timeout, at_128K_t>::value
        | detail::is_same<Timeout, at_256K_t>::value
        | detail::is_same<Timeout, at_512K_t>::value
        | detail::is_same<Timeout, at_1024K_t>::value
        | detail::is_same<Timeout, at_2048K_t>::value
        ;
};
             
}}
