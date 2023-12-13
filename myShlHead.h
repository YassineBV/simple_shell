#ifndef MHSHELL
#define MHSHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

/*extern char **environ;*/
int is_interactive(char **argh, char **env);
int is_non_interactive(char **env);
char **comtokniz(char *command, char *delm);
void sighand(int jh);
void execute_command(char **arg, char **argh, char **env);
void free_arguments(char **arg);

#endif
