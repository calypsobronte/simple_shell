#include "shell.h"
/**
 * get_func - searches for the function with flags and options
 * @TokenMain: char
 * @Token: token
 * Return: 1
 */

int get_func(char *TokenMain, char **Token)
{
	char *search = NULL;
	int i = 0;

	while (Token[i] != NULL)
		i++;
	Token[i] = NULL;
	if (i == 1)
		TokenMain[_strlen(TokenMain) - 1] = '\0';
	else if (i > 1)
		Token[i - 1][_strlen(Token[i - 1]) - 1] = '\0';
	if (TokenMain[0] == '/' || TokenMain[0] == '.')
	{
		search = malloc(sizeof(char) * _strlen(TokenMain) + 1);
		_strcpy(search, TokenMain);
	}
	else
	{
		search = malloc(sizeof(char) * _strlen(TokenMain) + 6);
		_strcpy(search, "/bin/");
		_strcat(search, TokenMain);
	}
	exe_fun(Token, search);
	if (search != NULL)
		free(search);
	free(TokenMain);
	return (1);
}
