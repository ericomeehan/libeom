# libeom
#
# Makefile for libeom - provides options for creating a static library out of all or part of libeom
#
# 2021-02-12
# Eric Meehan


###############################################################################
# COMPILER
###############################################################################

CC=gcc
CFLAGS=-Wall -pedantic
AR=ar
ARFLAGS=rcs
RM=rm -f


###############################################################################
# MARK: ALL
###############################################################################

# Create top level static library and all sub-libraries
all: Main DataStructures Networking Systems


###############################################################################
# MARK: MAIN
###############################################################################

# Creates just the top level static library
Main: DataStructuresSub NetworkingSub SystemsSub
	$(AR) $(ARFLAGS) libeom.a Node.o LinkedList.o Queue.o BinarySearchTree.o Entry.o Dictionary.o Client.o Server.o HTTPServer.o HTTPRequest.o ThreadPool.o PeerToPeer.o Files.o


###############################################################################
# MARK: DATA STRUCTURES
###############################################################################

# Creates the data structures library
DataStructures: DataStructuresSub
	$(AR) $(ARFLAGS) DataStructures/DataStructures.a Node.o LinkedList.o Queue.o BinarySearchTree.o Entry.o Dictionary.o

# Sub components of the data structures library
DataStructuresSub: Node LinkedList Queue BinarySearchTree Entry Dictionary

Node:
	$(CC) $(CFLAGS) -c DataStructures/Common/Node.c

LinkedList:
	$(CC) $(CFLAGS) -c DataStructures/Lists/LinkedList.c

Queue:
	$(CC) $(CFLAGS) -c DataStructures/Lists/Queue.c
	
BinarySearchTree:
	$(CC) $(CFLAGS) -c DataStructures/Trees/BinarySearchTree.c

Entry:
	$(CC) $(CFLAGS) -c DataStructures/Dictionary/Entry.c

Dictionary:
	$(CC) $(CFLAGS) -c DataStructures/Dictionary/Dictionary.c

	
###############################################################################
# MARK: NETWORKING
###############################################################################

# Creates the networking library
Networking: NetworkingSub
	$(AR) $(ARFLAGS) Networking/Networking.a Server.o HTTPRequest.o HTTPServer.o Node.o LinkedList.o Queue.o BinarySearchTree.o Entry.o Client.o Dictionary.o ThreadPool.o PeerToPeer.o

# Sub components of the networking library
NetworkingSub: DataStructuresSub SystemsSub Server Client HTTPRequest HTTPServer PeerToPeer

Server:
	$(CC) $(CFLAGS) -c Networking/Nodes/Server.c

Client:
	$(CC) $(CFLAGS) -c Networking/Nodes/Client.c

PeerToPeer:
	$(CC) $(CFLAGS) -c Networking/Nodes/PeerToPeer.c

HTTPServer:
	$(CC) $(CFLAGS) -c Networking/Nodes/HTTPServer.c

HTTPRequest:
	$(CC) $(CFLAGS) -c Networking/Protocols/HTTPRequest.c


###############################################################################
# MARK: Systems
###############################################################################

# Creates the systems library
Systems: SystemsSub
	$(AR) $(ARFLAGS) Systems/System.a ThreadPool.o Files.o

# Sub components of the systems library
SystemsSub: ThreadPool Files

ThreadPool:
	$(CC) $(CFLAGS) -c Systems/ThreadPool.c

Files:
	$(CC) $(CFLAGS) -c Systems/Files.c


###############################################################################
# MARK: TEST
###############################################################################

test: test_p2p test_linked_list test_queue

test_p2p: test/main.c
	$(CC) $(CFLAGS) -o test_p2p test/main.c libeom.a

test_linked_list: test/test_linked_list.c
	$(CC) $(CFLAGS) -o test_linked_list test/test_linked_list.c libeom.a

test_queue: test/test_queue.c
	$(CC) $(CFLAGS) -o test_queue test/test_queue.c libeom.a


###############################################################################
# MARK: CLEAN
###############################################################################

# Remove all .o files and test files
clean:
	$(RM) *.o
	$(RM) test_p2p
	$(RM) test_linked_list
	$(RM) test_queue

