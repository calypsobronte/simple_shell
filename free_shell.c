#include "shell.h"
/**
 * free_shell - funcion de para liberar en el main
 * @TokenMain: char
 * @size: size del argumento
 */
void free_shell(char **TokenMain, int size)
{
int i = 0;
for (i = 0; i < size; i++)
{
if (TokenMain[i] != NULL)
	free(TokenMain[i]);
}
free(TokenMain);
}
