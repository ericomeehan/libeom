// 
// Homo Deus
// 2/18/21
//
// Homo Deus C Library
// main.c
//
// Eric Meehan
//

#include "../Cryptography/ArbitrarilyPreciseInteger.h"

#include <stdio.h>

int main()
{
    struct ArbitrarilyPreciseInteger x = arbitrarily_precise_integer_constructor(0, 4, 0x446F6E27742067, 0x6F20757020746865, 0x72652E2E2E204974, 0x2773206461726B2E);
    
    printf("%s\n", x.hexadecimal);
}
