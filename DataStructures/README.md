#  Eric O Meehan C Library
## Data Structures

### Introduction

The hdelibc library contains a collection of data structures intended for genderal purpose usage.  These structures are designed to be dynamic and allow the user to focus on their data rather than the structure.  This comes with a slight performance cost; however, these data structures should be suitable for most applications.

### Compiling

To compile a stand-alone static library for the Data Structures sub-module, use the makefile:

```
make DataStructures
```

This will generate a static library in the following folder:

```
hdelibc/DataStructures/DataStructures.a
```

### Including

You can include the Data Structures sub-module by specifying its path:

```
#include <hdelibc/DataStructures.h>
