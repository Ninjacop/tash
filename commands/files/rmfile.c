#include <string.h>
#include <stdio.h>

#include "../../colors.h"

// ReMove FILE in a given directory (like rm)
int tash_rmfile(char **args)
{
    // Check if a directory was inputted
    if (args[1] == NULL)
    {
        fprintf(stderr, red "ERROR:" reset " expected a file path in \"rmfile\"\n");
    } else {
        // Remove the file
        remove(args[1]);
    }
    // return 1 because the command is sucessful and
    // we want to stay in the loop    
    return 1;
}