#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - maid void
 * Return: 0 always
**/

int main(void)
{
	char *commande;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			afficher_invite();
		}
		commande = lire_commande();

		if (commande == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				printf("\n");
			}
			exit(0);
		}

		if (*commande != '\0')
		{
			executer_commande(commande);
		}
		free(commande);
	}
	return (0);
}
