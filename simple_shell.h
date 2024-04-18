#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAXLINE 1024

extern char **environ;

char *trim(char *str);
void afficher_invite(void);
char *lire_commande(void);
void executer_commande(char *commande);
int handle_exit(char *commande);

#endif
