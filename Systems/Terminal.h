//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// Terminal.h
//
// Eric Meehan
// 4/10/21
//
//

/*
 The Terminal object is a command line interface for stand-alone applications.
 */

#ifndef Terminal_h
#define Terminal_h

#include <stdio.h>

void terminal(int argc, const char *argv[], void (*interpreter)(const char *arg));

#endif /* Terminal_h */
