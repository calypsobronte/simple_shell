#ifndef simple_shell
#define simple_shell

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <limits.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

int main(int ac, char **av)
void free_shell(char **TokenMain, int size);
int get_func(char * TokenMain, char **Token);

int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strtok(char *str, const char *delimitador);
#endif /* libraries Simple Shell Holberton */
