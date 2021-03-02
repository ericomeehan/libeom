# Homo Deus
# hdelibc
#
# Makefile for hdelibc - provides options for creating a static library out of all or part of hdelibc
#
# 2021-02-12
# Eric Meehan


###############################################################################
# ALL
###############################################################################

# Create top level static library and all sub-libraries
all: Main DataStructures Networking Systems



###############################################################################
# MAIN
###############################################################################

# Creates just the top level static library
Main: DataStructuresSub NetworkingSub SystemsSub
		ar rcs hdelibc.a Node.o LinkedList.o Queue.o BinarySearchTree.o Entry.o Dictionary.o Server.o HTTPServer.o HTTPRequest.o ThreadPool.o



###############################################################################
# DATA STRUCTURES
###############################################################################

# Creates the data structures library
DataStructures: DataStructuresSub
	ar rcs DataStructures/DataStructures.a Node.o LinkedList.o Queue.o BinarySearchTree.o Entry.o Dictionary.o
	
# Sub components of the data structures library
DataStructuresSub: Node LinkedList Queue BinarySearchTree Entry Dictionary

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
	
	
	
###############################################################################
# NETWORKING
###############################################################################

# Creates the networking library
Networking: NetworkingSub
	ar rcs Networking/Networking.a Server.o HTTPRequest.o

# Sub components of the networking library
NetworkingSub: Server HTTPRequest

Server:
	gcc -c Networking/Nodes/Server.c

HTTPServer:
	gcc -c Networking/Nodes/HTTPServer.c

HTTPRequest:
	gcc -c Networking/Protocols/HTTPRequest.c
	
	

###############################################################################
# Systems
###############################################################################

# Creates the systems library
Systems: SystemsSub
	ar rcs System/System.a ThreadPool.o

# Sub components of the systems library
SystemsSub: ThreadPool

ThreadPool:
	gcc -c System/ThreadPool.c



###############################################################################
# CLEAN
###############################################################################

# Remove all .o files
clean:
	rm *.o
