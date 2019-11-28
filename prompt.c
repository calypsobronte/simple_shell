#include "shell.h"
/**
 * main - funcion de la shell
 *
 * Return: 1
 */
int main(void)
{
	char *buffer = NULL, *TokenTemporal = NULL, **TokenMain = NULL;
	size_t BUFFSIZE = 32, characters;
	int k = 0;

	while (1)
	{
		buffer = malloc(BUFFSIZE * sizeof(char));
		if (buffer == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
		}
		TokenMain = malloc(sizeof(char) * 80);
		if (TokenMain == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
		}
		if (isatty(STDIN_FILENO) == 1)
			_printf("HolbiPro $ ");
		characters = getline(&buffer, &BUFFSIZE, stdin);
		if (characters == (size_t)-1)
		{
			k = 0;
			while (TokenMain[k] != NULL)
				k++;
			free_shell(TokenMain, k);
			free(buffer);
			break;
		}
		else if (_strcmp(buffer, "exit\n") == 0)
		{
			return (2);
		}
		else if (_strcmp(buffer, "env\n") == 0)
			return (_printenv());
		TokenTemporal = _strtok(buffer, " ");
		cmd_tokenizer(buffer, TokenTemporal, TokenMain);
	}
	return (0);
}

/**
 * _printenv - funcion env
 *
 * Return: 0
 */
int _printenv(void)
{
	int i = 1;
	char *s = *environ;

	for (; s; i++)
	{
		printf("%s\n", s);
		s = *(environ + i);
	}

	return (0);
}
