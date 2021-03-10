//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// Server.h
//
// Eric Meehan
// 2/7/21
//
//

/*
 The Server struct is used as the basis for nodes that need to operate as servers.
 Generically, the server connects to the network and listens on a given port.
 */

#ifndef Server_h
#define Server_h

#include <sys/socket.h>
#include <netinet/in.h>

// MARK: DATA TYPES

struct Server
{
    /* PUBLIC MEMBER VARIABLES */
    int domain;
    int service;
    int protocol;
    u_long interface;
    int port;
    int backlog;
    struct sockaddr_in address;
    int socket;
};


// MARK: CONSTRUCTORS

struct Server server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog);

#endif /* Server_h */
