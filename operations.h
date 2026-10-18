#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    int solde;
}Compte;
typedef struct{
    char nom[20];
    Compte comptes[5];
}Client;
void afficher_menu(void);

int chercher_compte_par_id(Client *c, int nb, int id);

void debiter_compte(Client *c, int index, int debit);

void crediter_compte(Client *c, int index, int credit);

void afficher_compte(Client *c, int index);

void creer_compte(Client *c, int *prochain_id, int *nb);

void virement(Client *c, int index_A, int index_B, int montant);

void supprimer_compte(Client *c, int index, int *nb);

void afficher_tout_comptes(Client *c, int *nb);

#endif
