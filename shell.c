#include "myShlHead.h"
/**
 * comtokniz - Tokenizes a command string into words.
 * @command: The command string.
 * @delm: The delimiter.
 *
 * Return: Array of arguments.
 */
char **comtokniz(char *command, char *delm)
{
	char **argv;
	char *copycom, *token, *cop2;
	int tokcount = 0, i = 0;

	copycom = strdup(command);
	if (copycom == NULL)
	{
		free(copycom);
		return (NULL);
	}
	cop2 = strdup(command);
	if (cop2 == NULL)
	{
		free(cop2);
		return (NULL);
	}
	token = strtok(copycom, delm);
	while (token != NULL)
	{
		tokcount++;
		token = strtok(NULL, delm);
	}
	argv = malloc((tokcount + 1) * sizeof(char *));
	if (argv == NULL)
		return (NULL);
	token = strtok(cop2, delm);
	while (token != NULL)
	{
		argv[i] = malloc(strlen(token)  + 1);
		strcpy(argv[i], token);
		token = strtok(NULL, delm);
		i++;
	}
	argv[i] = NULL;
	free(cop2);
	free(copycom);
	return (argv);
}
/**
 * sighand - Handles the exit signal.
 * @jh: Signal number.
 */
void sighand(int jh)
{
	(void) jh;
	write(STDOUT_FILENO, "\n", 1);
	exit(0);
}
/**
 * free_arguments - free the memory allocated for arguments.
 * @arg: arguments to free.
 */
void free_arguments(char **arg)
{
	int j = 0;

	while (arg[j])
	{
		free(arg[j]);
		j++;
	}
	free(arg);
}
/**
 * execute_command - Executes the command.
 * @arg: Array of arguments for the command.
 * environ variable.
 * @argh: name of the program.
 */
void execute_command(char **arg, char **argh)
{
	int j = 0;
	int readexc = execve(arg[0], arg, environ);

	if (readexc == -1)
	{
		perror(argh[0]);
		while (arg[j])
		{
			free(arg[j]);
			j++;
		}
		free(arg);
		exit(1);
	}
}

/**
 * main - Entry point for the shell.
 * Checks if shell is interactive or non-interactive
 *@argh: shell arguments
 *@ac: number of arguments
 *environ variable.
 * Return: Always returns 0.
 */
int main(int ac, char **argh)
{
	(void) ac;

	if (isatty(STDIN_FILENO))

		is_interactive(argh);

	else
		is_non_interactive();

	return (0);
}
