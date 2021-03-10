//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// HTTPServer.c
//
// Eric Meehan
// 2/21/21
//
//

/*
 The HTTPServer struct is the basis for servers intended to read and recieve HTTP protocols.
 To utilize the server, instantiate an HTTPServer object with the constructor, register routes with the member method, and launch the server.
 */

#include "HTTPServer.h"
#include "../../Systems/ThreadPool.h"

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


// MARK: PUBLIC MEMBER FUNCTIONS

void launch(struct HTTPServer *server);
void * handler(void *arg);


// MARK: PUBLIC HELPER FUNCTIONS

void register_routes(struct HTTPServer *server, char * (*route_function)(struct HTTPServer *server, struct HTTPRequest *request), char *uri, int num_methods, ...);


// MARK: PRIVATE DATA TYPES

// The client server struct is used as an argument for the handler method.
// By necessity, handler takes one void pointer as an argument, but both the client address and server reference are required.
struct ClientServer
{
    int client;
    struct HTTPServer *server;
};

// The route struct is stored in the HTTPServer.routes dictionary as an encapsulation of the methods, uri, and function associated with a given route.
struct Route
{
    int methods[9];
    char *uri;
    char * (*route_function)(struct HTTPServer *server, struct HTTPRequest *request);
};


// MARK: CONSTRUCTORS

// The constructor initializes all of the required elements for the HTTP server.
struct HTTPServer http_server_constructor()
{
    struct HTTPServer server;
    server.server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 255);
    server.routes = dictionary_constructor(compare_string_keys);
    server.register_routes = register_routes;
    server.launch = launch;
    return server;
}


// MARK: PUBLIC MEMBER FUNCTIONS

// This function adds a specified route to the dictionary associated with a given HTTP server.
void register_routes(struct HTTPServer *server, char * (*route_function)(struct HTTPServer *server, struct HTTPRequest *request), char *uri, int num_methods, ...)
{
    struct Route route;
    // Iterate over the list of methods provided.
    va_list methods;
    va_start(methods, num_methods);
    for (int i = 0; i < num_methods; i++)
    {
        route.methods[i] = va_arg(methods, int);
    }
    // Register the URI.
    char buffer[strlen(uri)];
    route.uri = buffer;
    strcpy(route.uri, uri);
    // Copy the desired function.
    route.route_function = route_function;
    // Save the route in the server's dictionary.
    server->routes.insert(&server->routes, uri, sizeof(char[strlen(uri)]), &route, sizeof(route));
}


void launch(struct HTTPServer *server)
{
    // Initialize a thread pool to handle clients.
    struct ThreadPool thread_pool = thread_pool_constructor(20);
    // Cast some of the member variables from the server.
    struct sockaddr *sock_addr = (struct sockaddr *)&server->server.address;
    socklen_t address_length = (socklen_t)sizeof(server->server.address);
    // An infinite loop allows the server to continuously accept new clients.
    while (1)
    {
        // Create an instance of the ClientServer struct.
        struct ClientServer *client_server = malloc(sizeof(struct ClientServer));
        // Accept an incoming connection.
        client_server->client = accept(server->server.socket, sock_addr, &address_length);
        client_server->server = server;
        // Pass the client off to the thread pool.
        struct ThreadJob job = thread_job_constructor(handler, client_server);
        thread_pool.add_work(&thread_pool, job);
    }
}


// MARK: PRIVATE MEMBER FUNCTIONS

// The handler is used in a multithreadded environment to handle incoming connections.
void * handler(void *arg)
{
    // Cast the argument back to a ClientServer struct.
    struct ClientServer *client_server = (struct ClientServer *)arg;
    // Read the client's request.
    char request_string[30000];
    read(client_server->client, request_string, 30000);
    // Parse the request string into a usable format.
    struct HTTPRequest request = http_request_constructor(request_string);
    // Extract the URI from the request.
    char *uri = request.request_line.search(&request.request_line, "uri", sizeof("uri"));
    // Find the corresponding route in the server's dictionary.
    struct Route *route = client_server->server->routes.search(&client_server->server->routes, uri, sizeof(char[strlen(uri)]));
    // Process the request and respond to the client.
    char *response = route->route_function(client_server->server, &request);
    write(client_server->client, response, sizeof(char[strlen(response)]));
    close(client_server->client);
    // Free the ClientServer object.
    free(client_server);
    // Use the destructor to destroy the request.
    http_request_destructor(&request);
    // Thread functions must return a pointer, so this function returns NULL.
    return NULL;
}


// MARK: PUBLIC HELPER FUNCTIONS

// Joins the contents of multiple files into one.
char *render_template(int num_templates, ...)
{
    // Create a buffer to store the data in.
    char *buffer = malloc(30000);
    int buffer_position = 0;
    char c;
    FILE *file;
    // Iterate over the files given as arguments.
    va_list files;
    va_start(files, num_templates);
    // Read the contents of each file into the buffer.
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
