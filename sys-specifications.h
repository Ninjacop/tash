// Getting the current working directory is different from
// UNIX and Windows OSes, so detect the OS and load the corresponding
// library and change a function name
#ifdef WINDOWS
#include <direct.h>
#define GetPWD _getcwd
#else
#include <unistd.h>
#define GetPWD getcwd
#endif

// Define the buffer size of the terminal
#define TASH_RL_BUFSIZE 1024
#define TASH_TOK_BUFSIZE 64

// Define characters that can be ommited from parsing
#define TASH_TOK_DELIM " \t\r\n\a"

// Define the current TASH version
#define VERSION_NO "0.1.1"


