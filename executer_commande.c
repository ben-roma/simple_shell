#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
* executer_commande - to execute a command
* @commande: the command input
* Return: no return
**/
void executer_commande(char *commande)
{
	pid_t pid;
	int status;
	char *argv[2];

	if (strcmp(commande, "exit") == 0)
	{
		free(commande);
		exit(0);
	}

	argv[0] = commande;
	argv[1] = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror("Erreur de fork");
		free(commande);
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		if (execve(commande, argv, environ) == -1)
		{
			perror(commande);
			free(commande);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

		free(commande);
	}
}
