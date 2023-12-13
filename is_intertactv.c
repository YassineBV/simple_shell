#include "myShlHead.h"
/**
 * is_interactive - command in interactive mode.
 *  handle the command in interactive mode.
 *
 * Return: 0 on success.
 */
int is_interactive(void)
{
	int status = 0, rdgtl = 0;
	char **arg = NULL, *command = NULL;

	while (1)
	{
		size_t len = 0;
		pid_t chidpid;

		arg = NULL, command = NULL;
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		rdgtl = getline(&command, &len, stdin);
		if (command == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			return (-1);
		}
		if (rdgtl == -1)
			free(command),  exit(1);
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
				write(STDOUT_FILENO, "./shell: No such file or directory\n", 36);
				exit(1);
			}
			execute_command(arg);
		}
		if (chidpid > 0)
			wait(&status);
		free_arguments(arg);
		free(command);
	}
	return (0);
}
