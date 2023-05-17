#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


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
    char targetChar = '/';


    while (1) {
        if (isatty(fileno(stdin))) 
	{
            // Interactive Mode
            write(STDOUT_FILENO, "$ ", 2);
            get = getline(&line, &buffer, stdin);
            if (get == -1) {
                if (feof(stdin)) {
                    write(STDOUT_FILENO,"\n", 2); // Print a newline before exiting on Ctrl+D (end of file).
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

        if (strchr(line, targetChar) != NULL)
	{
	if (access(line, X_OK) == 0)
	{
	pid = fork();
        if (pid == -1) 
	{
            perror("fork");
            continue;
        }

        if (pid == 0) 
	{
            // Child process
            execute_command(line);
            exit(1);
        } else {
            // Parent process
            wait(NULL);
        }
	}
	else
	{
		perror("command deos not exist");
	}
	}
	else
	{
        char buffer[256];
        FILE* fp = popen("which <line>", "r");
        if (fp == NULL) 
	{
        perror("popen");
        return;
	}

        if (fgets(buffer, sizeof(buffer), fp) == NULL) 
	{
        pclose(fp);
        return;
	}

        pclose(fp);
        buffer[strcspn(buffer, "\n")] = '\0';
        line = strdup(buffer);
        if (access(line, X_OK) == 0)
        {
        pid = fork();
        if (pid == -1) 
	{
            perror("fork");
            continue;
        }

        if (pid == 0) 
	{
            // Child process
            execute_command(line);
            exit(1);
        } 
	else 
	{
            // Parent process
            wait(NULL);
        }
        }
        else
        {
                perror("command deos not exist");
        }
	}
    }

    free(line);
}
