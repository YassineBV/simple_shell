#include "myShlHead.h"
/**
 * is_interactive - command in interactive mode.
 *  @argh: :handle the command in interactive mode.
 * environ variable.
 *
 * Return: 0 on success.
 */
int is_interactive(char **argh)
{
	while (1)
	{
		int status = 0, rdgtl = 0;
		size_t len = 0;
		pid_t chidpid;
		char **arg = NULL, *command = NULL;

		write(STDOUT_FILENO, "#cisfun$ ", 9);
		rdgtl = getline(&command, &len, stdin);
		if (command == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			return (-1);
		}
		if (rdgtl == -1)
			free(command), exit(127);
		arg = comtokniz(command, " \n\t");
		if (arg == NULL)
			free_arguments(arg), free(command), exit(1);
		chidpid = fork();
		if (chidpid == -1)
			free_arguments(arg), exit(1);
		if (chidpid == 0)
		{
			if (arg[1] != NULL)
			{
				free_arguments(arg);
				perror(argh[0]);
				exit(1);
			}
			execute_command(arg, argh);
		}
		if (chidpid > 0)
			wait(&status);
		free_arguments(arg);
		free(command);
	}
	return (0);
}
