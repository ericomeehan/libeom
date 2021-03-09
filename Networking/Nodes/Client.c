// 
// Homo Deus
// 3/9/21
//
// Homo Deus C Library
// Client.c
//
// Eric Meehan
// 



#include "Client.h"

#include <arpa/inet.h>
#include <string.h>

void request(struct Client *client, char *server_ip, char *request);

struct Client client_constructor(int domain, int service, int protocol, int port, u_long interface)
{
    struct Client client;
    client.domain = domain;
    client.port = port;
    client.interface = interface;
    client.socket = socket(domain, service, protocol);
    client.request = request;
    return client;
}

void request(struct Client *client, char *server_ip, char *request)
{
    struct sockaddr_in server_address;
    
    server_address.sin_family = client->domain;
    server_address.sin_port = htons(client->port);
    server_address.sin_addr.s_addr = client->interface;
    
    inet_pton(client->domain, server_ip, &server_address.sin_addr);
    connect(client->socket, (struct sockaddr*)&server_address, sizeof(server_address));
    send(client->socket, request, strlen(request), 0);
}
