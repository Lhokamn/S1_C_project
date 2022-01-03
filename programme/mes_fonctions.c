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
			
		    	if(champ_actuel ==0 ){//prénom
					printf("Prénom=%s",token);
		    	}
		    	else if(champ_actuel==1)
	            {//nom
					printf("Nnom=%s",token);
		    	}
				else if(champ_actuel==2)
	            {//ville
					printf("Ville=%s",token);
		    	}
	            else if(champ_actuel==3)
	            {//code postal
					printf("Code postal=%s",token);
		    	}
	            else if(champ_actuel==4)
	            {//telephone
					printf("Téléphone=%s",token);
		    	}
	            else if(champ_actuel==5)
	            {//mail
					printf("Mail=%s",token);
		    	}
	            else if(champ_actuel==6)
	            {//metier
					printf("Métier=%s",token);
		    	}
		    }
			printf("\n");
		    champ_actuel++;
	    }
	}
	fclose(fichier);
	return EXIT_SUCCESS;
}

/*-----------------------------------Switch 1-----------------------------------*/

/* Switch 1.1 */

int insertion_personne(Personne client [],int *nombre_client_actuel)
{
	char nomP[45], prenomP[45], villeP[45], code_postalP[6], telephoneP[14], mailP[60], metierP[50];
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
	char nom[45], telephone[14];
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
int recherche_dichotomique(Personne client[], char prenomP, char nomP, char caracteristiqueP, int debut, int fin)
{
	int milieu=(debut+fin)/2;
	if ((client[milieu].prenom==prenomP) && (client[milieu].nom==nomP) && (client[milieu].caracteristique==caracteristiqueP))
	{
		Personne *personne_rechercher;
		personne_rechercher=calloc(1,sizeof(char));
		strcpy(personne_rechercher[0].prenom,(client[milieu].prenom));
		strcpy(personne_rechercher[0].nom,(client[milieu].nom));
		strcpy(personne_rechercher[0].ville,(client[milieu].ville));
		strcpy(personne_rechercher[0].code_postal,(client[milieu].code_postal));
		strcpy(personne_rechercher[0].telephone,(client[milieu].telephone));
		strcpy(personne_rechercher[0].mail,(client[milieu].mail));
		strcpy(personne_rechercher[0].metier,(client[milieu].metier));
		lecture(personne_rechercher);
		free(personne_rechercher);
		return EXIT_SUCCESS;
	}
	if ((client[milieu].prenom==prenomP) && (client[milieu].nom==nomP) && (client[milieu].caracteristique<caracteristiqueP))
	{
		recherche_dichotomique(client,prenomP,nomP,caracteristiqueP,debut,milieu-1);
	}
	else if ((client[milieu].prenom==prenomP) && (client[milieu].nom==nomP) && (client[milieu].caracteristique>caracteristiqueP))
	{
		recherche_dichotomique(client,prenomP,nomP,caracteristiqueP,milieu,fin);
	}
	printf("La personne sélectionné n'existe pas\n");
	return EXIT_SUCCESS;
}

/*main switch 3*/

int information_personne(Personne client[],int nombre_client_actuel)
{
	char nomP[45], prenomP[45], mailP[60], telP[14];
	int critere_a_choisir;
	printf("Rentrez le Prénom et le nom de la personne :\n");
	scanf("%s %s",prenomP,nomP);
	printf("Vous connaissez le numéro de téléphone ou l'adresse mail ? \n 1) Le numéro de téléphone \n L'adresse mail");
	scanf("%d",critere_a_choisir);
	if (critere_a_choisir==1)
	{
		printf("Rentrez le numéro de téléphone. Attention, il n'y a pas d'espace entre les nombres, il faut mettre un point : \n");
		scanf("%s",telP);
		recherche_dichotomique(client,prenomP,nomP,telP,0,nombre_client_actuel);
	}
	else
	{
		printf("Rentrez l'adresse mail : \n");
		scanf("%s",mailP);
		recherche_dichotomique(client,prenomP,nomP,mailP,0,nombre_client_actuel);
	}
	return EXIT_SUCCESS;
}

/*-----------------------------------Switch 4-----------------------------------*/


int recherche_filtre(Personne client[], Personne client_filtre[], char critere)
{
	int indice=0, indice_filtre=0, nb_client_filtre;
	while (indice<taille_tableau) //a modifier
	{
		if (client[indice].caracteristique==critere) //caractéristique est à définir pour écrire qu'une seule fonction ( appliquer ensuite à quichsort)
		{
			client_filtre=realloc(client_filtre,(nb_client_filtre+1)*sizeof(char));
			strcpy(client_filtre[indice_filtre].prenom,(client[indice].prenom));
			strcpy(client_filtre[indice_filtre].nom,(client[indice].nom));
			strcpy(client_filtre[indice_filtre].ville,(client[indice].ville));
			strcpy(client_filtre[indice_filtre].code_postal,(client[indice].code_postal));
			strcpy(client_filtre[indice_filtre].telephone,(client[indice].telephone));
			strcpy(client_filtre[indice_filtre].mail,(client[indice].mail));
			strcpy(client_filtre[indice_filtre].metier,(client[indice].metier));
			indice_filtre++;
			nb_client_filtre++;
		}
		indice++;
		if (client[indice].caracteristique>critere)
		{
			lecture(client_filtre);
			free(client_filtre);
			return EXIT_SUCCESS;
		}
	}
}

int lancement_filtre(Personne client[], char critere)
{
	Personne *client_filtre;
	client_filtre=calloc(0,sizeof(char));

	recherche_filtre(client,client_filtre,critere);
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
			lancement_filtre(client, critere);
			break;
		case 2:
			quicksort_prenom(client,0,nombre_client_actuel);
			lancement_filtre(client, critere);
			break;
		case 3:
			quicksort_metier(client,0,nombre_client_actuel);
			lancement_filtre(client, critere);
			break;
		case 4:
			quicksort_code_postal(client,0,nombre_client_actuel);
			lancement_filtre(client, critere);
			break;
		default:
			break;
	}
	return EXIT_SUCCESS;
}

