#include <stdio.h>
#include <stdlib.h>

#include "../../sys-specifications.h"

// Displays the Current Folder (like pwd)
int tash_cf(char **args)
{
    char buff[FILENAME_MAX];
    
    GetPWD( buff, FILENAME_MAX );
    printf("\n%s\n", buff);

    // return 1 because the command is sucessful and
    // we want to stay in the loop
    return 1;
}