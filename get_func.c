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
	if (i == 1)
		TokenMain[_strlen(TokenMain) - 1] = '\0';
	else if (i > 1)
		Token[i - 1][_strlen(Token[i - 1]) - 1] = '\0';
	Token[i] = NULL;
	if (TokenMain[0] == '/' || TokenMain[0] == '.')
	{
		search = malloc(sizeof(char) * _strlen(TokenMain) + 1);
		_strcpy(search, TokenMain);
	}
	else
	{
		search = malloc((sizeof(char) * 6)  + _strlen(TokenMain));
		_strcpy(search, "/bin/");
		_strcat(search, TokenMain);
	}
	free(TokenMain);
	Token[0] = malloc(sizeof(char) * _strlen(search) + 1);
	if (Token[0] == NULL)
	{
		perror("Unable memory llocation");
		exit(1);
	}
	_strcpy(Token[0], search);
	free(search);
	exe_fun(Token, Token[0]);
	return (1);
}
