#ifndef MHSHELL
#define MHSHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

extern char **environ;
int is_interactive(void);
int is_non_interactive(void);
char **comtokniz(char *command, char *delm);
void sighand(int jh);
void execute_command(char **arg);
void free_arguments(char **arg);

#endif
