#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../sys-specifications.h"
#include "../../colors.h"

// Delay the current thread/prompt by a given amount of seconds
// IF THE INPUTTED SECONDS ARE NOT NUMBERS NO DELAY WILL HAPPEN
int tash_delay(char **args)
{
    unsigned int time = atoi(args[1]);

    // If no seconds are inputted
    if (args[1] == NULL)
    {
        fprintf(stderr, red "ERROR:" reset " expected a number of seconds in \"delay\"\n");
    // Regular output 
    } else if (args[1] != NULL && args[2] == NULL) {
        sleep(time);
    // Delay for half the time
    } else if (args[1] != NULL && strcmp(args[2], "--half") == 0) {
        sleep(time/2);
    // Delay for twice the time
    } else if (args[1] != NULL && strcmp(args[2], "--double") == 0) {
        sleep(time*2);
    // If multiple arguments were inputted
    } else {
        fprintf(stderr, red "ERROR:" reset " The values given to \"delay\" are invalid\n");
    }

    return 1;
}