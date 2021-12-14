#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_fonctions.h"
#define chemin "../test_a_detruire.csv"

int main(void)
{
    FILE *fichier=fopen(chemin,"r");
    if (fichier==NULL)
    {
        printf("Echec ouverture fichier\n");
        return EXIT_FAILURE;
    }
    fclose(fichier);
    
    remplissage_tableau();

    tri_tableau();

    menu();
    printf("Au revoir !");
    return 0;
}