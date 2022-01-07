#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_fonctions.h"


int main(void)
{
    int nombre_client_actuel=0;

    FILE *fichier=fopen(chemin,"r");
    if (fichier==NULL)
    {
        printf("Echec ouverture fichier\n");
        return EXIT_FAILURE;
    }
    fclose(fichier);
    
    Personne *client;
    client=(Personne *)calloc(taille_tableau,sizeof(Personne));
    remplissage_tableau(client, &nombre_client_actuel);

    menu(client, &nombre_client_actuel);
    free(client);
    printf("Au revoir !");
    return EXIT_SUCCESS;
}