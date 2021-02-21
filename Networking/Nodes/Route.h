// 
// Homo Deus
// 2/21/21
//
// Homo Deus C Library
// Route.h
//
// Eric Meehan
// 



#ifndef Route_h
#define Route_h

#include "HTTPServer.h"
#include "../Protocols/HTTPRequest.h"

struct Route
{
    int methods[9];
    char *uri;
    char * (*route_function)(struct HTTPServer *server, struct HTTPRequest *request);
};

#endif /* Route_h */
