//
// Homo Deus
// 2/9/21
//
// Homo Deus C Library
// HTTPRequest.h
//
// Eric Meehan
//

#ifndef HTTPRequest_h
#define HTTPRequest_h

#include "../../DataStructures/Dictionary/Dictionary.h"

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
    struct Dictionary header_fields;
};

struct HTTPRequest http_request_constructor(char *request_string);

#endif /* HTTPRequest_h */
