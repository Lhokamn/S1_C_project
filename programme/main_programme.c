#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_fonctions.h"
#define chemin "../test_a_detruire.csv"
#define ligne_tableau 6000
#define colonne_tableau 7
#define MAX_LENGTH 5000

int main(void)
{
    FILE *fichier=fopen(chemin,"r");
    char ligne[MAX_LENGTH];

    if (fichier==NULL)
    {
        printf("Echec ouverture fichier\n");
        return EXIT_FAILURE;
    }
    char tableau_CSV[ligne_tableau][colonne_tableau];
    int ajout_colonne=0;
    int ajout_ligne=0;
    while (ajout_ligne<ligne_tableau)
    {
        while (ajout_colonne<colonne_tableau)
        {
            tableau_CSV[ajout_ligne][ajout_colonne]=fgets(ligne,MAX_LENGTH,fichier);
            ajout_colonne++;
            printf("%s",tableau_CSV);
        }
        ajout_ligne++;
    }
    // menu(tableau_CSV, ligne_tableau, colonne_tableau);
    printf("Au revoir !");
    return 0;
}