#ifndef MHSHELL
#define MHSHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

extern char **environ;
int is_interactive(char **argh);
int is_non_interactive(void);
char **comtokniz(char *command, char *delm);
void sighand(int jh);
void execute_command(char **arg, char **argh);
void free_arguments(char **arg);
char *_strdup(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

#endif
