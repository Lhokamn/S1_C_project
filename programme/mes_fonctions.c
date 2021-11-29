#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define chemin "../test_a_detruire.csv"
#define MAX_LENGTH 5000

//lire un fichier csv ligne par ligne avec fgets et le diviseurs avec strtok

int test_fichier(void)
{
    FILE *fichier=fopen(chemin,"r");

    if (fichier==NULL)
    {
        printf("Echec ouverture fichier\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int lecture(void)
{
    if (test_fichier()==EXIT_FAILURE)
        return EXIT_FAILURE;

    char ligne[MAX_LENGTH];
    char *token; //Contiendra les différents champ de chaque ligne après tokenization
    FILE *fichier=fopen(chemin,"r");

    while (fgets(ligne,MAX_LENGTH,fichier))
    {
        printf("Ligne : %s", ligne);
        token = strtok(ligne, ",");
        while (token != NULL)
        {
            printf("Token : %s\n", token);
            token =strtok(NULL, ",");
        }
    }

    printf("\n");
    fclose(fichier);
    return EXIT_SUCCESS;
}

int recuperation(char attribut_rechercher)
{   
    if (attribut_rechercher=='Nom')
    {
        attribut_rechercher==1;
    }
    else if (attribut_rechercher=='Prénom')
    {
        attribut_rechercher==2;
    }
    else if (attribut_rechercher=='Profession')
    {
        attribut_rechercher==3;
    }
    else if (attribut_rechercher=='code_postal')
    {
        attribut_rechercher==4;
    }   
    else
    {
        printf("Le caractère choisi n'existe pas ou est mal orthographié. \nMerci d'essayer 'Nom', 'Prénom', 'Profession', 'code_postal'")
        return EXIT_FAILURE;
    }    
}