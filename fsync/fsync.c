#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define RESET "\033[m"
#define GREEN "\033[32m"
#define RED   "\033[31m"
#define BLUE "\033[34m"

void print_help(void)
{
    printf(BLUE "fsync: synchronize changes to a file\n" RESET GREEN "Usage:\n\tfsync [FILE]\n" RESET);
}

int main(int argc, char* argv[])
{
    /* Initial argument checking */
    if (argc < 2 || argc > 2) {
        print_help();
        return 1;
    }
    if (strncmp(argv[1], "--help", strnlen(argv[1], strlen("--help"))) == 0)
    {
        print_help();
        return 0;
    }

    /* check if argument file exists and we required permissions */
    if (access(argv[1], F_OK) != 0) {
        printf(RED "fsync: error: %s: No file or directory\n" RESET, argv[1]);
        return 1;
    }
    if (access(argv[1], W_OK | R_OK)) {
        printf(RED "fsync: error: %s: No permission to operate on file\n" RESET, argv[1]);
        return 1;
    }

    /* open a file stream to argument */
    FILE* fp = fopen(argv[1], "a+");
    if (fp == NULL) {
        printf(RED "fsync: error: %s: Unable to open file - %s\n" RESET, argv[1], strerror(errno));
        return 1;
    }

    /* get a file descriptor to argument file stream*/
    int fd = fileno(fp);
    if (fd == -1) {
        printf(RED "fsync: error: %s: file stream is not associated with an actual file\n" RESET, argv[1]);
        return 1;
    }

    /* finally perform the syscall */
    int rt = fsync(fd);
    if (rt == -1) {
        printf(RED "fsync: error: call to fsync - %s\n" RESET, strerror(errno));
        return 1;
    }
    return 0;
}
