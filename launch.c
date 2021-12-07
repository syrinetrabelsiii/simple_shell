#include "main.h"

/**
* _getenv  - function that return an env variable
* @env: the wanted environ variable
* Return: the environ variable
*/
char *_getenv(char *env)
{
        char **envi_var;
        size_t i;
        size_t j;

        envi_var = environ;
        for (i = 0; envi_var[i] != NULL; i++)
        {
                for (j = 0; j < strlen(env); j++)
                {
                        if (env[j] != envi_var[i][j])
                        {
                                break;
                        }
                        if (j == strlen(env) - 1)
                        {
                                return (envi_var[i] + strlen(env));
                        }
                }
        }
        return (NULL);
}

/**
*lsh_launch - executes a program and wait for it to terminate.
*@args : the command passed by the user
*Return: 1 if the shell should continue running, 0 if it should terminate
*/
int lsh_launch(char **args)
{
        pid_t pid;
        char *PATH = NULL;
        char **PATH_splitted;
        char *program_path;
        int wstatus;

        if (access(args[0], X_OK) == 0)
        {       pid = fork();
                if (pid ==  0)
                {
                        if (execve(args[0], args, NULL) == -1)
                        {
                                perror("no excution");
                                exit(EXIT_FAILURE);
                        }
                }
                waitpid(pid, &wstatus, 0);
                if (WIFEXITED(wstatus))
                {
                        return (127);
                }
                return(0);
}
        else
        {
        PATH = getenv("PATH");
        PATH_splitted = split_input(PATH, ":");
        program_path = add_command(args[0], PATH_splitted);
                if (access(program_path, X_OK) == 0)
                {
                        pid = fork();
                                if (pid == 0)
                                        {
                                                if (execve(program_path, args, NULL) == -1)
                                                        {
                                                                perror("no excution");
                                                                exit(EXIT_FAILURE);
                                                        }
                                        }
                        waitpid(pid, &wstatus, 0);
                        if (WIFEXITED(wstatus))
                                {
                                        return (127);
                                }
                }
                else
                {
                        perror("does not work, Retry");
                        free_array(PATH_splitted);
                        return (127);
                }
        return (0);
        }

}


/**
* split_input - function that splits string into array of string
* @line: string being passed by user
* @delim: to separeate the str by.
* Return:       array that hold the strings splitted
*                       this splits based on sent delimiters
*/
char **split_input(char *line, char *delim)
{
        int i;
        char **words_array;
        char *word;
        char *duplicated;
        int buffsize = 1024;

        duplicated = strdup(line);
        words_array = malloc(sizeof(char *) * buffsize);
        if (words_array == NULL)
        {
                perror("Malloc error\n");
                free_array(words_array);
                exit(98);
        }
        word = strtok(duplicated, delim);
        for (i = 0; word != NULL; i++)
{
                words_array[i] = strdup(word);
                word = strtok(NULL, delim);
        }
        words_array[i] = NULL;
        free(duplicated);
        return (words_array);
}



/**
 * add_command - check if program exists
 * @command: input taken from user.
 * @PATH_splitted: PATH env variable splitted by ':'.
 * Return: the result if the program exists or NULL
*/

char *add_command(char *command, char **PATH_splitted)
{
        char *final_lsh = NULL;
        int i = 0;
        int exists_program = 0;
        struct stat st;

        while (PATH_splitted[i] != NULL)
        {
                final_lsh = lsh_gen(PATH_splitted[i], command);
                i++;
                exists_program = stat(final_lsh, &st);
                if (exists_program == 0)
                {
                        free_array(PATH_splitted);
                        return (final_lsh);
                }
                else
                {
                        free(final_lsh);
                }
        }
        return (NULL);
}

/**
 * lsh_gen - concatenate every directory with command
 * @directory: directory from PATH
 * @command: user command.
 * Return: directory + command
*/
char *lsh_gen(char *directory, char *command)
{
        int i = 0;
        int j = 0;
        int command_len = 0;
        int directory_len = 0;
        int total_len = 0;
        char *final_lsh = NULL;

        command_len = strlen(command);
        directory_len = strlen(directory);
        total_len = directory_len + command_len + 2;
final_lsh = malloc(sizeof(char) * total_len);
        if (final_lsh == NULL)
        {
                perror("Malloc error\n");
                free(final_lsh);
                exit(98);
        }
        while (j < total_len)
        {
                for (i = 0; i <= directory_len && directory[i] != '\0'; i++)
                {
                        final_lsh[i] = directory[i];
                        j++;
                }
                final_lsh[j] = '/';
                j++;
                for (i = 0; i <= command_len; i++)
                {
                        final_lsh[j] = command[i];
                        j++;
                }
        }
        return (final_lsh);
}