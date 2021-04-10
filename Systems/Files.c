//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// Files.c
//
// Eric Meehan
// 4/2/21
//
//

#include "Files.h"

#include <stdio.h>
#include <stdlib.h>

unsigned long get_file_size(char *path)
{
    FILE *file = fopen(path, "r");
    fseek(file, 0, SEEK_END);
    unsigned long size = ftell(file);
    fclose(file);
    return size;
}

unsigned long get_file_size_internal(FILE *file)
{
    fseek(file, 0, SEEK_END);
    unsigned long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}

void write_file(char *path, void *data, unsigned long size)
{
    FILE *file = fopen(path, "w");
    fwrite(data, size, 1, file);
    fclose(file);
}

void append_file(char *path, void *data, unsigned long size)
{
    FILE *file = fopen(path, "a");
    fwrite(data, size, 1, file);
    fclose(file);
}

void * read_file(char *path)
{
    FILE *file = fopen(path, "r");
    unsigned long size = get_file_size_internal(file);
    void *data = malloc(size);
    fread(data, size, 1, file);
    return data;
}
