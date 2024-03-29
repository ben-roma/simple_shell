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
	char *trimmed_ligne;
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

	trimmed_ligne = trim(ligne);

	if (*trimmed_ligne == '\0')
	{
		free(ligne);
		return (NULL);
	}

	if (trimmed_ligne != ligne)
	{
		strcpy(ligne, trimmed_ligne);
	}
	return (ligne);
}

