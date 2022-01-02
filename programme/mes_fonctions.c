#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_variables.h"

int lecture (Personne client[])
{
	
	return EXIT_SUCCESS;
}

// void permuter(char *element1, char *element2)
// {
//     int tmp;
//     tmp = *element1;
//     *element1 = *element2;
//     *element2 = tmp;
// }

// void quicksort(Personne client[],int indice_colonne, int depart, int fin)
// {   
// 	int pivot, i, j;
//     if(depart < fin) {
//         pivot = depart;
//         i = depart;
//         j = taille_tableau;
//         while (i < j) {
//             while(client[i][indice_colonne] <= client[pivot][indice_colonne] && i < fin)
//                 i++;
//             while(client[j][indice_colonne] > client[pivot][indice_colonne])
//                 j--;
//             if(i < j) {
//                 permuter(&client[i][indice_colonne], &client[j][indice_colonne]);
//             }
//         }
//         permuter(&client[pivot][indice_colonne], &client[j][indice_colonne]);
//         quicksort(client, indice_colonne, depart, j-1);
//         quicksort(client, indice_colonne,  j + 1, fin);
//     }
// }

/*-----------------------------------Switch 1-----------------------------------*/

/* Switch 1.1 */

int insertion_personne(Personne client [])
{
	char *nomP, *prenomP, *villeP, *code_postalP, *telephoneP, *mailP, *metierP;
	int champ_actuel=0;
	printf("Insérez le nom \n");
    scanf("%s",&nomP);
	printf("Insérez le prénom \n");
    scanf("%s",&prenomP);
	printf("Insérez la ville \n");
    scanf("%s",&villeP);
	printf("Insérez le code postal \n");
    scanf("%s",&code_postalP);
	printf("Insérez le telephone \n");
    scanf("%s",&telephoneP);
	printf("Insérez le mail \n");
    scanf("%s",&mailP);
	printf("Insérez le metier \n");
    scanf("%s",&metierP);
	while (champ_actuel<7)
	{
		if(champ_actuel ==0 ){//nom
			strcpy(client[champ_actuel].nom,nomP);
		}
		else if(champ_actuel==1)
		{//prenom
			strcpy(client[champ_actuel].prenom,prenomP);
		}
		else if(champ_actuel==2)
		{//ville
		    strcpy(client[champ_actuel].ville,villeP);
		}
		else if(champ_actuel==3)
		{//code postal
		    strcpy(client[champ_actuel].code_postal,code_postalP);
		}
		else if(champ_actuel==4)
		{//telephone
		    strcpy(client[champ_actuel].telephone,telephoneP);
		}
		else if(champ_actuel==5)
		{//mail
		    strcpy(client[champ_actuel].mail,mailP);
		}
		else if(champ_actuel==6)
		{//metier
		    strcpy(client[champ_actuel].metier,metierP);
		}
	}
	return EXIT_SUCCESS;
}

int modification_element(Personne client[])
{
	printf("Donnez ");
}

int critere_insertion(Personne client[])
{
	int insertion, nombre;
	int i=0;
	printf("Que voulez faire ?: \n 1) Insérez tous les éléments d'une personne \n 2) Modifier une donnée d'une personne \n");
    scanf("%d",&insertion);
	switch (insertion)
	{
		case 1:
			printf("combien de personne voulez vous ajouter ? \n");
			scanf("%d",&nombre);
			while (i<nombre)
			{
				insertion_personne(client);
			}
			break;
		case 2:
			modification_element(client);
			break;
		default:
			break;
	}
}

/*-----------------------------------Switch 2-----------------------------------*/

int critere_suppression(Personne client[])
{
	printf("Choissi");
}

/*-----------------------------------Switch 3-----------------------------------*/

/* Switch 3.1 */
int recherche_dichotomie(Personne client[],int indice, char element_a_trouver, int debut, int fin)
{
	
	return EXIT_SUCCESS;
}

int information_personne(Personne client[])
{
	int informations;
	char nom;
	char prenom;
	char telephone;
	char mail;
	printf("Vous voulez rechercher par : \n 1) Son nom \n 2) Son prénom et numéro de téléphone \n 3) Son adresse mail \n");
    scanf("%d",&informations);
	switch (informations)
	{
		case 1:
			printf("Entrez le nom \n");
			scanf("%s",&nom);
			quicksort(client,informations,0,taille_tableau);
			recherche_dichotomie(client,informations,nom,0,taille_tableau-1);
			break;
		case 2:
			printf("Entrez le prénom et le numéro de téléphone \n");
			scanf("%s %s",&prenom,&telephone);
			informations=5;
			quicksort(client,informations,0,taille_tableau);
			recherche_dichotomie(client,informations,telephone,0,taille_tableau-1);
			break;
		case 3:
			printf("Entrez l'adresse mail \n");
			scanf("%s",&mail);
			quicksort(client,informations,0,taille_tableau);
			recherche_dichotomie(client,informations,mail,0,taille_tableau-1);
			break;
		default:
			break;
	}
}

/*-----------------------------------Switch 4-----------------------------------*/

/* Switch 4.1 */

int lancement_filtre(Personne client[], char critere, int indice)
{
	quicksort(client,indice,0,taille_tableau);

}

int choisir_filtre(Personne client[])
{
	int filtre;
	int critere;
	printf("Veuillez choisir l'élement à filtrer :\n 1) Nom \n 2) Prénom \n 3) profession \n 4) code postal \n");
    scanf("%d",&filtre);
	printf("Entrez le critère de filtre \n");
	scan("%s",&critere);
    switch (filtre)
	{
		case 1:
			lancement_filtre(client, critere, 0);
			break;
		case 2:
			lancement_filtre(client, critere, 1);
			break;
		case 3:
			lancement_filtre(client, critere, 6);
			break;
		case 4:
			lancement_filtre(client, critere, 4);
			break;
		default:
			break;
	}
}

//-----------------------------------------------------

int menu(Personne client[])
{
    int menu=0;
    while (menu!=5)
	{
        printf("Veuillez choisir ce que vous voulez faire :\n 1) Insérer ou modifier une personne \n 2) Supprimer une personne \n 3) Recherche des informations d'une personne \n 4) Filtrer \n 5) Quitter le programme \n");
        scanf("%d",&menu);
        switch (menu)
		{
			case 1:
				critere_insertion(client);
				break;
			case 2:
				critere_suppression(client);
				break;
			case 3:
				information_personne(client);
				break;
			case 4:
				choisir_filtre(client);
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
	while(fgets(longueur_ligne, taille_ligne, fichier) != NULL)
	{
	    champ_actuel = 0;
	    char *copie_ligne = strdup(longueur_ligne);//dupliquer la chaîne ligne avec strdupa car le strsep modifie
	                                      //le pointeur passé, et nous ne voulons pas perdre la valeur d’origine
		printf("%s",champ_actuel);
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