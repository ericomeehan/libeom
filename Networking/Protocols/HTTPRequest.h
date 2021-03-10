//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// HTTPRequest.h
//
// Eric Meehan
// 2/9/21
//
//

/*
 The HTTPRequest struct contains three dictionaries representing the three components of an HTTP Request.
 */

#ifndef HTTPRequest_h
#define HTTPRequest_h

#include "../../DataStructures/Dictionary/Dictionary.h"


// MARK: DATA TYPES

struct HTTPRequest
{
    struct Dictionary request_line;
    struct Dictionary header_fields;
    struct Dictionary body;
};


// MARK: CONSTRUCTORS

struct HTTPRequest http_request_constructor(char *request_string);
void http_request_destructor(struct HTTPRequest *request);

#endif /* HTTPRequest_h */
