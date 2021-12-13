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


tri_tableau()
{
	int indice=1;
	char tableau_prenom=taille_tableau;
	char tableau_ville=taille_tableau;
	char tableau_code_postal=taille_tableau;
	char tableau_telephone=taille_tableau;
	char tableau_mail=taille_tableau;
	char tableau_metier=taille_tableau;
	while (indice<7)
		switch (indice)
		{
		case 1:
			tri_bulle(tableau_prenom,indice);
			break;
		case 2:
			tri_bulle(tableau_ville,indice);
			break;
		case 3:
			tri_bulle(tableau_code_postal,indice);
			break;
		case 4:
			tri_bulle(tableau_telephone,indice);
			break;
		case 5:
			tri_bulle(tableau_mail,indice);
			break;
		case 6:
			tri_bulle(tableau_metier,indice);
			break;
		default:
			break;
		}
}


void remplissage_tableau(void)
{
	FILE *fichier = fopen(chemin,"r");
    char longueur_ligne[taille_ligne];
    char *token;
	int t=0;
	while( fgets(longueur_ligne, taille_ligne, fichier) != NULL)
	{
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
				switch (t)
				{
				case 0:
					//nom
					strcpy(client[t].nom,token);
					break;
				case 1:
					//prenom
					strcpy(client[t].prenom,token);
					break;
				case 2:
					//ville
		    	    strcpy(client[t].ville,token);
					break;
				case 3:
					//code postal
		    	    strcpy(client[t].code_postal,token);
					break;
				case 4:
					//telephone
		    	    strcpy(client[t].telephone,token);
					break;	
				case 5:
					//mail
		    	    strcpy(client[t].mail,token);
					break;
				case 6:
					//metier
		    	    strcpy(client[t].metier,token);
					break;			
				default:
					break;
				}
		    }
			t++;
	    } 
	}
	fclose(fichier);
}