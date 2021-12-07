#include "main.h"
/**
 * lsh_execute - execute builtins
 * @args: command entered
 * Return: the executing of one of the builtins
 */

int lsh_execute(char **args)
{
        int i;

        int (*function_func[])(char **) = {
                &lsh_cd,
                &lsh_help,
                &lsh_exit,
                &lsh_env,
};

char *function_str[] = {
        "cd",
        "help",
        "exit",
        "env",
};


        if (args[0] == NULL)
{
        return (1);
}
        for (i = 0; i <= 4; i++)
{
        if (strcmp(args[0], function_str[i]) == 0)
        {
                return ((*function_func[i])(args));
        }

}
        return (lsh_launch(args));
}
