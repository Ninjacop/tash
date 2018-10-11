// Load each function to be used, and other specifications

#include "sys-specifications.h"
#include "colors.h"

#include "commands/files/cf.c"
#include "commands/files/fsize.c"
#include "commands/files/ls.c"
#include "commands/files/mkfile.c"
#include "commands/files/mkfold.c"
#include "commands/files/mt.c"
#include "commands/files/rmfile.c"
#include "commands/files/rmfold.c"

#include "commands/language/comments.c"
#include "commands/language/add-sub.c"
#include "commands/language/mult-div.c"

#include "commands/system/clear.c"
#include "commands/system/delay.c"
#include "commands/system/exit.c"
#include "commands/system/time-and-date.c"

// Forward declaration of 'help' and 'load, 
// because they cannot be used in a seperate file.
int tash_help(char **args);

// List of all accepted commands
char *builtin_str[] = {
    "mult",
    "div",
    "add",
    "sub",
    "!",
    "fsize",
    "mkfold",
    "mkfile",
    "rmfold",
    "rmfile",
    "mt",
    "cf",
    "lc",
    "time",
    "delay",
    "clear",
    "help",
    "exit"
};

// List of all the corresponding functions 
// to those commands
int (*builtin_func[]) (char **) = {
    &tash_mult,
    &tash_div,
    &tash_add,
    &tash_sub,
    &tash_comments,
    &tash_fsize,
    &tash_mkfold,
    &tash_mkfile,
    &tash_rmfold,
    &tash_rmfile,
    &tash_mt,
    &tash_cf,
    &tash_lc,
    &tash_time,
    &tash_delay,
    &tash_clear,
    &tash_help,
    &tash_exit
};

// Helper function to 'help', listing the number
// of current commands
int tash_num_builtins()
{
    return sizeof(builtin_str) / sizeof(char *);
}

// The 'help' function -- I know it's a little messy
// but it gets the job done... for now (TBD)
int tash_help(char **args)
{
    // If no arguments are supplied
    if (args[1] == NULL) 
    {
        printf("\n\nTeegan's Awesome SHell!\n\n\t Version %s\n\n", VERSION_NO);
        printf("These are the current builtin commands:\n\n");

    // List all the builtin commands
    for (int i = 1; i < tash_num_builtins(); i++) // i = 1 so it doesn't show comments and other language syntax related commands
    {
        printf("    %s\n", builtin_str[i]);
    }

    // Manuals/documentations for each command, dependent on the argument supplied
    printf("\nType \"help [command]\" for more information on a specific command\n");
    } else if (strcmp(args[1], "fsize") == 0) {
        printf("\n\nfsize [path to file] - (File SIZE) \n\tDisplays the file size of a file at a specific location.\n\n");
    } else if (strcmp(args[1], "mkfold") == 0) {
        printf("\n\nmkfold [full path to folder] - (MaKE FOLDer) \n\tCreates an empty folder at a specific location\n\n");
    } else if (strcmp(args[1], "mkfile") == 0) {
        printf("\n\nmkfile [full path to file] - (MaKe FILE) \n\tCreates an empty file at a specific loation where you provide the extension.\n\n");
    } else if (strcmp(args[1], "rmfold") == 0) {
        printf("\n\nrmfold [full path to folder] - (ReMove FOLDer) \n\tRemoves a folder at a specific location,\n\tdeleting all the files in the selected folder.\n\n");
    } else if (strcmp(args[1], "rmfile") == 0) {
        printf("\n\nrmfile [full path to file] - (ReMove FILE) \n\tRemoves a file at a specific location.\n\n");
    } else if (strcmp(args[1], "mt") == 0) {
        printf("\n\nmt [full path to folder | other options similar to `cd`] - (Move To) \n\tChanges the current working directory.\n\tIt works exactly like `cd` from other shells.\n\n");
    } else if (strcmp(args[1], "cf") == 0) {
        printf("\n\ncf [no arguments] - (Current Folder) \n\tDisplays the current working directory.\n\n");
    } else if (strcmp(args[1], "lc") == 0) {
        printf("\n\nlc [full path to folder] - (List Contents) \n\tDisplays each sub-folder and file in a given directory\n\tone item per line.\n\n");
    } else if (strcmp(args[1], "time") == 0) {
        printf("\n\ntime [no arguments] - (current TIME and date) \n\tDisplays the current time and date according to the internal clock.\n\n");
    } else if (strcmp(args[1], "delay") == 0) {
        printf("\n\ndelay [seconds] - (DELAY thread) \n\tWaits for a specific amount of time and then continues the current process.\n\n");
    } else if (strcmp(args[1], "clear") == 0) {
        printf("\n\nclear [no arguments] - (CLEAR screen) \n\tWipes the current terminal window clean, but you can scroll up a little\n\tto see the previous work before `clear` was used.\n\n");
    } else if (strcmp(args[1], "help") == 0) {
        printf("\n\nhelp [no arguments | command] - (HELP) \n\tWhen no arguments are given, a brief description of TASH is given\n\talong with all the available commands.\n\tWhen an argument/command is given, a simple explanation on the command/argument about its purpose.\n\n");
    } else if (strcmp(args[1], "exit") == 0) {
        printf("\n\nexit [no arguments] - (EXIT TASH) \n\tExits TASH completely, going back into the parent shell.\n\n");
    } else if (args[1] != NULL && args[2] != NULL)
    {
        fprintf(stderr, red "ERROR:" reset "Please use only none or one command in \"help\"\n");
    } else {
        fprintf(stderr, red "ERROR:" reset "The inputted command is not known\n");
    }
    return 1;
}

