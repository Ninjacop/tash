#include "funcdefs.c"

// This powers the REPL (Read Eval Print Loop)/Command Loop
 
// Reads a line based off of the buffer size, which is declared
// in "funcdefs.c" and other files, so it doesn't need to be declared here
char *tash_read_line(void)
{
    int bufsize = TASH_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer) 
    {
        fprintf(stderr, red "ERROR:" reset " allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        // Read a character
        c = getchar();

        // If EOF is hit, return a null character and return a new line
        if (c == EOF || c == '\n')
        {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        // Move to the next column in the buffer
        position++;

        // Reallocate if the buffer has exceeded
        if (position >= bufsize)
        {
            bufsize += TASH_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if (!buffer)
            {
                // Red & reset sets the text color to the specified color then
                fprintf(stderr, red "ERROR:" reset " allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

// "Tokenizes" each command, so arguments can be split up from actual commands
// and arguments given to the specified command
char **tash_split_line(char *line)
{
    int bufsize = TASH_TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, red "ERROR:" reset " allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TASH_TOK_DELIM);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize) 
        {
            bufsize += TASH_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));

            if (!tokens)
            {
                fprintf(stderr, red "ERROR:" reset " allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TASH_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

// Goes in hand with `tash_execute` - launches a command with arguments
// and forks out the arguments as child processes
int tash_launch(char **args)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    
    if (pid == 0)
    {
        // Child process (the arguments)
        if (execvp(args[0], args) == -1)
        {
            perror("tash");
        }
        exit(EXIT_FAILURE);

    } else if (pid < 0) {
        // Forks an error
        perror("tash");
    } else {
        // Parent process (the command)
        do 
        {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

// Takes a token and if it is valid, execute it
int tash_execute(char **args)
{    
  if (args[0] == NULL) {
    // An empty command was entered, so return a new line
    return 1;
  }

  //check if the entered command is in the builtin command list
  for (int i = 0; i < tash_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  // Execute the command & it's given args
  return tash_launch(args);
}

// Putting everything together to make the command loop
void tash_loop(void)
{
  char *line;
  char **args;
  int status;

  do {
    // The `$` shows up to know that you can input commands
    // and to say to the user "Hey, no process is in effect, so fire away!"
    printf("$ ");
    line = tash_read_line();
    args = tash_split_line(line);
    status = tash_execute(args);

    free(line);
    free(args);
  } while (status);
}

// `tash_loop` can act like a `main` function, but this is needed
// to load configs before the command loop THEN enter it
int main(int argc, char **argv, char **args)
{
    // Load configs from .tashrc, which is in the home directory
    // or where ever TASH is installed
    FILE *config_file, *new_config_file;
    char buf[TASH_RL_BUFSIZE];

// Default text that is outputted to .tashrc when the flie isn't found
const char *new_text = " !                      TASH Configuration File                    !\n \
! 		                                		  !\n \
!     Put in your commands here to run at the shell's startup      !\n \
!							 	   !\n \
!   Only single line comments are supported, and start with '!'   !\n \
\n \
\n \
! Display current time\n \
time\n \
\n \
! Show the current working folder\n \
cf";

    // Open the file
    config_file = fopen(".tashrc", "r");

    // Is the file there?
    if (config_file == NULL)
    {
        // Create file if none has been detected on the path 
        printf("No config file is found on the home directory, creating file...\n");

        new_config_file = fopen(".tashrc", "w");

        fprintf(new_config_file, "%s\n", new_text);
        fclose(new_config_file);

    } else {
        // Load the file and execute commands line by line and display them into the prompt
        // then go into the command prompt
        while (fgets(buf, sizeof(buf), config_file) != NULL)
        {  
            //printf("%s\n", buf); -- This will print out each command that is in .tashrc
            //                        then the corresponding output of that command below
            tash_execute(tash_split_line(buf));
        }
    }

    // Close the file stream after all the configs have been loaded
    fclose(config_file);


    // Run the command loop
    tash_loop();

    // Do shutdown or cleanup operations, if any, then exit
    return EXIT_SUCCESS;
}
