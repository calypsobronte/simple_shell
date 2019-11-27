#include "shell.h"
/**
 * exe_fun - function that executes the command sent to the shell
 * @Token: letter
 * @search: the command to be looked for
 * Return: 1
 */
int exe_fun(char **Token, char *search)
{
	pid_t child_pid;

	Token[0] = malloc(sizeof(char) * _strlen(search) + 1);
	_strcat(Token[0], search);
	if (access(search, X_OK | F_OK) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			execve(search, Token, NULL);
			return (0);
		}
		else
			waitpid(child_pid, NULL, 0);
	}
	else
		perror("./shell");
	return (1);
}
