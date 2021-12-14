#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_fonctions.h"

int main(void)
{
    FILE *fichier=fopen(chemin,"r");
    if (fichier==NULL)
    {
        printf("Echec ouverture fichier\n");
        return EXIT_FAILURE;
    }
    fclose(fichier);
    
    Personne client[taille_tableau];
    remplissage_tableau(client);

    menu(client);
    printf("Au revoir !");
    return 0;
}