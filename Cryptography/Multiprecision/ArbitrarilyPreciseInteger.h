//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// UnboundedInteger.h
//
// Eric Meehan
// 3/4/21
//
//


#ifndef UnboundedInteger_h
#define UnboundedInteger_h

#include <stdlib.h>

struct ArbitrarilyPreciseInteger
{
    uint64_t *value;
    short sign;
    int size;
    char *hexadecimal;
};

struct ArbitrarilyPreciseInteger arbitrarily_precise_integer_constructor(short sign, int size, ...);
void arbitrarily_precise_integer_destructor(struct ArbitrarilyPreciseInteger *bignum);

#endif /* UnboundedInteger_h */
