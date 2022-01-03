#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_variables.h"



//------------Algorithme de tri-------------- 
void permuter(char *element1, char *element2)
{
    int tmp;
    tmp = *element1;
    *element1 = *element2;
    *element2 = tmp;
}

void quicksort_nom(Personne client[], int depart, int fin)
{   
	int pivot, i, j;
    if(depart < fin) {
        pivot = depart;
        i = depart;
        j = taille_tableau;
        while (i < j) {
            while(client[i].nom <= client[pivot].nom && i < fin)
                i++;
            while(client[j].nom > client[pivot].nom)
                j--;
            if(i < j) {
                permuter(client[i].nom, client[j].nom);
            }
        }
        permuter(client[pivot].nom, client[j].nom);
        quicksort_nom(client, depart, j-1);
        quicksort_nom(client, j + 1, fin);
    }
}

void quicksort_prenom(Personne client[], int depart, int fin)
{   
	int pivot, i, j;
    if(depart < fin) {
        pivot = depart;
        i = depart;
        j = taille_tableau;
        while (i < j) {
            while(client[i].prenom <= client[pivot].prenom && i < fin)
                i++;
            while(client[j].prenom > client[pivot].prenom)
                j--;
            if(i < j) {
                permuter(client[i].prenom, client[j].prenom);
            }
        }
        permuter(client[pivot].prenom, client[j].prenom);
        quicksort_prenom(client, depart, j-1);
        quicksort_prenom(client, j + 1, fin);
    }
}

void quicksort_metier(Personne client[], int depart, int fin)
{   
	int pivot, i, j;
    if(depart < fin) {
        pivot = depart;
        i = depart;
        j = taille_tableau;
        while (i < j) {
            while(client[i].metier <= client[pivot].metier && i < fin)
                i++;
            while(client[j].metier > client[pivot].metier)
                j--;
            if(i < j) {
                permuter(client[i].metier, client[j].metier);
            }
        }
        permuter(client[pivot].metier, client[j].metier);
        quicksort_metier(client, depart, j-1);
        quicksort_metier(client, j + 1, fin);
    }
}

void quicksort_code_postal(Personne client[], int depart, int fin)
{   
	int pivot, i, j;
    if(depart < fin) {
        pivot = depart;
        i = depart;
        j = taille_tableau;
        while (i < j) {
            while(client[i].code_postal <= client[pivot].code_postal && i < fin)
                i++;
            while(client[j].code_postal > client[pivot].code_postal)
                j--;
            if(i < j) {
                permuter(client[i].code_postal, client[j].code_postal);
            }
        }
        permuter(client[pivot].code_postal, client[j].code_postal);
        quicksort_code_postal(client, depart, j-1);
        quicksort_code_postal(client, j + 1, fin);
    }
}

void quicksort_mail(Personne client[], int depart, int fin)
{   
	int pivot, i, j;
    if(depart < fin) {
        pivot = depart;
        i = depart;
        j = taille_tableau;
        while (i < j) {
            while(client[i].mail <= client[pivot].mail && i < fin)
                i++;
            while(client[j].mail > client[pivot].mail)
                j--;
            if(i < j) {
                permuter(client[i].mail, client[j].mail);
            }
        }
        permuter(client[pivot].mail, client[j].mail);
        quicksort_mail(client, depart, j-1);
        quicksort_mail(client, j + 1, fin);
    }
}

//--------------------------------------------

int critere_recherche(Personne client[], char *nom, char *telephone)
{
	printf("rentrer le nom de famille et le numéro de téléphone \n");
	scanf("%s %s",nom,telephone);
	return EXIT_SUCCESS;
}

/*-----------------------------------Switch 1-----------------------------------*/

/* Switch 1.1 */

