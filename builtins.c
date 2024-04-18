#include "simple_shell.h"

/**
* handle_exit - Exits the shell
* @commande: Parsed command
* Return: 1 if the shell should continue running, 0 if it should exit
**/
int handle_exit(char *commande)
{
	if (strcmp(commande, "exit") == 0)
	{
		free(commande);
		exit(0);
	}
	return (1);
}
