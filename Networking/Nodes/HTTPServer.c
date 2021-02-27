// 
// Homo Deus
// 2/21/21
//
// Homo Deus C Library
// HTTPServer.c
//
// Eric Meehan
// 



#include "HTTPServer.h"
#include "Route.h"
#include "../../System/ThreadPool.h"

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void register_routes(struct HTTPServer *server, char * (*route_function)(struct HTTPServer *server, struct HTTPRequest *request), char *uri, int num_methods, ...);
void launch(struct HTTPServer *server);
void * handler(void *arg);

struct ClientServer
{
    int client;
    struct HTTPServer *server;
};

struct HTTPServer http_server_constructor()
{
    struct HTTPServer server;
    server.server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 255);
    server.routes = dictionary_constructor(compare_string_keys);
    server.register_routes = register_routes;
    server.launch = launch;
    return server;
}


void register_routes(struct HTTPServer *server, char * (*route_function)(struct HTTPServer *server, struct HTTPRequest *request), char *uri, int num_methods, ...)
{
    struct Route route;
    va_list methods;
    va_start(methods, num_methods);
    for (int i = 0; i < num_methods; i++)
    {
        route.methods[i] = va_arg(methods, int);
    }
    char buffer[strlen(uri)];
    route.uri = buffer;
    strcpy(route.uri, uri);
    route.route_function = route_function;
    
    server->routes.insert(&server->routes, uri, sizeof(char[strlen(uri)]), &route, sizeof(route));
}

void launch(struct HTTPServer *server)
{
    struct ThreadPool thread_pool = thread_pool_constructor(20);
    struct sockaddr *sock_addr = (struct sockaddr *)&server->server.address;
    socklen_t address_length = (socklen_t)sizeof(server->server.address);
    while (1)
    {
        struct ClientServer *client_server = malloc(sizeof(struct ClientServer));
        client_server->client = accept(server->server.socket, sock_addr, &address_length);
        client_server->server = server;
        struct ThreadJob job = thread_job_constructor(handler, client_server);
        thread_pool.add_work(&thread_pool, job);
    }
}

void * handler(void *arg)
{
    struct ClientServer *client_server = (struct ClientServer *)arg;
    char request_string[30000];
    read(client_server->client, request_string, 30000);
    struct HTTPRequest request = http_request_constructor(request_string);
    char *uri = request.request_line.search(&request.request_line, "uri", sizeof("uri"));
    struct Route *route = client_server->server->routes.search(&client_server->server->routes, uri, sizeof(char[strlen(uri)]));
    char *response = route->route_function(client_server->server, &request);
    write(client_server->client, response, sizeof(char[strlen(response)]));
    free(client_server);
    return NULL;
}

char *render_template(int num_templates, ...)
{
    va_list files;
    va_start(files, num_templates);
    char *buffer = malloc(30000);
    int buffer_position = 0;
    char c;
    FILE *file;
    for (int i = 0; i < num_templates; i++)
    {
        char *path = va_arg(files, char*);
        file = fopen(path, "r");
        while ((c = fgetc(file)) != EOF)
        {
            buffer[buffer_position] = c;
            buffer_position += 1;
        }
    }
    va_end(files);
    return buffer;
}
