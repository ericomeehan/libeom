//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// Files.h
//
// Eric Meehan
// 4/2/21
//
//

/*
 Some basic utilities for dealing with files.
 */

#ifndef Files_h
#define Files_h

unsigned long get_file_size(char *path);
void write_file(char *path, void *data, unsigned long size);
void append_file(char *path, void *data, unsigned long size);
void * read_file(char *path);

#endif /* Files_h */
