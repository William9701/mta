#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
        int i;
        if (argc > 1)
        {
                for (i = 1; i < argc; i++)
                {
                        execute_command(argv[i]);
                }
        }
        else
        {
                run_shell();
        }
        return 0;
}
void run_shell() 
{
    char *line = NULL;
    size_t buffer = 0;
    ssize_t get;
    pid_t pid;

    while (1) {
        if (isatty(fileno(stdin))) {
            // Interactive Mode
            write(STDOUT_FILENO, "$ ", 2);

	    free(line);
	    line = NULL;
	    buffer = 0;
            get = getline(&line, &buffer, stdin);
            if (get == -1) {
                if (feof(stdin)) {
                    write(STDOUT_FILENO, "\n", 2); // Print a newline before exiting on Ctrl+D (end of file).
                    break;
                } else {
                    perror("getline");
                    continue;
                }
            }
            line[get - 1] = '\0';
        } else {
            // Non-Interactive Mode
            if (getline(&line, &buffer, stdin) == -1) {
                break; // Exit the loop when reaching end-of-file in non-interactive mode.
            }
            line[strcspn(line, "\n")] = '\0'; // Remove the trailing newline character.
        }

	_fork(line);
    }
}
