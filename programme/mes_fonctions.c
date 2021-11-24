#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define chemin "../test_a_detruire.csv"
#define MAX_LENGTH 30000

//lire un fichier csv ligne par ligne avec fgets et le diviseurs avec strtok

void test_fichier()
{
    char ligne[MAX_LENGTH];

    char *token; //Contiendra les différents champ de chaque ligne après tokenization

    FILE *fichier=fopen(chemin,"r");

    if (fichier==NULL)
    {
        printf("Echec ouverture fichier\n");
        exit (EXIT_FAILURE);
    }
}

int lecture(void)
{
    test_fichier();

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
    switch (attribut_rechercher)
    {
        case 1:
        //pour récupérer les prénoms
        break;
        case 2:
        //pour récupérer les noms
        break;
        case 3:
        //pour récupérer les code postal
        break;
        case 4:
        //pour récupérer les profession

    }
}