//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// Client.h
//
// Eric Meehan
// 3/9/21
//
//

/*
 The Client struct is used as a tool for connecting to and interacting with servers.
 In general, client objects are used to send requests to server APIs.
 */


#ifndef Client_h
#define Client_h

#include <sys/socket.h>
#include <netinet/in.h>

// MARK: DATA TYPES

struct Client
{
    /* PUBLIC MEMBER VARIABLES */
    // The network socket for handling connections.
    int socket;
    // Variables dealing with the specifics of a connection.
    int domain;
    int service;
    int protocol;
    int port;
    u_long interface;
    /* PUBLIC MEMBER METHODS */
    // The request method allows a client to make a request of a specified server.
    char * (*request)(struct Client *client, char *server_ip, void *request, unsigned long size);
};


// MARK: CONSTRUCTORS

struct Client client_constructor(int domain, int service, int protocol, int port, u_long interface);


#endif /* Client_h */
