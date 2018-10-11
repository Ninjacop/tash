// A simple way of parsing addition and subtraction
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

#include "../../sys-specifications.h"
#include "../../colors.h"

// add two numbers
int tash_add(char **args)
{
    // start with 0 and build it up
    int finalnum = 0;

    for (int i = 1; args[i] != '\0'; i++)
    {
        // if input is a letter
        if (isalpha(*args[i]))
        {
            printf("%d\n", finalnum);
            return 1;
        }
        // if input is a number
        if (isdigit(*args[i]))
        {
            finalnum += atoi(args[i]);
        }
    }

    // print the final result
    printf("%d\n", finalnum);

    return 1;
}

// subtract two numbers
int tash_sub(char **args)
{
    // cannot start with 0, so build it from the first input
    int finalnum = 0;
    int firstnum = atoi(args[1]);

    for(int i = 1; args[i] != '\0'; i++)
    {
        // if input is a letter
        if (isalpha(*args[i]))
        {
            printf("%d\n", finalnum);
            return 1;
        }
        // if input is a number
        if (isdigit(*args[i]))
        {
            finalnum = firstnum - atoi(args[i]);
        }
    }
    
    // print the final result 
    printf("%d\n", finalnum);

    return 1;
}
