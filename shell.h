#ifndef simple_shell
#define simple_shell

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int ac, char **av);
void free_shell(char **TokenMain, int size);
int get_func(char *TokenMain, char **Token);

char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
char *_strtok(char *str, const char *delimitador);
int exe_fun(char **Token, char *search);
#endif /* libraries Simple Shell Holberton */
