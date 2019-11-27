#include "shell.h"
/**
 * main - funcion de la shell
 * @ac: int
 * @av: point of point
 * Return: 1
 */
int main()
{
	char *buffer = NULL, *TokenTemporal = NULL, **TokenMain = NULL;
	size_t BUFFSIZE = 32, characters = 0;
	int i = 0, j = 0;

	while (1)
	{
		buffer = malloc(BUFFSIZE * sizeof(char));
		if (buffer == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
		}
		printf("HolbiPro $ ");
		characters = getline(&buffer, &BUFFSIZE, stdin);
		TokenMain = malloc(sizeof(char *) * BUFFSIZE);
		if (TokenMain == NULL)
			return (0);
		if (characters == (size_t)-1)
		{
			free(TokenMain);
			free(buffer);
			printf("\n");
			break;
		}
		TokenTemporal = _strtok(buffer, " ");
		i = 0;
		while (TokenTemporal != NULL)
		{
			TokenMain[i] = malloc((sizeof(char) * _strlen(TokenTemporal)) + 1);
			_strcpy(TokenMain[i], TokenTemporal);
			TokenTemporal = _strtok(NULL, " ");
			i++;
		}
		get_func(TokenMain[0], TokenMain);
		while (TokenMain[j] != NULL)
			j++;
		free_shell(TokenMain, j);
		free(buffer);
		}
		return (0);
}
