# libeom
#
# Makefile for libeom - provides options for creating a static library out of all or part of libeom
#
# 2021-02-12
# Eric Meehan


###############################################################################
# MARK: ALL
###############################################################################

# Create top level static library and all sub-libraries
all: Main DataStructures Networking Systems

###############################################################################
# MARK debug_all
###############################################################################
debug: DEBUG = -g

debug: all

###############################################################################
# MARK: MAIN
###############################################################################

# Creates just the top level static library
Main: DataStructuresSub NetworkingSub SystemsSub
		ar rcs libeom.a Node.o LinkedList.o Queue.o BinarySearchTree.o Entry.o Dictionary.o Client.o Server.o HTTPServer.o HTTPRequest.o ThreadPool.o PeerToPeer.o Files.o



###############################################################################
# MARK: DATA STRUCTURES
###############################################################################

# Creates the data structures library
DataStructures: DataStructuresSub
	ar rcs DataStructures/DataStructures.a Node.o LinkedList.o Queue.o BinarySearchTree.o Entry.o Dictionary.o
	
# Sub components of the data structures library
DataStructuresSub: Node LinkedList Queue BinarySearchTree Entry Dictionary

Node:
	gcc $(DEBUG) -c DataStructures/Common/Node.c

LinkedList:
	gcc $(DEBUG) -c DataStructures/Lists/LinkedList.c

Queue:
	gcc $(DEBUG) -c DataStructures/Lists/Queue.c
	
BinarySearchTree:
	gcc $(DEBUG) -c DataStructures/Trees/BinarySearchTree.c

Entry:
	gcc $(DEBUG) -c DataStructures/Dictionary/Entry.c

Dictionary:
	gcc $(DEBUG) -c DataStructures/Dictionary/Dictionary.c
	
	
	
###############################################################################
# MARK: NETWORKING
###############################################################################

# Creates the networking library
Networking: NetworkingSub
	ar rcs Networking/Networking.a Server.o HTTPRequest.o HTTPServer.o Node.o LinkedList.o Queue.o BinarySearchTree.o Entry.o Client.o Dictionary.o ThreadPool.o PeerToPeer.o

# Sub components of the networking library
NetworkingSub: DataStructuresSub SystemsSub Server Client HTTPRequest HTTPServer PeerToPeer

Server:
	gcc $(DEBUG) -c Networking/Nodes/Server.c
	
Client:
	gcc $(DEBUG) -c Networking/Nodes/Client.c

PeerToPeer:
	gcc $(DEBUG) -c Networking/Nodes/PeerToPeer.c

HTTPServer:
	gcc $(DEBUG) -c Networking/Nodes/HTTPServer.c

HTTPRequest:
	gcc $(DEBUG) -c Networking/Protocols/HTTPRequest.c
	
	

###############################################################################
# MARK: Systems
###############################################################################

# Creates the systems library
Systems: SystemsSub
	ar rcs Systems/System.a ThreadPool.o Files.o

# Sub components of the systems library
SystemsSub: ThreadPool Files

ThreadPool:
	gcc $(DEBUG) -c Systems/ThreadPool.c

Files:
	gcc $(DEBUG) -c Systems/Files.c


###############################################################################
# MARK: CLEAN
###############################################################################

# Remove all .o files
clean:
	rm *.o
