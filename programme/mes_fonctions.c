#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define chemin "../test_a_detruire.csv"
#define MAX_LENGTH 30000

//lire un fichier csv ligne par ligne avec fgets et le diviseurs avec strtok

int lecture(void)
{
    char ligne[MAX_LENGTH];

    char *token; //Contiendra les différents champ de chaque ligne après tokenization

    /*const char *separateur=",";*/ //la liste des caractères de séparation à utiliser pour le découpage

    FILE *fichier=fopen(chemin,"r");

    if (fichier==NULL)
    {
        printf("Echec ouverture fichier\n");
        exit (EXIT_FAILURE);
    }

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

int ajout_client(char Prenom, char Nom, char Ville, char code_postal, char num_telephone)
{

}