#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main()
{
    int choix, credit, debit;
    int id, index;
    int prochain_id = 101;
    int nb = 0; // nb : nombres de comptes créés
    Client c[3];
    int nb_clients =0;
    printf("Saississez votre nom \n");
    scanf("%s", c->nom);
    do{
    afficher_menu();
    printf("Votre choix : ");
    scanf("%d",&choix);
    switch(choix){
    case 1 :
        if(nb == 0){
                printf("Aucun compte. Creez un compte d'abord.\n");
                break;
        }

        printf("Entrez l'id du compte a debiter :");
        scanf("%d",&id);
        index = chercher_compte_par_id(&c, nb, id);

        if(index == -1){
        printf("Compte introuvable.\n");
        break;
        }
        printf("Montant a debiter : ");
        scanf("%d",&debit);
        debiter_compte(&c, index, debit);
        break;
    case 2 :
        if(nb == 0){
                printf("Aucun compte. Creez un compte d'abord.\n");
                break;
        }

        printf("Entrez l'id du compte a crediter :");
        scanf("%d",&id);
        index = chercher_compte_par_id(&c, nb, id);

        if(index == -1){
        printf("Compte introuvable.\n");
        break;
        }
        printf("Montant a crediter : ");
        scanf("%d",&credit);
        crediter_compte(&c, index, credit);
        break;
   case 3: {

    if(nb == 0){
        printf("Aucun compte.\n");
        break;
    }

    printf("Entrez l'ID du compte a afficher : ");
    scanf("%d", &id);

    index = chercher_compte_par_id(&c, nb, id);

    if(index == -1){
        printf("Compte introuvable.\n");
    } else {
        afficher_compte(&c, index);
    }
    break;
}
    case 4 :
        creer_compte(&c, &prochain_id, &nb);
        break;

    case 5 :
        if(nb < 2   ){
        printf("Pas de virement possible : vous avez besoin d'au moins 2 comptes");
        break;
        }
        int id_A, id_B, montant;
        printf("Entrez l'ID du compte source : ");
        scanf("%d", &id_A);

        int index_A = chercher_compte_par_id(&c, nb, id_A);

        printf("Entrez l'ID du compte destinataire : ");
        scanf("%d", &id_B);

        int index_B = chercher_compte_par_id(&c, nb, id_B);
        if(id_A == id_B){
            printf("Transaction impossible : meme compte !\n");
            break;
        }

        if(index_A == -1 || index_B == -1){
            printf("Compte introuvable.\n");
            break;
        }

        printf(" Montant a transferer ? ");
        scanf("%d",&montant);
        if(montant <= 0 || montant >= c->comptes[index_A].solde){
            printf("Montant invalide !\n");
            break;
        }
        virement(&c, index_A, index_B, montant );
        printf("Virement effectue \n");
        printf("Le solde du compte [%d] est %d \n",id_A,c->comptes[index_A].solde);
        printf("Le solde du compte [%d] est %d \n",id_B,c->comptes[index_B].solde);
        break;

    case 6 :
        if(nb == 0){
        printf("Aucun compte.\n");
        break;
    }

    printf("Entrez l'ID du compte a supprimer : ");
    scanf("%d", &id);

    index = chercher_compte_par_id(&c, nb, id);

    if(index == -1){
        printf("Compte introuvable.\n");
    } else {
        supprimer_compte(&c, index, &nb);
        printf("Opperation effectue \n");
        printf("Compte ID %d supprimer \n",id);
    }
    break;

    case 7 :
        if(nb == 0){
        printf("Aucun compte.\n");
        break;
    }
        afficher_tout_comptes(&c, &nb);
        break;

    }
}while(choix!=0);
return 0;
}
