#pragma once

#include "avr/wdt/detail/global.hpp"
#include "avr/wdt/detail/is_same.hpp"

namespace avr { namespace wdt { 

struct at_2K_t{};
struct at_4K_t{};
struct at_8K_t{};
struct at_16K_t{};
struct at_32K_t{};
struct at_64K_t{};
struct at_128K_t{};
struct at_256K_t{};

AVR_WDT_INLINE_GLOBAL(at_2K)
AVR_WDT_INLINE_GLOBAL(at_4K)
AVR_WDT_INLINE_GLOBAL(at_8K)
AVR_WDT_INLINE_GLOBAL(at_16K)
AVR_WDT_INLINE_GLOBAL(at_32K)
AVR_WDT_INLINE_GLOBAL(at_64K)
AVR_WDT_INLINE_GLOBAL(at_128K)
AVR_WDT_INLINE_GLOBAL(at_256K)

template<typename Timeout>
struct is_timeout {
    static constexpr bool value =
        detail::is_same<Timeout, at_2K_t>::value
        | detail::is_same<Timeout, at_4K_t>::value
        | detail::is_same<Timeout, at_8K_t>::value
        | detail::is_same<Timeout, at_16K_t>::value
        | detail::is_same<Timeout, at_32K_t>::value
        | detail::is_same<Timeout, at_64K_t>::value
        | detail::is_same<Timeout, at_128K_t>::value
        | detail::is_same<Timeout, at_256K_t>::value
        ;
};
             
}}
