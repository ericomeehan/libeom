#  Eric O Meehan C Library
## Networking

### Introduction

The hdelibc networking library contains a collection of tools for performing network tasks, including methods and data types for quickly performing network tasks and data structures for networking protocols.  

### Compiling

To compile a stand-alone static library for the Networking sub-module, use the makefile:

```
make Networking
```

This will generate a static library in the following folder:

```
hdelibc/Networking.a
```
### Including

You can include the Networking sub-module by specifying its path:

```
#include <hdelibc/Networking.h>
```
