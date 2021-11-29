#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_fonctions.h"
#define chemin "../test_a_detruire.csv"
#define ligne 6000
#define colonne 7
#define MAX_LENGTH 5000

int main(void)
{
    FILE *fichier=fopen(chemin,"r");

    if (fichier==NULL)
    {
        printf("Echec ouverture fichier\n");
        return EXIT_FAILURE;
    }
    char tableau_CSV[ligne][colonne];
    int ajout_colonne=0;
    int ajout_ligne=0;
    while (ajout_ligne<ligne)
    {
        while (ajout_colonne<colonne)
        {
            tableau_CSV[ajout_ligne][ajout_colonne]=fgets(ligne,MAX_LENGTH,fichier);
        }
    }
    return EXIT_SUCCESS;
    menu();
    printf("Au revoir !");
    return 0;
}