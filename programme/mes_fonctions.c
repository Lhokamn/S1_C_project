#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
            printf("Commande non valide");
        }
}