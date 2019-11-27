#include "shell.h"
/**
 * _strcat - function that concatena two strings
 * @dest: leeter
 * @src: letter
 * Return: dest of string
 */
char *_strcat(char *dest, char *src)
{
	int str_len_destino = _strlen(dest);
	int str_len_src = _strlen(src);
	int str_len_maximo = str_len_destino + str_len_src - 1;
	int i;
	int cont = 0;
	for (i = str_len_destino; i <= str_len_maximo; i++)
	{
		dest[i] = src[cont];
		cont++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcpy - copy of string
 * @dest: string
 * @src: string
 * Return: dest a copy
 */
char *_strcpy(char *dest, char *src)
{
int cont_words;
for (cont_words = 0; src[cont_words] != 0; cont_words++)
dest[cont_words] = src[cont_words];
dest[cont_words] = 0;
return (dest);
}
/**
 * _strlen - counts length of a string
 * @str: - letter string
 * Return: number of string
 */
int _strlen(char *str)
{
char *point = str;
size_t _string;
_string = 0;
if (str == NULL)
	return (_string);
while (*point++ != '\0')
	_string++;
return (_string);
}
/**
  * _strtok - tokenizes a string
  * @str: string to tokenize
  * @delimitador: string that contains the delimitadoriters
  * Return: pointer to position in string of a null terminated word.
  */
char *_strtok(char *str, const char *delimitador)
{
	static char *run_string, *end_string, *end;
	unsigned int i, j;
	int words = 0;

	if (str == NULL)
	{
		if (run_string == NULL || end == NULL)
			return (NULL);
		str = end + 1;
	}
	else
		end_string = str + _strlen(str);
	for (i = 0; str + i < end_string; i++)
	{
		for (j = 0; delimitador != NULL && delimitador[j] != '\0'; j++)
		{
			if (str[i] == delimitador[j])
			{
				if (words == 1)
				{
					str[i] = '\0';
					end = str + i;
					return (run_string);
				}
				break;
			}
		}
		if (delimitador[j] == '\0' && words == 0)
		{
			words = 1;
			run_string = str + i;
		}
	}
	end = NULL;
	if (words == 1)
		return (run_string);
	return (NULL);
}
