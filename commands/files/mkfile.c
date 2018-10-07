#include <stdio.h>

#include "../../colors.h"

// MaKe a FILE with a path (like touch)
int tash_mkfile(char **args)
{
    FILE *file;

    // Check if a file was inputted
    if (args[1] == NULL)
    {
        fprintf(stderr, red "ERROR:" reset " expected a file path in \"mkfile\"\n");
    } else {
        // Write nothing to an empty file, then close it
        file = fopen(args[1], "w");
        fclose(file);
    }

    // return 1 because the command is sucessful and
    // we want to stay in the loop
    return 1;
}