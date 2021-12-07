#include "main.h"

/**
 * lsh_read_line - reads the command entered
 * Return: the command readed
 */
char *lsh_read_line(void)
{
  {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, stdin);
    if (read == -1)
    {
      free(line);
      perror("readline");
      exit(EXIT_SUCCESS);
    }

    return (line);
  }
}

/**
 * lsh_split_line - splites the command into tokens
 * @line: the command entere dby the user
 * Return: tokens
 */

char **lsh_split_line(char *line)
{
  int bufsize = lsh_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char *));
  char *token;

  if (!tokens)
  {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, lsh_TOK_DELIM);
  while (token != NULL)
  {
    tokens[position] = token;
    position++;

    if (position >= bufsize)
    {
      bufsize += lsh_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char *));
      if (!tokens)
      {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
    token = strtok(NULL, lsh_TOK_DELIM);
  }

  tokens[position] = NULL;
  return (tokens);
}
