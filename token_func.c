#include "shell.h"
/**
 * cmd_tokenizer - Tokenizes the command entered and their flags
 *
 * @buffer: buffer of the command entered.
 * @TokenTemporal: Temporal var to store the tokenized items.
 * @TokenMain: Principal entry of the orders, where the commands are stored.
 *
 * Return: 0 on success.
 */

int cmd_tokenizer(char *buffer, char *TokenTemporal, char **TokenMain)
{
int j = 0, i = 0;

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
free(TokenTemporal);
return (0);
}
