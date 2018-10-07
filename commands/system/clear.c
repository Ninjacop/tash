#include <stdio.h>
#include <sys/ioctl.h>

#include "../../sys-specifications.h"

// Clears the terminal prompt using a semi-okay way
int tash_clear(char **args)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    int rows = w.ws_row;
    int i;

    // For the amount of rows in a prompt, print newlines
    for (i = 0; i < rows; i++)
    {
        printf("\n");
    }
    // return 1 because the command is sucessful and
    // we want to stay in the loop
    return 1;
}
