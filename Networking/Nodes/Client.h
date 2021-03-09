// 
// Homo Deus
// 3/9/21
//
// Homo Deus C Library
// Client.h
//
// Eric Meehan
// 



#ifndef Client_h
#define Client_h

#include <sys/socket.h>
#include <netinet/in.h>

struct Client
{
    int domain;
    int service;
    int protocol;
    int port;
    u_long interface;
    
    int socket;
    
    void (*request)(struct Client *client, char *server_ip, char *request);
};

#endif /* Client_h */
