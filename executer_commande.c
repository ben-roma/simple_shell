#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

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

	pid = fork();
	if (pid == -1)
	{
		perror("Erreur de fork");
		free(commande);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(commande, argv, environ) == -1)
		{
			fprintf(stderr, "%s: %s\n", commande, strerror(errno));
			free(commande);
			exit(127);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);

			if (exit_status != 0)
			{
				free(commande);
				exit(exit_status);
			}
		}
	}
	free(commande);
}
