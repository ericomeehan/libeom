#  Homo Deus
## C Library

## Introduction

The Homo Deus C Library (hdelibc) is an open source collection of tools for the C programming language.  
The project is in continuous development, with features being added and revised continually over time.  

The easiest way to import the library is simply to download the project folder and copy it into your project, and then reference the desired header files.  
Static library files are included to support easy compiling - in gcc, for example:

```
gcc my_project.c libhdelibc.a
```

If only a section of the library is desired, that section alone may be included, and static libraries are provided for each sub-module.  
Again, include this in your compile command:

```
gcc my_project.c libhdelibc-datastructures.a
```

Since there are numerous sub-modules, this file will simply serve as a table of contents for what is included in the library. 
For more specific documentation, please consult the README included in each submodule.

## Contents

### Data Structures

#### Lists

* Node
* LinkedList
* Queue

