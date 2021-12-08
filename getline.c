#include "main.h"
/**
*_getline - read the input
*Return: buff
*/
char *_getline()
{
int i, buffsize = 1024, rd;
char b = 0;
char *buff = malloc(sizeof(char) * buffsize);

if (buff == NULL)
return (NULL);
for (i = 0; b != EOF && b != '\n'; i++)
{
fflush(stdin);
rd = read(STDIN_FILENO, &b, 1);
if (rd == 0)
{
free(buff);
exit(EXIT_SUCCESS);
}
buff[i] = b;
if (buff[0] == '\n')
return (NULL);
if (i >= buffsize)
{
buff = _realloc(buff, buffsize, buffsize + 1024);
buffsize += 1024;
if (buff == NULL)
return (NULL);
}
}
buff[i] = '\0';
for (i = 0; buff[i] != '\0'; i++)
{
if (buff[i] == '#')
{
buff[i] = '\0';
break;
}
}
return (buff);
}
