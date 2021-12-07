#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_fonctions.h"
#include "mes_variables.h"


int main(void)
{
    FILE *fichier=fopen(chemin,"r");
    char ligne[MAX_LENGTH];

    if (fichier==NULL)
    {
        printf("Echec ouverture fichier\n");
        return EXIT_FAILURE;
    }

    do
    {
        creation_structure_personne(fgets(ligne, MAX_LENGTH,fichier));
    }while (fread!=NULL);
    
    // menu(tableau_CSV, ligne_tableau, colonne_tableau);
    fclose(fichier);
    printf("Au revoir !");
    return 0;
}