#include "Aaron_libFS.h"
#include <stdlib.h>
#include <string.h>

int fileCreate(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) return -1;
    fclose(fp);
    return 0;
}

File* fileOpen(const char *filename, const char *mode) {
    FILE *fp = fopen(filename, mode);
    if (!fp) return NULL;

    File *file = malloc(sizeof(File));
    strcpy(file->name, filename);
    file->fp = fp;
    return file;
}

int fileWrite(File *file, const char *data) {
    if (!file || !file->fp) return -1;
    fputs(data, file->fp);
    return 0;
}

int fileRead(File *file, char *buffer, size_t size) {
    if (!file || !file->fp) return -1;
    rewind(file->fp);  // start from beginning
    fread(buffer, 1, size, file->fp);
    return 0;
}

int fileClose(File *file) {
    if (!file || !file->fp) return -1;
    fclose(file->fp);
    free(file);
    return 0;
}

int fileDelete(const char *filename) {
    return remove(filename);
}