int insertion_personne(Personne client [],int *nombre_client_actuel)
{
	char nomP[45], prenomP[45], villeP[45], code_postalP[6], telephoneP[10], mailP[60], metierP[50];
	int champ_actuel=0;
	client=realloc(client,(*nombre_client_actuel+1)*sizeof(char));
	nombre_client_actuel++;
	printf("Insérez le nom \n");
    scanf("%s",nomP);
	printf("Insérez le prénom \n");
    scanf("%s",prenomP);
	printf("Insérez la ville \n");
    scanf("%s",villeP);
	printf("Insérez le code postal \n");
    scanf("%s",code_postalP);
	printf("Insérez le telephone \n");
    scanf("%s",telephoneP);
	printf("Insérez le mail \n");
    scanf("%s",mailP);
	printf("Insérez le metier \n");
    scanf("%s",metierP);
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

/* switch 1.2 */

int modification_client(Personne client[], int champ_actuel)
{
	int critere;
	char mot_a_remplacer[60];
	printf("Quel critère voulait vous modifier ? \n 1) Prénom \n 2) Nom \n 3) Ville \n 4) Code postal \n 5) Téléphone \n 6) Mail \n 7) Métiers \n");
	scanf("%d",&critere);
	printf("Rentrez le nouveau élément\n");
	scanf("%s",mot_a_remplacer);
	switch (critere)
	{
		case 1:
			strcpy(client[champ_actuel].prenom,mot_a_remplacer);
			break;
		case 2:
			strcpy(client[champ_actuel].nom,mot_a_remplacer);
			break;
		case 3:
			strcpy(client[champ_actuel].ville,mot_a_remplacer);
			break;
		case 4:
			strcpy(client[champ_actuel].code_postal,mot_a_remplacer);
			break;
		case 5:
			strcpy(client[champ_actuel].telephone,mot_a_remplacer);
			break;
		case 6:
			strcpy(client[champ_actuel].mail,mot_a_remplacer);
			break;
		case 7:
			strcpy(client[champ_actuel].metier,mot_a_remplacer);
			break;
		default:
			break;
	}
	return EXIT_SUCCESS;
}

int verification_client(Personne client[], char *nom, char *telephone)
{
	int champ_actuel=0;
	while(champ_actuel<taille_tableau)
	{
		if (client[champ_actuel].nom==nom && client[champ_actuel].telephone==telephone)
		{
			modification_client(client,champ_actuel);
			return EXIT_SUCCESS;
		}
		champ_actuel++;
	}
	return EXIT_SUCCESS;	
}

/*main switch 1*/

int critere_insertion(Personne client[],int *nombre_client_actuel)
{
	int insertion, nombre;
	int i=0;
	char *nom, *telephone;
	printf("Que voulez faire ?: \n 1) Insérez tous les éléments d'une personne \n 2) Modifier une donnée d'une personne \n");
    scanf("%d",&insertion);
	switch (insertion)
	{
		case 1:
			printf("combien de personne voulez vous ajouter ? \n");
			scanf("%d",&nombre);
			while (i<nombre)
			{
				insertion_personne(client,nombre_client_actuel);
			}
			break;
		case 2:
			critere_recherche(client,nom,telephone);
			verification_client(client,nom,telephone);
			break;
		default:
			break;
	}
	return EXIT_SUCCESS;
}

/*-----------------------------------Switch 2-----------------------------------*/

int suppression_client(Personne client[], char *nom, char *telephone,int *nombre_client_actuel)
{
	int champ_actuel=0;
	while(champ_actuel<taille_tableau)
	{
		if (client[champ_actuel].nom==nom && client[champ_actuel].telephone==telephone)
		{
			client=realloc(client,(*nombre_client_actuel-1)*sizeof(char));
			nombre_client_actuel--;
		}
		champ_actuel++;
		printf("La personne cherché n'existe pas \n");
	}
	return EXIT_SUCCESS;	
}

int critere_suppression(Personne client[],int *nombre_client_actuel)
{
	char *nom, *telephone;
	critere_recherche(client,nom,telephone);
	suppression_client(client,nom,telephone,nombre_client_actuel);
	return EXIT_SUCCESS;
}

/*-----------------------------------Switch 3-----------------------------------*/

/* Switch 3.1 */
int recherche_dichotomie(Personne client[],int indice, char element_a_trouver, int debut, int fin)
{
	
	return EXIT_SUCCESS;
}

/*main switch 3*/

int information_personne(Personne client[],int nombre_client_actuel)
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
			quicksort_nom(client,0,nombre_client_actuel);
			recherche_dichotomie(client,informations,nom,0,taille_tableau-1);
			break;
		case 2:
			printf("Entrez le prénom et le numéro de téléphone \n");
			scanf("%s %s",&prenom,&telephone);
			informations=5;
			quicksort_prenom(client,0,nombre_client_actuel);
			recherche_dichotomie(client,informations,telephone,0,taille_tableau-1);
			break;
		case 3:
			printf("Entrez l'adresse mail \n");
			scanf("%s",&mail);
			quicksort_mail(client,0,nombre_client_actuel);
			recherche_dichotomie(client,informations,mail,0,taille_tableau-1);
			break;
		default:
			break;
	}
	return EXIT_SUCCESS;
}

