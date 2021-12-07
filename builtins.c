#include "main.h"
/**
 * lsh_cd - function that handles the cd command
 * @args : command passed by the user
 * Return: the designed directory
 */
int lsh_cd(char **args)
{
        int path = 1;
        char buf[4096];
        char *old_path = NULL;
        char *curr_path = NULL;

        if (args[2] != NULL)
                perror("error");
        else
        {
                if (args[1] != NULL)
                {
                        if (strcmp(args[1], "-") == 0)
                        {
                                if (old_path == NULL)
                                {
                                        path = chdir(getenv("HOME"));
                                        if (path != 0)
                                                perror("Error: ");
                                }
                                else
                                {
                                        path = chdir(old_path);
                                        if (path != 0)
                                                perror("error");
                                }
                        }
                        else
                        {
                                old_path = getcwd(buf, sizeof(buf));
                                curr_path = args[1];
                                path = chdir(curr_path);
                                if (path != 0)
                                        perror("error");
                        }
                }
                if (args[1] == NULL)
                {
                        path = chdir(getenv("HOME"));
                        if (path != 0)
                                perror("Error");
                }
        }
        return (1);
}


/**
 * lsh_help - function that prints the help for a command
 * @args: the user input
 * Return: print the help command
 *
 */

int lsh_help(char **args)
{
        if (strcmp(args[0], "help") == 0 && args[1] == NULL)
        {
                read_textfile("help", 6368);
                return (1);
        }
        if (args[2] == NULL)
        {
                if (strcmp(args[1], "cd") == 0)
                        read_textfile("cd", 1620);
                else if (strcmp(args[1], "exit") == 0)
                        read_textfile("exit", 147);
                else if (strcmp(args[1], "env") == 0)
                        read_textfile("env", 999);
                else if (strcmp(args[1], "help") == 0)
                        read_textfile("help_help", 599);
                else
                {
                        write(1, "hsh: ", 5);
                        write(1, args[0], strlen(args[0]));
                        write(1, ": no help topics match `", 24);
                        write(1, args[1], strlen(args[1]));
                        write(1, "\'\n", 2);
                }
        }
        else
        {
                write(1, "hsh: ", 5);
                write(1, args[0], strlen(args[0]));
                write(1, ": no help topics match `", 24);
                write(1, args[1], strlen(args[1]));
                write(1, "\'\n", 2);
        }
        return (1);
}

/**
 * lsh_env - function prints env variable
 * @args : command passed by the user
 * Return: print the enviroment variable
 */

int lsh_env(__attribute__((unused)) char **args)
{
        int i;
        int len;

        for (i = 0; environ[i] != NULL; i++)
        {
                len = strlen(environ[i]);
                write(1, environ[i], len);
                write(1, "\n", 1);
        }
        return (127);
}

/**
 * lsh_exit - exit command
 * @args : command passed by the user
 * Return: exit command
 */
int lsh_exit(__attribute__((unused)) char **args)
{
        exit(98);
}
