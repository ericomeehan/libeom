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
// 4/17/21
//
//

#ifndef Terminal_h
#define Terminal_h

#include <stdio.h>

int terminal(int argc, const char **argv, int (*interpreter)(int argc, const char **argv), const char *pipeline);

#endif /* Terminal_h */
