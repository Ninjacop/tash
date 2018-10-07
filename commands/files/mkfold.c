#include <string.h>
#include <stdio.h>
#include <sys/stat.h>

#include "../../colors.h"
#include "../../sys-specifications.h"

// MaKe a FOLDer in a given path (like mkdir)
int tash_mkfold(char **args)
{
    // Check if a path was inputted
    if (args[1] == NULL)
    {
        fprintf(stderr, red "ERROR:" reset " expected a folder path in \"mkf\"\n");
        return 1;
    } else {
        // Creates a folder with Read/Write/Search perms for the owner and group, and Read/Search for others
        mkdir(args[1], S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    }
    
    // return 1 because the command is sucessful and
    // we want to stay in the loop
    return 1;
}