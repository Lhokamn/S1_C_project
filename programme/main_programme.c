#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_fonctions.h"

int main(void)
{
    char choix;
    printf("Que voulez-vous faire ? Choisissez un nombre \n 1.Lire le tableau \n 2.Modifier le fichier");
    switch(scanf("%c",&choix)) {

        case choix='1':
            system("cls");
            printf("Lecture du fichier \n ");
            lecture();
        break;
        case choix ='2':
            system("cls");
            printf("Modifier le tableau");
        break;
        default:
        printf("Erreur: Fin système");
        return void;
    }
    return 0;
}