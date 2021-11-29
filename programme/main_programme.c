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
            lecture();
        break;
        case choix ='2':

        break;
        default:
        printf("Erreur: Fin système");
    }
    return 0;
}