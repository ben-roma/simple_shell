#include "simple_shell.h"
#include <ctype.h>
#include <string.h>

/**
 * trim - delete space
 * @str: xoxo
 * Return: str
**/

char *trim(char *str)
{
	char *fin;

	while (isspace((unsigned char)*str))
		str++;

	if (*str == 0)
		return (str);

	fin = str + strlen(str) - 1;
	while (fin > str && isspace((unsigned char)*fin))
		fin--;

	*(fin + 1) = 0;

	return (str);
}

