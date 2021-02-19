// 
// Homo Deus
// 2/18/21
//
// Homo Deus C Library
// main.c
//
// Eric Meehan
// 



#include <stdio.h>
#include "../Networking/Nodes/HTTPServer.h"

int main()
{
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 20, launch);
    server.launch(&server);
}
