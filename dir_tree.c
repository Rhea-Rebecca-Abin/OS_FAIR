#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void traverseDirectory(const char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Failed to open directory: %s\n", path);
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char filepath[1024];
        snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (stat(filepath, &statbuf) == -1) {
            fprintf(stderr, "Failed to get file status: %s\n", filepath);
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            pid_t pid = fork();

            if (pid == -1) {
                fprintf(stderr, "Failed to create child process for directory: %s\n", filepath);
            } else if (pid == 0) {
                // Child process
                printf("Child PID: %d, Traversing directory: %s\n", getpid(), filepath);
                traverseDirectory(filepath);
                exit(0);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    printf("Parent PID: %d, Traversing directory: %s\n", getpid(), argv[1]);
    traverseDirectory(argv[1]);

    return 0;
}

