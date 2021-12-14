#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_variables.h"

void permuter(char *element1, char *element2)
{
    int tmp;
    tmp = *element1;
    *element1 = *element2;
    *element2 = tmp;
}

void quicksort(Personne client[],int indice_colonne, int depart, int fin)
{   
	int pivot, i, j;
    if(depart < fin) {
        pivot = depart;
        i = depart;
        j = taille_tableau;
        while (i < j) {
            while(client[i][indice_colonne] <= client[pivot][indice_colonne] && i < fin)
                i++;
            while(client[j][indice_colonne] > client[pivot][indice_colonne])
                j--;
            if(i < j) {
                permuter(&client[i][indice_colonne], &client[j][indice_colonne]);
            }
        }
        permuter(&client[pivot][indice_colonne], &client[j][indice_colonne]);
        quicksort(client, indice_colonne, depart, j-1);
        quicksort(client, indice_colonne,  j + 1, fin);
    }
}

int menu(Personne client[])
{
    int menu=0;
    while (menu!=5)
	{
        printf("Veuillez choisir ce que vous voulez faire\n 1) Insérer une personne \n 2) Supprimer une personne \n 3) Recherche des informations d'une personne \n 4) Filtrer \n 5) Quitter le programme \n");
        scanf("%d",&menu);
        switch (menu)
		{
			case 1:
				quicksort(client,0,0,taille_ligne);
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
	return EXIT_FAILURE;
}


int remplissage_tableau(Personne client[])
{
	FILE *fichier = fopen(chemin,"r");
    char longueur_ligne[taille_ligne];
    char *token;
    int champ_actuel = 0;
	//int ligne_actuelle=0;
	while(fgets(longueur_ligne, taille_ligne, fichier) != NULL)
	{
	    champ_actuel = 0;
	    char *copie_ligne = strdup(longueur_ligne);//dupliquer la chaîne ligne avec strdupa car le strsep modifie
	                                      //le pointeur passé, et nous ne voulons pas perdre la valeur d’origine
	    while( (token = strsep(&copie_ligne, ",")) != NULL)
	    {
		    /* note the trailing field will contain newline. */
		    if(*token == '\n')
		    {
		    	//ne rien faire
		    }
		    else if(token == NULL){
		    	//ne rien faire
		    }
		    else{
			
		    	if(champ_actuel ==0 ){//nom
					strcpy(client/*[ligne_actuelle]*/[champ_actuel].nom,token);
		    	}
		    	else if(champ_actuel==1)
	            {//prenom
					strcpy(client[champ_actuel==1].prenom,token);
		    	}
				else if(champ_actuel==2)
	            {//ville
		    	    strcpy(client[champ_actuel].ville,token);
		    	}
	            else if(champ_actuel==3)
	            {//code postal
		    	    strcpy(client[champ_actuel].code_postal,token);
		    	}
	            else if(champ_actuel==4)
	            {//telephone
		    	    strcpy(client[champ_actuel].telephone,token);
		    	}
	            else if(champ_actuel==5)
	            {//mail
		    	    strcpy(client[champ_actuel].mail,token);
		    	}
	            else if(champ_actuel==6)
	            {//metier
		    	    strcpy(client[champ_actuel].metier,token);
		    	}
		    }
		    champ_actuel++;
	    }
		//ligne_actuelle++;
	}
	fclose(fichier);
	return EXIT_SUCCESS;
}