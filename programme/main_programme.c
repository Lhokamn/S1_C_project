#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_fonctions.h"
#include "mes_variables.h"

int main(void)
{
    FILE *fichier=fopen(chemin,"r");
    if (fichier==NULL)
    {
        printf("Echec ouverture fichier\n");
        return EXIT_FAILURE;
    }
    remplissage_tableau();
    // menu(tableau_CSV, ligne_tableau, colonne_tableau);
    fclose(fichier);
    printf("Au revoir !");
    return 0;
}