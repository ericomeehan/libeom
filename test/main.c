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

char * home(struct HTTPServer *server, struct HTTPRequest *request)
{
    char *x = render_template(2, "/Users/eric/Documents/demo/header.html", "/Users/eric/Documents/demo/index.html");
    return x;
}

char * about(struct HTTPServer *server, struct HTTPRequest *request)
{
    return render_template(2, "/Users/eric/Documents/demo/header.html", "/Users/eric/Documents/demo/about.html");
}

int main()
{
    struct HTTPServer server = http_server_constructor();
    
    server.register_routes(&server, home, "/", 0);
    server.register_routes(&server, about, "/about", 0);
    
    server.launch(&server);
}