/*-----------------------------------Switch 4-----------------------------------*/


int recherche_filtre(Personne client[], Personne client_filtre[])
{

}

int lancement_filtre(Personne client[], char critere, int indice)
{
	Personne *client_filtre;
	client_filtre=calloc(0,sizeof(char));

	recherche_filtre(client,client_filtre);

	lecture(client_filtre);
	return EXIT_SUCCESS;
}

int choisir_filtre(Personne client[],int *nombre_client_actuel)
{
	int filtre;
	int critere;
	printf("Veuillez choisir l'élement à filtrer :\n 1) Nom \n 2) Prénom \n 3) profession \n 4) code postal \n");
    scanf("%d",&filtre);
	printf("Entrez le critère de filtre \n");
	scanf("%d",&critere);
    switch (filtre)
	{
		case 1:
			quicksort_nom(client,0,nombre_client_actuel);
			lancement_filtre(client, critere, 0);
			break;
		case 2:
			quicksort_prenom(client,0,nombre_client_actuel);
			lancement_filtre(client, critere, 1);
			break;
		case 3:
			quicksort_metier(client,0,nombre_client_actuel);
			lancement_filtre(client, critere, 6);
			break;
		case 4:
			quicksort_code_postal(client,0,nombre_client_actuel);
			lancement_filtre(client, critere, 4);
			break;
		default:
			break;
	}
	return EXIT_SUCCESS;
}

/*-----------------------------------Switch 5-----------------------------------*/

int lecture (Personne client[])
{
	FILE *fichier = fopen(chemin,"r");
    char longueur_ligne[taille_ligne];
    char *token;
    int champ_actuel;
	while(fgets(longueur_ligne, taille_ligne, fichier) != NULL)
	{
	    champ_actuel = 0;
	    char *copie_ligne = strdup(longueur_ligne);//dupliquer la chaîne ligne avec strdupa car le strsep modifie
	                                      //le pointeur passé, et nous ne voulons pas perdre la valeur d’origine
		while( (token = strsep(&copie_ligne, ",")) != NULL)
	    {
		    if(*token == '\n')
		    {
		    	//ne rien faire
		    }
		    else if(token == NULL){
		    	//ne rien faire
		    }
		    else{
			
		    	if(champ_actuel ==0 ){//nom
					printf("nom=%s",token);
		    	}
		    	else if(champ_actuel==1)
	            {//prenom
					printf("prénom=%s",token);
		    	}
				else if(champ_actuel==2)
	            {//ville
					printf("ville=%s",token);
		    	}
	            else if(champ_actuel==3)
	            {//code postal
					printf("code postal=%s",token);
		    	}
	            else if(champ_actuel==4)
	            {//telephone
					printf("téléphone=%s",token);
		    	}
	            else if(champ_actuel==5)
	            {//mail
					printf("mail=%s",token);
		    	}
	            else if(champ_actuel==6)
	            {//metier
					printf("métier=%s",token);
		    	}
		    }
			printf("\n");
		    champ_actuel++;
	    }
	}
	fclose(fichier);
	return EXIT_SUCCESS;
}


