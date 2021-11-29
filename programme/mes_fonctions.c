#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define chemin "../test_a_detruire.csv"
#define MAX_LENGTH 5000

void menu(void)
{
    int menu=0;
    while (menu!=5)
        printf("Veuillez choisir ce que vous voulez faire\n 1) Insérer une personne \n 2) Supprimer une personne \n 3)recherche des informations d'une personne \n 4) Filtrer \n 5) Quitter le programme");
        scanf(&menu);
        if (menu==1)
        {
            //
        }
        else if (menu==2)
        {
            //
        }
        else if (menu==3)
        {
            //
        }
        else if (menu==4)
        {
            //
        }
        else
        {
            printf("Commande non valide")
        }
}

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

int transformation_CSV_tableau(int ligne, int colonne)
{
    if (test_fichier()==EXIT_FAILURE)
        return EXIT_FAILURE;
    else
    {
        
    }    
}