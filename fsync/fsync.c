//   fsync - perform the fsync syscall on a file argument.
//   Copyright (C) 2022 Amritpal Singh
// 
//     This program is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
// 
//     This program is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
// 
//     You should have received a copy of the GNU General Public License
//     along with this program.  If not, see <https://www.gnu.org/licenses/>.
// 
// Also add information on how to contact you by electronic and paper mail.
// 
//   If the program does terminal interaction, make it output a short
// notice like this when it starts in an interactive mode:
// 
//     <program>  Copyright (C) <year>  <name of author>
//     This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
//     This is free software, and you are welcome to redistribute it
//     under certain conditions; type `show c' for details.
// 
// The hypothetical commands `show w' and `show c' should show the appropriate
// parts of the General Public License.  Of course, your program's commands
// might be different; for a GUI interface, you would use an "about box".
// 
//   You should also get your employer (if you work as a programmer) or school,
// if any, to sign a "copyright disclaimer" for the program, if necessary.
// For more information on this, and how to apply and follow the GNU GPL, see
// <https://www.gnu.org/licenses/>.
// 
//   The GNU General Public License does not permit incorporating your program
// into proprietary programs.  If your program is a subroutine library, you
// may consider it more useful to permit linking proprietary applications with
// the library.  If this is what you want to do, use the GNU Lesser General
// Public License instead of this License.  But first, please read
// <https://www.gnu.org/licenses/why-not-lgpl.html>.
 
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
