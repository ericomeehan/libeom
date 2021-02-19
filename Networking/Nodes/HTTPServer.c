// 
// Homo Deus
// 2/18/21
//
// Homo Deus C Library
// HTTPServer.c
//
// Eric Meehan
// 



#include "HTTPServer.h"
#include "../Protocols/HTTPRequest.h"

#include <unistd.h>
#include <string.h>
#include <stdio.h>

void launch(struct Server *server)
{
    int addrlen = sizeof(server->address);
    long valread;
    while(1)
    {
        printf("=== WAITING ===\n");
        int new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&addrlen);
        char buffer[30000];
        valread = read(new_socket, buffer, 30000);
        struct HTTPRequest request = http_request_constructor(buffer);
        char *x = "Host";
        char *content_type = (char *)request.header_fields.search(&request.header_fields, x, sizeof(char[strlen(x)]));
        char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 13\n\n";
        char r[strlen(hello) + strlen(content_type)];
        strcat(r, hello);
        strcat(r, content_type);
        write(new_socket, r, strlen(r));
        close(new_socket);
    }
}
