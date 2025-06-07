#include <stdio.h>
#include <string.h>
#include "Aaron_libFS.h"

int main() {
    const char *filename = "Aaron_Introduction.txt";
    char buffer[1024];

    int choice;
    File *file;

    do {
        printf("\n--- File System Menu ---\n");
        printf("1. Create File\n");
        printf("2. Open and Write to File\n");
        printf("3. Read File\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar();  // Clear newline

        switch (choice) {
            case 1:
                if (fileCreate(filename) == 0)
                    printf("File created.\n");
                else
                    printf("Error creating file.\n");
                break;

            case 2:
                file = fileOpen(filename, "a+");
                if (file) {
                    const char *intro = "Hi, I'm Aaron.\n\n"
                        "I enjoy teaching computer science and exploring new technology. "
                        "In my free time, I love music and video games.\n";
                    fileWrite(file, intro);
                    fileClose(file);
                    printf("Intro written to file.\n");
                } else {
                    printf("Error opening file.\n");
                }
                break;

            case 3:
                file = fileOpen(filename, "r");
                if (file) {
                    memset(buffer, 0, sizeof(buffer));
                    fileRead(file, buffer, sizeof(buffer) - 1);
                    printf("File contents:\n%s\n", buffer);
                    fileClose(file);
                } else {
                    printf("Error reading file.\n");
                }
                break;

            case 4:
                if (fileDelete(filename) == 0)
                    printf("File deleted.\n");
                else
                    printf("Error deleting file.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}
