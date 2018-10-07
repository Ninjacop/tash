#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

#include "../../colors.h"

// Lists Contents of a folder (like ls) -- one file/folder per line
int tash_lc(char **args)
{   
    // If no file and argument is specified
    if (args[1] == NULL)
    {
        fprintf(stderr, red "ERROR:" reset " expected folder location or directory to \"lc\"\n");
        return 1;
    // If no file is specified, but the `--here` arguments gets the contents of the current directory  
    } else if (strcmp(args[1], "--here") == 0) {
        DIR *d;
        struct dirent *dir;
        d = opendir(".");
        
        // Does the directory exist?
        if (d)       
        {
            while ((dir = readdir(d)) != NULL)
            {
                printf("%s\n", dir->d_name);
            }
            // Close the directory stream
            closedir(d);
        // If no arguments match the above    
        } else {
            perror (red "ERROR:" reset " Couldn't open the current directory");
        }
    } 

    // return 1 because the command is sucessful and
    // we want to stay in the loop 
    return 1; 
}