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
    
    void (*user_portal)(struct PeerToPeer *peer_to_peer);
    void * (*server_function)(void *arg);
    void * (*client_function)(void *arg);
};

struct PeerToPeer peer_to_peer_constructor(int domain, int service, int protocol, int port, u_long interface, void * (*server_function)(void *arg), void * (*client_function)(void *arg));

#endif /* PeerToPeer_h */
