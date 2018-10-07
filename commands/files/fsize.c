#include <stdio.h>
#include <string.h>

#include "../../colors.h"

// Find a File's Size with different results
int tash_fsize(char **args)
{      
    int result;
    
    // Open a file
    FILE *fh = fopen(args[1], "rb");

    // Read through the file
    fseek(fh, 0, SEEK_END);

    // result equals the amount of bytes in the file
    result = (int)ftell(fh);

    if (args[1] == NULL)
    {
        // When no file is specified
        fprintf(stderr, red "ERROR:" reset " expected a file path in \"fsize\"\n");
    } else if (args[1] != NULL && args[2] == NULL) {
        // Regular output
        printf("%d Bytes\n", result);
    } else if (strcmp(args[2], "--kb")) {
        // Print output in Kilobytes (KB) when specified
        printf("%f KB\n", result / 1000.0);
    } else if (strcmp(args[2], "--mb")) {
        // Print output in Megabytes (MB) when specified
        printf("%f MB\n", result / 1000000.0);
    } else if (strcmp(args[2], "--gb")) {
        // Print output in Gigabytes (GB) when specified
        printf("%f GB\n", result / 1000000000.0);
    } else {
        // If the input for `fsize` doesn't include anything or other things, print this error
        fprintf(stderr, red "ERROR:" reset " arguments given to \"fsize\" are invalid\n");
    }
    
    // Close the file
    fclose(fh);
    
    // return 1 because the command is sucessful and
    // we want to stay in the loop
    return 1;
}
