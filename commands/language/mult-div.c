// simple way of parsing multiplication and division

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "../../sys-specifications.h"
#include "../../colors.h"

// multiply numbers
int tash_mult(char **args)
{
    // cannot build off 0, so build off first number
    int finalnum = 0;
    int firstnum = atoi(args[1]);

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
            finalnum = firstnum * atoi(args[i]);
        }
    }
    // return the final result
    printf("%d\n", finalnum);

    return 1;
}

// divide numbers
int tash_div(char **args)
{
    // cannot build off 0, so build off first number
    int finalnum = 0;
    int firstnum = atoi(args[1]);

    for (int i = 1; args[i] != '\0'; i++)
    {
        // if first input is a 0 (i.e. 0/1)
        if (strcmp(args[2], "0") == 0)
        {
            printf("0\n");
            return 1;
        // if second input is a 0 (i.e. 1/0)
        } else if (strcmp(args[i], "0") == 0) {
            fprintf(stderr, red "ERROR:" reset " Division by 0\n");
            return 1;
        }
        // if input is a letter
        if (isalpha(*args[i])) 
        {
            printf("%d\n", finalnum);
            return 1;
        }
        // if input is a number
        if (isdigit(*args[i]))
        {
            finalnum = firstnum / atoi(args[i]);
        }
    }
    // return the final resul
    printf("%d\n", finalnum);

    return 1;
}
