//
// Homo Deus
// 2/7/21
//
// Homo Deus C Library
// Server.h
//
// Eric Meehan
//

#ifndef Server_h
#define Server_h

#include <sys/socket.h>
#include <netinet/in.h>

struct Server
{
    int domain;
    int service;
    int protocol;
    u_long interface;
    int port;
    int backlog;
    
    struct sockaddr_in address;
    
    int socket;
};

struct Server server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog);

#endif /* Server_h */
