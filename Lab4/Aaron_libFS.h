#ifndef AARON_LIBFS_H
#define AARON_LIBFS_H

#include <stdio.h>

typedef struct {
    char name[100];
    FILE *fp;
} File;

int fileCreate(const char *filename);
File* fileOpen(const char *filename, const char *mode);
int fileWrite(File *file, const char *data);
int fileRead(File *file, char *buffer, size_t size);
int fileClose(File *file);
int fileDelete(const char *filename);
#endif