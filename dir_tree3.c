#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include<string.h>
void traverseDirectory(const char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Failed to open directory: %s\n", path);
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            pid_t pid = fork();
            if (pid == -1) {
                fprintf(stderr, "Failed to create child process for directory: %s\n", entry->d_name);
            } else if (pid == 0) {
                // Child process
                printf("Child PID: %d, Traversing directory: %s\n", getpid(), entry->d_name);

                char filepath[1024];
                snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);
                traverseDirectory(filepath);

                exit(0);
            } else {
                // Parent process
                wait(NULL);
            }
        } else if (entry->d_type == DT_REG) {
            printf("File: %s\n", entry->d_name);
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

