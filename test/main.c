//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// main.c
//
// Eric Meehan
// 2/18/21
//
//

#include "../libeom.h"

#include <string.h>
#include <stdio.h>
#include <unistd.h>

void * client_function(void *arg)
{
    struct Client client = client_constructor(AF_INET, SOCK_STREAM, 0, 1248, INADDR_ANY);
    client.request(&client, "127.0.0.1", arg);
    return NULL;
}

void * server_function(void *arg)
{
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 1248, 20);
    struct sockaddr *address = (struct sockaddr *)&server.address;
    socklen_t address_size = (socklen_t)sizeof(server.address);
    while (1)
    {
        int client = accept(server.socket, address, &address_size);
        char request[255];
        memset(request, 0, 255);
        read(client, request, 255);
        printf("%s", request);
        close(client);
    }
}

int main()
{
    struct ThreadPool thread_pool = thread_pool_constructor(11);
    struct ThreadJob server_job = thread_job_constructor(server_function, NULL);
    thread_pool.add_work(&thread_pool, server_job);
    while (1)
    {
        char request[255];
        memset(request, 0, 255);
        fgets(request, 255, stdin);
        struct ThreadJob client_job = thread_job_constructor(client_function, request);
        thread_pool.add_work(&thread_pool, client_job);
    }
}
