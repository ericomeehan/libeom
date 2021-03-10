//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// UnboundedInteger.c
//
// Eric Meehan
// 3/4/21
//
//


#include "ArbitrarilyPreciseInteger.h"

#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#define max(x,y) (((x) >= (y)) ? (x) : (y))
#define min(x,y) (((x) < (y)) ? (x) : (y))


const uint64_t MAX_BASE_2xx64_INT = 0xFFFFFFFFFFFFFFFF;
const uint64_t MID_BASE_2xx64_INT = 0x8000000000000000;

int overflow_detection(uint64_t x, uint64_t y)
{
    return (max(x, y) >= MID_BASE_2xx64_INT && min(x, y) >= MID_BASE_2xx64_INT) || !(max(x, y) < MID_BASE_2xx64_INT && min(x, y) < MID_BASE_2xx64_INT) || (min(x, y) > MAX_BASE_2xx64_INT - max(x, y));
}

struct ArbitrarilyPreciseInteger arbitrarily_precise_integer_constructor(short sign, int size, ...)
{
    struct ArbitrarilyPreciseInteger number;
    number.value = malloc(sizeof(uint64_t[size]));
    va_list blocks;
    va_start(blocks, size);
    for (int i = 0; i < size; i++)
    {
        number.value[i] = va_arg(blocks, uint64_t);
    }
    number.sign = sign;
    number.size = size;
    number.hexadecimal = malloc(size * 8);
    for (int i = 0; i < size; i++)
    {
        char x[17];
        sprintf(x, "%llX", number.value[i]);
        strcat(number.hexadecimal, x);
    }
    return number;
}

void arbitrarily_precise_integer_destructor(struct ArbitrarilyPreciseInteger *number)
{
    free(number->value);
    free(number->hexadecimal);
}
