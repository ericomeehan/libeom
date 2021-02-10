//
//  HTTPRequest.h
//  hdelibc
//
//  Created by Eric Meehan on 2/9/21.
//

#ifndef HTTPRequest_h
#define HTTPRequest_h

enum HTTPMethods
{
    GET,
    POST,
    PUT,
    HEAD,
    PATCH,
    DELETE,
    CONNECT,
    OPTIONS,
    TRACE
};

struct HTTPRequest
{
    int Method;
    char *URI;
    float HTTPVersion;
};

struct HTTPRequest http_request_constructor(char *request_string);

#endif /* HTTPRequest_h */
