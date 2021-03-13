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
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>

struct ServerLoopArgument
{
    int client;
    struct Server *server;
    struct LinkedList *known_hosts;
};

void * server_loop(void *arg)
{
    struct ServerLoopArgument *argument = arg;
    char request[255];
    memset(request, 0, 255);
    read(argument->client, request, 255);
    char *client_address = inet_ntoa(argument->server->address.sin_addr);
    printf("\t\t\t%s says: %s\n", client_address, request);
    close(argument->client);
    short found = 0;
    for (int i = 0; i < argument->known_hosts->length && !found; i++)
    {
        if (strcmp(client_address, argument->known_hosts->retrieve(argument->known_hosts, i)) == 0)
        {
            found = 1;
        }
    }
    if (!found)
    {
        argument->known_hosts->insert(argument->known_hosts, argument->known_hosts->length, client_address, sizeof(client_address));
    }
    return NULL;
}

void * server_function(void *arg)
{
    printf("Server running.\n");
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 1248, 20);
    struct sockaddr *address = (struct sockaddr *)&server.address;
    socklen_t address_length = (socklen_t)sizeof(server.address);
    struct ThreadPool thread_pool = thread_pool_constructor(50);
    while (1)
    {
        struct ServerLoopArgument loop_arg;
        loop_arg.client = accept(server.socket, address, &address_length);
        loop_arg.server = &server;
        loop_arg.known_hosts = arg;
        struct ThreadJob server_job = thread_job_constructor(server_loop, &loop_arg);
        thread_pool.add_work(&thread_pool, server_job);
    }
    return NULL;
}

void client_function(char *request, struct LinkedList *known_hosts)
{
    struct Client client = client_constructor(AF_INET, SOCK_STREAM, 0, 1248, INADDR_ANY);
    for (int i = 0; i < known_hosts->length; i++)
    {
        client.request(&client, known_hosts->retrieve(known_hosts, i), request);
    }
}

int main()
{
    struct LinkedList known_hosts = linked_list_constructor();
    known_hosts.insert(&known_hosts, 0, "127.0.0.1", 10);
    
    printf("Starting server...\n");
    pthread_t server_thread;
    pthread_create(&server_thread, NULL, server_function, &known_hosts);
    
    while (1)
    {
        char request[255];
        memset(request, 0, 255);
        fgets(request, 255, stdin);
        client_function(request, &known_hosts);
    }
}
