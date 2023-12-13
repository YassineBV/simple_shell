#include "myShlHead.h"
/**
 * is_non_interactive - Command on non-interactive mode.
 *
 * Return: 0 on success.
 */
int is_non_interactive(void)
{
	char **arg = NULL, *command = NULL;
	size_t len = 0;
	int redexc = 0, rdgtl = 0, status;
	pid_t child;

	while ((rdgtl = getline(&command, &len, stdin)) != -1)
	{
		if (command[rdgtl - 1] == '\n')
		{
			command[rdgtl - 1] = '\0';
		}
		arg = comtokniz(command, " \n\t");
		if (arg == NULL)
		{
			free(command);
			exit(1);
		}
		free(command);
		child = fork();
		if (child == -1)
			free_arguments(arg), exit(1);
		if (child == 0)
		{
			redexc = execve(arg[0], arg, environ);
			if (redexc == -1)
				free_arguments(arg), exit(1);
		}
		if (child > 0)
			wait(&status);
	}
	return (0);
}
