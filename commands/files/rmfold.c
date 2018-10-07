#include <stdio.h>
#include <stdint.h>

#include "../../colors.h"
#include "../../sys-specifications.h"

// ReMove FOLDer in a given directory AND ALL ITS CONTENTS (like rmdir -rf)
int tash_rmfold(char **args)
{
    // Check if a path was inputted
    if (args[1] == NULL)
    {
        fprintf(stderr, red "ERROR:" reset " expected a folder path in \"rmfold\"\n");
    } else {
        // Remove the folder AND ALL ITS CONTENTS
        rmdir(args[1]);
    }
    // return 1 because the command is sucessful and
    // we want to stay in the loop
    return 1;
}