/*-----------------------------------Switch 6-----------------------------------*/
int ecriture_fichier_csv(Personne client[],int nombre_client_actuel)
{
	FILE *fichier = fopen(chemin,"w");
	char longueur_ligne[taille_ligne];
    int champ_actuel;
	int indice=0;
	while(fgets(longueur_ligne, taille_ligne, fichier) != NULL)
	{
		champ_actuel=0;
		while (indice<nombre_client_actuel)
		{	
		    if(champ_actuel ==0 ){//nom
				fprintf(fichier,"%s,",client[champ_actuel].nom);
		    }
		    else if(champ_actuel==1)
	        {//prenom
				fprintf(fichier,"%s,",client[champ_actuel].prenom);
		    }
			else if(champ_actuel==2)
	        {//ville
		        fprintf(fichier,"%s,",client[champ_actuel].ville);
		    }
	        else if(champ_actuel==3)
	        {//code postal
		        fprintf(fichier,"%s,",client[champ_actuel].code_postal);
		    }
	        else if(champ_actuel==4)
	        {//telephone
		        fprintf(fichier,"%s,",client[champ_actuel].telephone);
		    }
	        else if(champ_actuel==5)
	        {//mail
		        fprintf(fichier,"%s,",client[champ_actuel].mail);
		    }
	        else if(champ_actuel==6)
	        {//metier
		        fprintf(fichier,"%s,",client[champ_actuel].metier);
		    }
			champ_actuel++;
		}	
		indice++;	
	}
	return EXIT_SUCCESS;
}

//----------------------------Programmes principaux----------------------------*/

int menu(Personne client[], int *nombre_client_actuel)
{
    int menu=0;
    while (menu!=6)
	{
        printf("Veuillez choisir ce que vous voulez faire :\n 1) Insérer ou modifier une personne \n 2) Supprimer une personne \n 3) Recherche des informations d'une personne \n 4) Filtrer \n 5) Lire le programme \n 6) Quitter le programme \n");
        scanf("%d",&menu);
        switch (menu)
		{
			case 1:
				critere_insertion(client,nombre_client_actuel);
				printf("Veuillez choisir ce que vous voulez faire :\n 1) Insérer ou modifier une personne \n 2) Supprimer une personne \n 3) Recherche des informations d'une personne \n 4) Filtrer \n 5) Lire le programme \n 6) Quitter le programme \n");
       		 	scanf("%d",&menu);
				break;
			case 2:
				critere_suppression(client,nombre_client_actuel);
				printf("Veuillez choisir ce que vous voulez faire :\n 1) Insérer ou modifier une personne \n 2) Supprimer une personne \n 3) Recherche des informations d'une personne \n 4) Filtrer \n 5) Lire le programme \n 6) Quitter le programme \n");
        		scanf("%d",&menu);
				break;
			case 3:
				information_personne(client,nombre_client_actuel);
				printf("Veuillez choisir ce que vous voulez faire :\n 1) Insérer ou modifier une personne \n 2) Supprimer une personne \n 3) Recherche des informations d'une personne \n 4) Filtrer \n 5) Lire le programme \n 6) Quitter le programme \n");
        		scanf("%d",&menu);
				break;
			case 4:
				choisir_filtre(client,nombre_client_actuel);
				printf("Veuillez choisir ce que vous voulez faire :\n 1) Insérer ou modifier une personne \n 2) Supprimer une personne \n 3) Recherche des informations d'une personne \n 4) Filtrer \n 5) Lire le programme \n 6) Quitter le programme \n");
        		scanf("%d",&menu);
				break;
			case 5:
				lecture(client);
				printf("Veuillez choisir ce que vous voulez faire :\n 1) Insérer ou modifier une personne \n 2) Supprimer une personne \n 3) Recherche des informations d'une personne \n 4) Filtrer \n 5) Lire le programme \n 6) Quitter le programme \n");
        		scanf("%d",&menu);
				break;
			case 6:
				ecriture_fichier_csv(client,nombre_client_actuel);
				return EXIT_SUCCESS;
			default:
				break;
		}
	}
	return EXIT_SUCCESS;
}


int remplissage_tableau(Personne client[], int *nombre_client_actuel)
{
	FILE *fichier = fopen(chemin,"r");
    char longueur_ligne[taille_ligne];
    char *token;
    int champ_actuel;
	int nb_client = 0;
	while(fgets(longueur_ligne, taille_ligne, fichier) != NULL)
	{
	    champ_actuel = 0;
	    char *copie_ligne = strdup(longueur_ligne);//dupliquer la chaîne ligne avec strdupa car le strsep modifie
	                                      //le pointeur passé, et nous ne voulons pas perdre la valeur d’origine
		while( (token = strsep(&copie_ligne, ",")) != NULL)
	    {
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
		nb_client++;
	}

	*nombre_client_actuel = nb_client;

	fclose(fichier);
	return EXIT_SUCCESS;
}