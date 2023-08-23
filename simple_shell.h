#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define MAXLINE 1024

extern char **environ;

void afficher_invite(void);
char *lire_commande(void);
void executer_commande(char *commande);

#endif
