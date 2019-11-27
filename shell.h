#ifndef simple_shell
#define simple_shell

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <signal.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main();
void free_shell(char **TokenMain, int size);
int get_func(char *TokenMain, char **Token);

char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
char *_strtok(char *str, const char *delimitador);
int exe_fun(char **Token, char *search);

/*Function to use with printf */
/**
 * struct typeprint - create libraries
 * @typec: char
 * @fun: point void of lista
 * Description: struct
 */
typedef struct typeprint
{
	char typec;
	int (*fun)(va_list lista);
} typedate;
/*Second function for _printf */
int opFunction(int cont, va_list list, typedate tipos[],
const char *format);
int printUnk(int i, int spaces, const char *format, int band);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
int _printf(const char *format, ...);
int printString(va_list lista);
int printChar(va_list lista);
int printDecimal(va_list lista);
int printInteger(va_list lista);
int printBinary(va_list lista);
int printUnsigned(va_list lista);
int printUnsignedDigit(unsigned int num, int *cont);
int printOctal(va_list lista);
int printDigitOctal(unsigned int num, int *cont);
char *_littleBuffer(int size);
#endif /* libraries Simple Shell Holberton */
