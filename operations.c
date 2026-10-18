#include "operations.h"
#include <string.h>

void afficher_menu(void)
{
    printf(" \n ------MENU------ \n");
    printf("1- Debiter \n");
    printf("2- Crediter \n");
    printf("3- Afficher un compte \n");
    printf("4- Creer un compte \n");
    printf("5- Virement \n");
    printf("6- Supprimer un compte \n");
    printf("7- Afficher tout les comptes \n");
    printf("0- Quitter \n");
}
int chercher_compte_par_id(Client *c, int nb, int id)
{
    for(int i = 0; i < nb; i++){
        if(c->comptes[i].id == id)
            return i;   // index du compte trouvé
    }
    return -1; // pas trouvé
}

void debiter_compte(Client *c, int index, int debit)
{
    if(c->comptes[index].solde >= debit){
        c->comptes[index].solde -= debit;
        printf("Operation reussite : votre nouveau solde est %d",c->comptes[index].solde);
    } else{
        printf("Solde insuffisant \n");
    }
}
void crediter_compte(Client *c, int index, int credit)
{
    c->comptes[index].solde += credit;
    printf("Operation reussite : votre nouveau solde est %d",c->comptes[index].solde);
}
void afficher_compte(Client *c, int index)
{
    printf("Compte ID=%d | Solde=%d\n", c->comptes[index].id, c->comptes[index].solde);
}

void creer_compte(Client *c, int *prochain_id, int *nb)
{
    if(*nb >= 5) {
        printf("Nombre max de comptes atteint.\n");
        return;
    }

    printf("Entrez le solde du nouveau compte : ");
    scanf("%d", &c->comptes[*nb].solde);

    c->comptes[*nb].id = *prochain_id;

    printf("Compte cree avec succes ! ID = %d\n", c->comptes[*nb].id);

    (*nb)++;
    (*prochain_id)++;
}

void virement(Client *c, int index_A, int index_B, int montant)
{
    c->comptes[index_A].solde -= montant;
    c->comptes[index_B].solde += montant;
}

void supprimer_compte(Client *c, int index, int *nb)
{
    for(int i = index; i <*nb - 1; i++){
        c->comptes[i] = c->comptes[i + 1];
    }
    (*nb)--; // on réduit le nombre de comptes

}
void afficher_tout_comptes(Client *c, int *nb)
{
    printf("Nom : %s \n", c->nom);
    for(int i=0; i<*nb; i++){
        printf(" ID : %d --> Solde : %d \n", c->comptes[i].id, c->comptes[i].solde);
    }
}
