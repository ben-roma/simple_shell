#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * lire_commande - read a command
 * Return: a ligne.
**/
char *lire_commande(void)
{
	char *ligne = malloc(MAXLINE);
	size_t len;

	if (ligne == NULL)
	{
		perror("Erreur d'allocation de mémoire");
		exit(1);
	}

	if (fgets(ligne, MAXLINE, stdin) == NULL)
	{
		free(ligne);
		return (NULL);
	}

	len = strlen(ligne);
	if (len > 0 && ligne[len - 1] == '\n')
	{
		ligne[len - 1] = '\0';
	}
	return (ligne);
}

