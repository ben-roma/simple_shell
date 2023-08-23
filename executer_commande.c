#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * executer_commande - to execut a command
 * @commande: the command input
 * Return: no return
**/

void executer_commande(char *commande)
{
	pid_t pid;
	int status;
	char *argv[2];

	argv[0] = commande;
	argv[1] = NULL;
	pid = fork();
	if (pid  == -1)
	{
		perror("Erreur de fork");
		exit(1);
	}

	if (pid == 0)
	{
		if (execve(commande, argv, environ) == -1)
		{
			fprintf(stderr, "./shell: No such file or directory\n");
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
}
