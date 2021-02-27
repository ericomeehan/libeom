// 
// Homo Deus
// 2/18/21
//
// Homo Deus C Library
// main.c
//
// Eric Meehan
//

#include "../Networking/Nodes/HTTPServer.h"

#include <stdio.h>

char * home(struct HTTPServer *server, struct HTTPRequest *request)
{
    char *a = "/Users/eric/Documents/demo/header.html";
    char *b = "/Users/eric/Documents/demo/index.html";
    char *x = render_template(2, a, b);
    return x;
}

int main()
{
    struct HTTPServer server = http_server_constructor();
    
    server.register_routes(&server, home, "/", 0);
    server.launch(&server);
}
