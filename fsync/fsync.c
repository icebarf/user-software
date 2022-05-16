#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void print_help(void)
{
    printf("%s%s", "fsync: synchronize changes to a file\n", "Usage:\n\tfsync [FILE]\n");
}

int main(int argc, char* argv[])
{
    if (argc < 2 || argc > 2) {
        print_help();
        return 1;
    }

    if (access(argv[1], F_OK) != 0) {
        printf("fsync: error: %s: No file or directory\n", argv[1]);
        return 1;
    }
    if (access(argv[1], W_OK | R_OK)) {
        printf("fsync: error: %s: No permission to operate on file\n", argv[1]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "a+");
    if (fp == NULL) {
        printf("fsync: error: %s: Unable to open file - %s\n", argv[1], strerror(errno));
        return 1;
    }

    int fd = fileno(fp);
    if (fd == -1) {
        printf("fsync: error: %s: file stream is not associated with an actual file\n", argv[1]);
        return 1;
    }

    int rt = fsync(fd);
    if (rt == -1) {
        printf("fsync: error: call to fsync - %s\n", strerror(errno));
        return 1;
    }
    return 0;
}
