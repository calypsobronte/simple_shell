#include "shell.h"
/**
 * main - funcion de la shell
 *
 * Return: 1
 */
int main(void)
{
	char *buffer = NULL, *TokenTemporal = NULL, **TokenMain = NULL;
	size_t BUFFSIZE = 80, characters;
	int i = 0, j = 0, k = 0;

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
		if (characters == (size_t)-1 || _strcmp(buffer, "exit\n") == 0)
		{
			k = 0;
			while (TokenMain[k] != NULL)
				k++;
			free_shell(TokenMain, k);
			free(buffer);
			break;
		}
		TokenTemporal = _strtok(buffer, " ");
		i = 0;
		while (TokenTemporal != NULL)
		{
			TokenMain[i] = malloc(sizeof(char) * (_strlen(TokenTemporal) + 1));
			if (TokenMain[i] == NULL)
			{
				free(buffer);
				free(TokenMain);
				perror("Error");
				return ('\0');
			}
			_strcpy(TokenMain[i], TokenTemporal);
			TokenTemporal = _strtok(NULL, " ");
			i++;
		}
		get_func(TokenMain[0], TokenMain); /*problem*/
		while (TokenMain[j] != NULL)
			j++;
		free_shell(TokenMain, j);
		free(buffer);
		}
		free(TokenTemporal);
		return (0);
}
