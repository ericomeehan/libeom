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
#include <arpa/inet.h>


void * server_function(void *arg)
{
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 1248, 20);
    struct sockaddr *address = (struct sockaddr *)&server.address;
    socklen_t address_size = (socklen_t)sizeof(server.address);
    printf("Starting server...\n");
    while (1)
    {
        int client = accept(server.socket, address, &address_size);
        char request[255];
        memset(request, 0, 255);
        read(client, request, 255);
        char *client_address = inet_ntoa(server.address.sin_addr);
        printf("\t\t\t%s says: %s", client_address, request);
        close(client);
        
        struct LinkedList *known_hosts = (struct LinkedList *)arg;
        short found = 0;
        for (int i = 0; i < known_hosts->length && !found; i++)
        {
            char *each = known_hosts->retrieve(known_hosts, i);
            if (strcmp(inet_ntoa(server.address.sin_addr), each) == 0)
            {
                found = 1;
            }
        }
        if (!found)
        {
            known_hosts->insert(known_hosts, known_hosts->length, client_address, strlen(client_address));
        }
    }
}

int main()
{
    struct LinkedList known_hosts = linked_list_constructor();
    known_hosts.insert(&known_hosts, 0, "127.0.0.1", 9);
    
    struct ThreadPool thread_pool = thread_pool_constructor(11);
    struct ThreadJob server_job = thread_job_constructor(server_function, &known_hosts);
    thread_pool.add_work(&thread_pool, server_job);
    
    while (1)
    {
        char request[255];
        memset(request, 0, 255);
        fgets(request, 255, stdin);
        for (int i = 0; i < known_hosts.length; i++)
        {
            struct Client client = client_constructor(AF_INET, SOCK_STREAM, 0, 1248, INADDR_ANY);
            client.request(&client, known_hosts.retrieve(&known_hosts, i), request);
        }
    }
}
