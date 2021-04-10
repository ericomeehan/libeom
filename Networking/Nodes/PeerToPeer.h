//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// PeerToPeer.h
//
// Eric Meehan
// 3/13/21
//
//

/*
 The PeerToPeer object is intended as a wrapper for a node with client and server capacities.
 The object requires the client and server functionalities be defined by the user.
 */

#ifndef PeerToPeer_h
#define PeerToPeer_h

#include "Server.h"
#include "../../DataStructures/Lists/LinkedList.h"

struct PeerToPeer
{
    struct Server server;
    struct LinkedList known_hosts;
    
    int domain;
    int service;
    int protocol;
    int port;
    u_long interface;
    
    // The user_portal function is activated to launch the server and client applications.
    void (*user_portal)(struct PeerToPeer *peer_to_peer);
    void * (*server_function)(void *arg);
    void * (*client_function)(void *arg);
};

struct PeerToPeer peer_to_peer_constructor(int domain, int service, int protocol, int port, u_long interface, void * (*server_function)(void *arg), void * (*client_function)(void *arg));

#endif /* PeerToPeer_h */
