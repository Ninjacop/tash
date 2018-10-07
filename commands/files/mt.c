#include <stdio.h>

#include "../../colors.h"
#include "../../sys-specifications.h"

// Move To a given directory (like cd)
int tash_mt(char **args)
{
    // Check if a file was inputted
    if (args[1] == NULL)
    {
        fprintf(stderr, red "ERROR:" reset " expected targeted folder in \"mt\"\n");
    } else {
        if (chdir(args[1]) != 0)
        {
            perror("tash");
        }
    }
    // return 1 because the command is sucessful and
    // we want to stay in the loop
    return 1;
}