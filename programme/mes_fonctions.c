#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_variables.h"


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
	return EXIT_FAILURE;
}

void tri_bulle(char tableau[taille_tableau],int indice)
{
	int j=0;
	int tmp;
	while (j<taille_tableau)
	{
		int k=0;
		while (k<taille_ligne)
		{
			if (tableau[j]<tableau[k])
			{
				tmp=tableau[j];
				tableau[j]=tableau[k];
				tableau[k]=tmp;
			}
			k++;
		}
		j++;
	}
}


int remplissage_tableau(void)
{
	FILE *fichier = fopen(chemin,"r");
    char longueur_ligne[taille_ligne];
    char *token;
    int champ_actuel = 0;
	while( fgets(longueur_ligne, taille_ligne, fichier) != NULL)
	{
	    champ_actuel = 0;
		Personne client[taille_tableau];
	    char *copie_ligne = strdup(longueur_ligne);//dupliquer la chaîne ligne avec strdupa car le strsep modifie
	                                      //le pointeur passé, et nous ne voulons pas perdre la valeur d’origine
	    while( (token = strsep(&copie_ligne, ",")) != NULL)
	    {
			printf("%s \n",token);
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
					strcpy(client[champ_actuel].nom,token);
		    	}
		    	else if(champ_actuel==1)
	            {//prenom
					strcpy(client[champ_actuel].prenom,token);
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
	}
	fclose(fichier);
	return EXIT_SUCCESS;
}