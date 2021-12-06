#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int caracteristique_insertion(char tableau_CSV, int ligne_tableau, int colonne_tableau)
// {
//     int insertion;
//     printf("1) Vous voulez insérer un élément à une personne \n2)Voulez insérer toutes les caractéristiques d'une personne");
//     scanf("%d",&insertion);
//     if (insertion==1)
//     {
//         int contenance_element;
//         int nom_personne;
//         printf("donnez en premier lieu l'élément à ajouter, puis le nom de la personne");
//         scanf("%d %d",&contenance_element,&nom_personne);

//     }
//     else if (insertion==2)
//     {
//         int nb_personne_a_rajouter;
//         int i=0;
//         printf("Combien de personne voulez vous ajouter ?");
//         while (i<nb_personne_a_rajouter)
//         {
//             scanf("%d",&nb_personne_a_rajouter);
//             char Nom;
//             char Prenom;
//             char Ville;
//             char code_postal;
//             char n_telephone;
//             char adresse_mail;
//             char metier;

//             printf("Donnez le nom de la personne à rajouter");
//             scanf("%c",&Nom);
//             insertion_personne(tableau_CSV, ligne_tableau, colonne_tableau, Nom);
//         }
        

//     }
// }


// void menu(char tableau_CSV, int ligne_tableau, int colonne_tableau)
// {
//     int menu=0;
//     while (menu!=5)
//         printf("Veuillez choisir ce que vous voulez faire\n 1) Insérer une personne \n 2) Supprimer une personne \n 3)recherche des informations d'une personne \n 4) Filtrer \n 5) Quitter le programme");
//         scanf("%d",&menu);
//         if (menu==1)
//         {
//             caracteristique_insertion(tableau_CSV, ligne_tableau, colonne_tableau);
//         }
//         else if (menu==2)
//         {
//             //
//         }
//         else if (menu==3)
//         {
//             //
//         }
//         else if (menu==4)
//         {
//             //
//         }
//         else if (menu==5)
//         {
//             //
//         }
//         else
//         {
//             printf("Commande non valide");
//         }
// }