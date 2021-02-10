//
//  t.c
//  hdelibc
//
//  Created by Eric Meehan on 2/9/21.
//

#include <stdio.h>
#include "HTTPRequest.h"

int main()
{
    char *request_string = "POST / HTTP/1.1\nHost: 127.0.0.1\nUser-Agent: python-requests/2.25.1\nAccept-Encoding: gzip, deflate\nAccept: */*\nConnection: keep-alive\nContent-Length: 16\nContent-Type: application/x-www-form-urlencoded\n\none=2&three=four";
    struct HTTPRequest request = http_request_constructor(request_string);
    printf("%d, %s, %f\n", request.Method, request.URI, request.HTTPVersion);
}
