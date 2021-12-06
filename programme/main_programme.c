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

    struct Personne donnees[MAX_LENGTH];

    int compteur_ligne=0;
    
    while(fgets !=NULL)
    {
        donnees[compteur_ligne].prenom,"fgets(chemin,'r')";
        donnees[compteur_ligne].nom,"fgets(chemin,'r')";
        donnees[compteur_ligne].ville,"fgets(chemin,'r')";
        donnees[compteur_ligne].code_postal,"fgets(chemin,'r')";
        donnees[compteur_ligne].telephone,"fgets(chemin,'r')";
        donnees[compteur_ligne].mail,"fgets(chemin,'r')";
        donnees[compteur_ligne].metier,"fgets(chemin,'r')";
        compteur_ligne++;
    }
    // menu(tableau_CSV, ligne_tableau, colonne_tableau);
    fclose(fichier);
    printf("Au revoir !");
    return 0;
}