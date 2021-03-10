//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// HTTPServer.h
//
// Eric Meehan
// 2/21/21
//
//

/*
 The HTTPServer struct is the basis for servers intended to read and recieve HTTP protocols.
 To utilize the server, instantiate an HTTPServer object with the constructor, register routes with the member method, and launch the server.
 */

#ifndef HTTPServer_h
#define HTTPServer_h

#include "Server.h"
#include "../Protocols/HTTPRequest.h"

// MARK: DATA TYPES

struct HTTPServer
{
    /* PUBLIC MEMBER VARIABLES */
    // A generic server object to connect to the network with the appropriate protocols.
    struct Server server;
    // A dictionary of routes registerred on the server with URL's as keys.
    struct Dictionary routes;
    
    /* PUBLIC MEMBER METHODS */
    // This method is used to register URL's as routes to the server.
    void (*register_routes)(struct HTTPServer *server, char * (*route_function)(struct HTTPServer *server, struct HTTPRequest *request), char *uri, int num_methods, ...);
    // The launch sequence begins an infinite loop where the server listens for and handles incoming connections.
    void (*launch)(struct HTTPServer *server);
};

// The HTTPMethods enum lists the various HTTP methods for easy referral.
enum HTTPMethods
{
    CONNECT,
    DELETE,
    GET,
    HEAD,
    OPTIONS,
    PATCH,
    POST,
    PUT,
    TRACE
};

// MARK: CONSTRUCTORS

struct HTTPServer http_server_constructor(void);


// MARK: PUBLIC HELPER FUNCTIONS

// This function combines the contents of files into a single string.
// This is used to create web pages out of multiple templates.
char *render_template(int num_templates, ...);

#endif /* HTTPServer_h */

