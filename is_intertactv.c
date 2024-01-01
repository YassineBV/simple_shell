#include "myShlHead.h"
/**
 * _strcpy - entry of the program
 *
 *@dest: copies the string pointed to by src
 *@src: including the terminating null byte
 *
 *Return: the pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strlen - entry of the program
 *
 *@s: function that returns the length of a string
 *
 *Return: Alway 0
*/
int _strlen(char *s)
{
	int pr;

	for (pr = 0; *s != '\0'; s++)
		pr++;

	return (pr);
}
/**
 * _strdup - function that returns a pointer
 *
 *@str: to a newly allocated space in memory
 *
 *Return: returns a pointer to the duplicated string
*/
char *_strdup(char *str)
{
	unsigned int n;
	unsigned int i;
	char *newstr;

	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		n = strlen(str) + 1;
		newstr = (char *)malloc(n * sizeof(char));
		if (newstr == NULL)
		{

			return (NULL);
		}
		else
		{
			for (i = 0; i < n; i++)
			{
				newstr[i] = str[i];
			}

		}
		return (newstr);
	}

	return (newstr);
}

/**
 * is_interactive - command in interactive mode.
 *  @argh: :handle the command in interactive mode.
 * environ variable.
 *
 * Return: 0 on success.
 */
int is_interactive(char **argh)
{
	int status = 0;

	while (1)
	{
		int rdgtl = 0;
		size_t len = 0;
		pid_t chidpid;
		char **arg = NULL, *command = NULL;

		write(STDOUT_FILENO, "$ ", 2);
		rdgtl = getline(&command, &len, stdin);
		if (command == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			return (-1);
		}
		if (rdgtl == -1){
			free(command);
			perror("getline"), exit(EXIT_FAILURE);
		}
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
		if (chidpid > 0){
			wait(&status);
		free_arguments(arg);
		free(command);}
	}
	return (WEXITSTATUS(status));
}
