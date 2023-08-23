#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - maid void
 * Return: 0 always
**/

int main(void)
{
	char *commande;

	while (1)
	{
		afficher_invite();
		commande = lire_commande();

		if (commande == NULL)
		{
			printf("\n");
			exit(0);
		}

		executer_commande(commande);
		free(commande);
	}
	return (0);
}
