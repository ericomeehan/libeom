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

// The tokenizer is used to convert stdin commands into char * arrays to be used as argv.
void tokenizer(char *buffer, int *argc, char **argv);

// The terminal function handles the input method of the application and passes work to the interpreter.
// The interpreter is defined in the application itself.
int terminal(int argc, const char **argv, int (*interpreter)(int argc, const char **argv), const char *pipeline)
{
    // Prepare a result for the program execution.
    int result = 0;
    
    // Handle the command based on the input type.
    switch (argc)
    {
        // There should always be at least one command.
        case 0:
        {
            fprintf(stderr, "Error, not enough arguments.  How did you do that?\n");
            result = EXIT_FAILURE;
            break;
        }
        
        // A single argument means that either an interactive shell or pipeline should be opened.
        case 1:
        {
            int pipe = 0;
            if (!isatty(fileno(stdin)))
            {
                // Rerout stdin, stdout, and stderr to pipeline.
                pipe = open(pipeline, O_RDWR);
                dup2(pipe, STDIN_FILENO);
                dup2(pipe, STDOUT_FILENO);
                dup2(pipe, STDERR_FILENO);
            }
            
            // Receive commands until the user quits.
            char buffer[256];
            do
            {
                // Clean the buffer.
                memset(buffer, 0, 256);
                
                // Get the command.
                fgets(buffer, 256, stdin);
                
                // Tokenize the command.
                char *args[256] = {0};
                args[0] = (char *)argv[0];
                tokenizer(buffer, &argc, args);
                
                // Execute the command.
                result = interpreter(argc, argv);
                
            } while (strcmp(buffer, "quit") != 0);
            break;
        }
            
        // A single command can simply be executed by the interpreter.
        default:
            result = interpreter(argc, argv);
            break;
    }
    return result;
}

void tokenizer(char *buffer, int *argc, char **argv)
{
    // This creates an array of pointers to substrings in buffer delimited by spaces and taking quoted
    // sections as complete strings.
    *argc = 1;
    short quotes_open = 0;
    for (int i = 0; i < strlen(buffer); i++)
    {
        if (buffer[i] == ' ' && !quotes_open)
        {
            buffer[i] = 0;
            argv[*argc] = buffer + i + 1;
        }
        else if (buffer[i] == '"')
        {
            quotes_open = !quotes_open;
        }
    }
}
