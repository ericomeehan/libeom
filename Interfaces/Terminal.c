//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// Terminal.c
//
// Eric Meehan
// 4/17/21
//
//

#include "Terminal.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


int terminal(int argc, const char **argv, int (*interpreter)(int argc, const char **argv), const char *pipeline)
{
    int result = 0;
    switch (argc)
    {
        case 0:
        {
            perror("Error, not enough arguments\n");
            result = EXIT_FAILURE;
            break;
        }
        case 1:
        {
            if (isatty(fileno(stdin)))
            {
                char buffer[256];
                do
                {
                    memset(buffer, 0, 256);
                    printf(">>> ");
                    fgets(buffer, 256, stdin);
                    // result = interpreter(1, buffer);
                    printf("%s\n", buffer);
                } while (strcmp(buffer, "quit\n") != 0);
            }
            else
            {
                char buffer[256] = {0};
                int pipe = open(pipeline, O_RDWR);
                read(pipe, buffer, 256);
                // result = interpreter(1, buffer);
                printf("%s\n", buffer);
                char *response = "hello yourself";
                write(pipe, response, strlen(response) + 1);
                close(pipe);
            }
            break;
        }
        default:
            result = interpreter(argc, argv);
            break;
    }
    return result;
}
