#pragma once

namespace avr { namespace wdt { 

enum class timeout {
    at_16ms,
    at_32ms,
    at_64ms,
    at_125ms,
    at_250ms,
    at_500ms,
    at_1s,
    at_2s,
    at_4s,
    at_8s,
};
             
}}
