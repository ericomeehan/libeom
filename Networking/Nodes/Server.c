//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// Server.c
//
// Eric Meehan
// 2/7/21
//
//

/*
 The Server struct is used as the basis for nodes that need to operate as servers.
 Generically, the server connects to the network and listens on a given port.
 */

#include "Server.h"

#include <stdio.h>
#include <stdlib.h>

// MARK: CONSTRUCTORS

struct Server server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog)
{
    struct Server server;
    // Define the basic parameters of the server.
    server.domain = domain;
    server.service = service;
    server.protocol = protocol;
    server.interface = interface;
    server.port = port;
    server.backlog = backlog;
    // Use the aforementioned parameters to construct the server's address.
    server.address.sin_family = domain;
    server.address.sin_port = htons(port);
    server.address.sin_addr.s_addr = htonl(interface);
    // Create a socket for the server.
    server.socket = socket(domain, service, protocol);
    // Confirm the connection was successful.
    if (server.socket == 0)
    {
        perror("Failed to connect socket...\n");
        exit(1);
    }
    // Attempt to bind the socket to the network.
    if ((bind(server.socket, (struct sockaddr *)&server.address, sizeof(server.address))) < 0)
    {
        perror("Failed to bind socket...\n");
        exit(1);
    }
    // Start listening on the network.
    if ((listen(server.socket, server.backlog)) < 0)
    {
        perror("Failed to start listening...\n");
        exit(1);
    }
    return server;
}
