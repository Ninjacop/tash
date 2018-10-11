#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>
#include <search.h>

#include "../../colors.h"

char* stack[1000];

int tash_declare(char **args)
{
    stack[atoi(args[1])] = args[2];
    printf("%s\n", stack[atoi(args[1])]);
    
    return 1;
}

int tash_show(char **args)
{
    if(stack[atoi(args[1])] != NULL)
    {
        printf("%s\n", stack[atoi(args[1])]);
    }

    return 1;
}

