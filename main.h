#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

#define lsh_RL_BUFSIZE 1024
#define lsh_TOK_BUFSIZE 64
#define lsh_TOK_DELIM " \t\r\n\a"

void sig_handler(int signum);
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int lsh_env(char **args);
int lsh_history(char **args);
int lsh_launch(char **args);
char **split_input(char *line, char *delim);
char *add_command(char *command, char **PATH_splitted);
char **lsh_split_line(char *line);
char *lsh_gen(char *directory, char *command);
ssize_t read_textfile(const char *filename, size_t letters);
char *_getenv(char *env);
int lsh_execute(char **args);
void lsh_loop(void);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
size_t _strlen(const char *s);
char *lsh_read_line(void);
void free_array(char **str);



extern char **environ;

#endif
