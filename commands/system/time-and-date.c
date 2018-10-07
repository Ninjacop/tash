#include <stdio.h>
#include <time.h>

#include "../../colors.h"

// Get the internal time from the computer and display it
int tash_time(char **args)
{
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf(cyan "Current local time and date:" reset " %s\n", asctime(timeinfo));

    // return 1 because the command is sucessful and
    // we want to stay in the loop
    return 1;
}
