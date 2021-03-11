#  Eric O Meehan C Library

## Introduction

Eric O Meehan's C Library is an open source collection of tools for the C programming language.  
The project is in continuous development, with features being added and revised continually over time.  

## Compiling

If you save the libeom directory to your default include location, there is no need to compile anything; however, a makefile is provided to allow the compiling of libeom into a static library containing all sub-modules, individual sub-modules, or both.  The simplest configuration is to compile both with the command:

```
make
```

This will generate a static library for libeom as a whole, as well as static libraries for each of the sub-modules individually.  If you only wish to compile the top-level static library, use:

```
make Main
```

If you wish to compile a static library for only a portion of libeom, you will need to use the command specified for that section.  You can find the command in that sub-module's README, or in the table of contents below.

After using one of the aforementioned make commands, it is recommended to run:

```
make clean
```

To remove the residual object files.

## Including

The easiest way to import the library is simply to download the project folder and copy it into your project, and then reference the desired header files.  You will need to use brackets or quotes according to how you intend to use the library, but documentation is written as if libeom is saved in your default include path.

```
// If in default include path:
#include <libeom.h>
// If in the same directory as your project:
#include "libeom/libeom.h"
```

If you are using libeom as a static library, remember to include the desired .a file in your command:

```
gcc my_project.c libeom/libeom.a
```

If only a section of the library is desired, that section alone may be included, and static libraries are provided for each sub-module.  
Again, use the include statement and parameterize the static library (if applicable):

```
#include <libeom/DataStructures/DataStructures.h>
```

```
gcc my_project.c libeom/DataStructures/DataStructures.a
```

Since there are numerous sub-modules, this file will simply serve as a table of contents for what is included in the library. 

## Contents

For specific documentation on components, check the README included in the sub-module directories.  


### Data Structures

**Location:**

```
libeom/DataStructures
```

**Include:**

```
#include <libeom/DataStructures.h>
```

#### Components

**Common**

* Node

**Dictionary**

* Entry
* Dictionary

**Lists**

* LinkedList
* Queue

**Trees**

* BinarySearchTree

### Networking

**Location**

```
libeom/Networking
```

**Include**

```
#include <libeom/Networking.h>
```

#### Components

**Nodes**

* Server
* HTTPServer

**Protocols**

* HTTPRequest

### Systems

**Location**

```
libeom/Systems
```

**Include**

```
#include <libeom/Systems.h>
```


