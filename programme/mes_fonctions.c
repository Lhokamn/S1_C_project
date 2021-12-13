#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_variables.h"

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


int menu(void)
{
    int menu=0;
    while (menu!=5)
	{
        printf("Veuillez choisir ce que vous voulez faire\n 1) Insérer une personne \n 2) Supprimer une personne \n 3)recherche des informations d'une personne \n 4) Filtrer \n 5) Quitter le programme \n");
        scanf("%d",&menu);
        switch (menu)
		{
			case 1:
				/* code */
				break;
			case 2:
				/* code */
				break;
			case 3:
				/* code */
				break;
			case 4:
				/* code */
				break;
			case 5:
				return EXIT_SUCCESS;
			default:
				break;
		}
	}
}


void remplissage_tableau(void)
{
	FILE *fichier = fopen(chemin,"r");
    char longueur_ligne[taille_ligne];
    char *token;
    int champ_actuel = 0;
	int t=0;
	while( fgets(longueur_ligne, taille_ligne, fichier) != NULL)
	{
	    champ_actuel = 0;
		Personne client[taille_tableau];
	    char *copie_ligne = strdup(longueur_ligne);//dupliquer la chaîne ligne avec strdupa car le strsep modifie
	                                      //le pointeur passé, et nous ne voulons pas perdre la valeur d’origine
	    while( (token = strsep(&copie_ligne, ",")) != NULL)
	    {
		    /* note the trailing field will contain newline. */
		    if(*token == '\n'){
		    }
		    else if(token == NULL){
		    }
		    else{
			
		    	if(champ_actuel ==0 ){//nom
					strcpy(client[t].nom,token);
		    	}
		    	else if(champ_actuel==1)
	            {//prenom
					strcpy(client[t].prenom,token);
		    	}
				else if(champ_actuel==2)
	            {//ville
		    	    strcpy(client[t].ville,token);
		    	}
	            else if(champ_actuel==3)
	            {//code postal
		    	    strcpy(client[t].code_postal,token);
		    	}
	            else if(champ_actuel==4)
	            {//telephone
		    	    strcpy(client[t].telephone,token);
		    	}
	            else if(champ_actuel==5)
	            {//mail
		    	    strcpy(client[t].mail,token);
		    	}
	            else if(champ_actuel==6)
	            {//metier
		    	    strcpy(client[t].metier,token);
		    	}
		    }
		    champ_actuel++;
	    }
	    t++;
	}
	fclose(fichier);
}