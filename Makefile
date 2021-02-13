# Homo Deus
# hdelibc
#
# Makefile for hdelibc - provides options for creating a static library out of all or part of hdelibc
#
# 2021-02-12
# Eric Meehan


# ALL
# Create top level static library and all sub-libraries
all: Main DataStructures

# MAIN
# Creates just the top level static library
Main: DSSub
		ar rcs hdelibc.a Node.o LinkedList.o Queue.o BinarySearchTree.o Entry.o Dictionary.o ; make clean


# DATA STRUCTURES
# Creates the data structures library
DataStructures: DSSub
	ar rcs DataStructures/hdelibc-datastructures.a Node.o LinkedList.o Queue.o BinarySearchTree.o Entry.o Dictionary.o ; make clean
	
DSSub: Node LinkedList Queue BinarySearchTree Entry Dictionary

Node:
	gcc -c DataStructures/Common/Node.c

LinkedList:
	gcc -c DataStructures/Lists/LinkedList.c

Queue:
	gcc -c DataStructures/Lists/Queue.c
	
BinarySearchTree:
	gcc -c DataStructures/Trees/BinarySearchTree.c

Entry:
	gcc -c DataStructures/Dictionary/Entry.c

Dictionary:
	gcc -c DataStructures/Dictionary/Dictionary.c


# CLEAN
# Remove all .o files
clean:
	rm *.o