/*-----------------------------------Switch 5-----------------------------------*/

int affichage_client_sans_éléments(Personne client[], int nombre_client_actuel)
{
	int indice=0;
	Personne *client_sans_elements;
	client_sans_elements=calloc(nombre_client_actuel,sizeof(char));
	while (indice<nombre_client_actuel)
	{
		if ((client[indice].prenom==NULL) || (client[indice].nom==NULL) || (client[indice].ville==NULL) || (client[indice].code_postal==NULL) || (client[indice].telephone==NULL) || (client[indice].mail==NULL) || (client[indice].metier==NULL))
		{
			strcpy(client_sans_elements[indice].prenom,(client[indice].prenom));
			strcpy(client_sans_elements[indice].nom,(client[indice].nom));
			strcpy(client_sans_elements[indice].ville,(client[indice].ville));
			strcpy(client_sans_elements[indice].code_postal,(client[indice].code_postal));
			strcpy(client_sans_elements[indice].telephone,(client[indice].telephone));
			strcpy(client_sans_elements[indice].mail,(client[indice].mail));
			strcpy(client_sans_elements[indice].metier,(client[indice].metier));
		}
		indice++;
	}
	lecture(client_sans_elements);
	free(client_sans_elements);
	return EXIT_SUCCESS;
}


int affichage(Personne client[], int nombre_client_actuel)
{
	int affichage;
	printf("Voulez voir : \n 1) Tous les clients \n 2) les clients a qui il manque un ou des éléments");
	scanf("%d",&affichage);
	switch (affichage)
	{
	case 1:
		lecture(client);
		break;
	case 2:
		affichage_client_sans_éléments(client, nombre_client_actuel);
		break;
	default:
		break;
	}
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
	fclose(fichier);
	return EXIT_SUCCESS;
}

//----------------------------Programmes principaux----------------------------*/

int menu(Personne client[], int *nombre_client_actuel)
{
    int menu=0;
    while (menu!=6)
	{
        printf("Veuillez choisir ce que vous voulez faire :\n 1) Insérer ou modifier une personne \n 2) Supprimer une personne \n 3) Recherche des informations d'une personne \n 4) Filtrer \n 5) affichage \n 6) Quitter le programme \n");
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
				affichage(client,nombre_client_actuel);
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
			
		    	if(champ_actuel ==0 ){//pre
					strcpy(client[champ_actuel].prenom,token);
		    	}
		    	else if(champ_actuel==1)
	            {//nom
					strcpy(client[champ_actuel].nom,token);
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