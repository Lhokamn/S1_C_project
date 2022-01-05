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
            while((strcmp(client[i].nom,client[pivot].nom)<=0) && (i < fin))
                i++;
            while((strcmp(client[j].nom,client[pivot].nom)>0))
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
            while((strcmp(client[i].prenom,client[pivot].prenom)<=0) && (i < fin))
                i++;
            while(strcmp(client[j].prenom,client[pivot].prenom)>0)
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
            while((strcmp(client[i].metier,client[pivot].metier)<=0) && (i < fin))
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
            while((strcmp(client[i].code_postal,client[pivot].code_postal)<=0) && i < fin)
                i++;
            while(strcmp(client[j].code_postal,client[pivot].code_postal)>0)
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


//On fait appel à une fonction créé plus tard, pour garder une structure du code
int recherche_dichotomique_telephone(Personne client[],Personne personne_rechercher[], char *prenomP, char *nomP, char *telP, int debut, int fin, int *milieu);

int lecture (Personne client[], int nb_client_actuel)
{
	int indice=0;
	while (indice<=nb_client_actuel)
	{
		printf("Prénom=%s",client[indice].prenom);
		printf("Nom=%s",client[indice].nom);
		printf("Ville=%s",client[indice].ville);
		printf("Code postal=%s",client[indice].code_postal);
		printf("Téléphone=%s",client[indice].telephone);
		printf("Mail=%s",client[indice].mail);
		printf("Métier=%s",client[indice].metier);
	}
	return EXIT_SUCCESS;
}

int ajout_dans_un_tableau(Personne client[], Personne tableau[],int indice_client, int indice_tableau)
{
	strcpy(tableau[indice_tableau].prenom,(client[indice_client].prenom));
	strcpy(tableau[indice_tableau].nom,(client[indice_client].nom));
	strcpy(tableau[indice_tableau].ville,(client[indice_client].ville));
	strcpy(tableau[indice_tableau].code_postal,(client[indice_client].code_postal));
	strcpy(tableau[indice_tableau].telephone,(client[indice_client].telephone));
	strcpy(tableau[indice_tableau].mail,(client[indice_client].mail));
	strcpy(tableau[indice_tableau].metier,(client[indice_client].metier));
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

int modification_client(Personne client[], Personne personne_trouve[],int milieu)
{
	int critere;
	char mot_a_remplacer[60];
	printf("Quel critère modifier ? \n 1) Prénom \n 2) Nom \n 3) Ville \n 4) Code postal \n 5) Téléphone \n 6) Mail \n 7) Métiers \n");
	scanf("%d",&critere);
	printf("Rentrez le nouveau élément\n");
	scanf("%s",mot_a_remplacer);
	switch (critere)
	{
		case 1:
			strcpy(personne_trouve[0].prenom,mot_a_remplacer);
			break;
		case 2:
			strcpy(personne_trouve[0].nom,mot_a_remplacer);
			break;
		case 3:
			strcpy(personne_trouve[0].ville,mot_a_remplacer);
			break;
		case 4:
			strcpy(personne_trouve[0].code_postal,mot_a_remplacer);
			break;
		case 5:
			strcpy(personne_trouve[0].telephone,mot_a_remplacer);
			break;
		case 6:
			strcpy(personne_trouve[0].mail,mot_a_remplacer);
			break;
		case 7:
			strcpy(personne_trouve[0].metier,mot_a_remplacer);
			break;
		default:
			break;
	}
	ajout_dans_un_tableau(client,personne_trouve,milieu,0);
	return EXIT_SUCCESS;
}

/*main switch 1*/

int critere_insertion(Personne client[],int *nombre_client_actuel)
{
	int insertion, nombre;
	int i=0;
	char prenom[45], nom[45], telephone[14];
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
		case 2: ;
			Personne *personne_rechercher;
			personne_rechercher=calloc(1,sizeof(char));
			printf("Rentrer le prénom, le nom de famille et le numéro de téléphone \n");
			fgets(prenom,size_of_buff,stdin);
			fgets(nom,size_of_buff,stdin);
			fgets(telephone,size_of_buff,stdin);
			int milieu=(0+*nombre_client_actuel)/2;
			recherche_dichotomique_telephone(client,personne_rechercher,prenom,nom,telephone,0,*nombre_client_actuel,&milieu);
			modification_client(client,personne_rechercher,milieu);
			free(personne_rechercher);
			break;
		default:
			break;
	}
	return EXIT_SUCCESS;
}

/*-----------------------------------Switch 2-----------------------------------*/

int suppression_client(Personne client[], Personne personne_trouver[], int milieu, int personne, int nombre_client_actuel)
{
	int i=milieu;
	int fin=1;
	while (fin==1)
	{
		if ((i+1)==nombre_client_actuel)
		{
			client=realloc(client,(nombre_client_actuel-1)*sizeof(char));
			fin=0;
		}
		Personne *client_a_decaler;
		client_a_decaler=calloc(1,sizeof(char));
		ajout_dans_un_tableau(client_a_decaler,client,0,i);
		free(client_a_decaler);
	}	
	return EXIT_SUCCESS;	
}

int critere_suppression(Personne client[],int *nombre_client_actuel)
{
	char prenom[45], nom[45], telephone[14];
	int milieu=((0+*nombre_client_actuel)/2);
	Personne *personne_rechercher;
	personne_rechercher=calloc(1,sizeof(char));

	printf("Rentrer le prénom, le nom de famille et le numéro de téléphone \n");
	fgets(prenom,size_of_buff,stdin);
	fgets(nom,size_of_buff,stdin);
	fgets(telephone,size_of_buff,stdin);
	quicksort_nom(client,0,nombre_client_actuel);	
	recherche_dichotomique_telephone(client,personne_rechercher,prenom,nom,telephone,0,nombre_client_actuel,&milieu);		
	suppression_client(client,personne_rechercher,milieu,0,nombre_client_actuel);
	free(personne_rechercher);
	return EXIT_SUCCESS;
}

/*-----------------------------------Switch 3-----------------------------------*/

/* Switch 3.1 */

//Il faut faire arriver à la fin à retourner le milieu pour pouvoir le réutiliser après

int recherche_dichotomique_telephone(Personne client[],Personne personne_rechercher[], char *prenomP, char *nomP, char *telP, int debut, int fin, int *milieu)
{	
	int milieu_dico=(debut+fin)/2;
	if ((strcmp(client[milieu_dico].prenom,prenomP)==0) && (strcmp(client[milieu_dico].nom,nomP)==0) && (strcmp(client[milieu_dico].telephone,telP)==0))
	{
		ajout_dans_un_tableau(client,personne_rechercher,milieu,0);
		return EXIT_SUCCESS;
	}
	if ((strcmp(client[milieu_dico].prenom,prenomP)<0) && (strcmp(client[milieu_dico].nom,nomP)<0) && (strcmp(client[milieu_dico].telephone,telP)<0))
	{
		recherche_dichotomique_telephone(client,personne_rechercher,prenomP,nomP,telP,debut,milieu-1,milieu_dico);
	}
	else if ((strcmp(client[milieu_dico].prenom,prenomP)>0) && (strcmp(client[milieu_dico].nom,nomP)>0) && (strcmp(client[milieu_dico].telephone,telP)>0))
	{
		recherche_dichotomique_telephone(client,personne_rechercher, prenomP,nomP,telP,milieu,fin,milieu_dico);
	}
	printf("La personne sélectionné n'existe pas\n");
	return EXIT_SUCCESS;
}

int recherche_dichotomique_mail(Personne client[],Personne personne_rechercher[], char *prenomP, char *nomP, char *mailP, int debut, int fin)
{
	int milieu=(debut+fin)/2;
	if ((strcmp(client[milieu].prenom,prenomP)==0) && (strcmp(client[milieu].nom,nomP)==0) && (strcmp(client[milieu].mail,mailP)==0))
	{
		Personne *personne_rechercher;
		personne_rechercher=calloc(1,sizeof(char));
		
		ajout_dans_un_tableau(client,personne_rechercher,milieu,0);

		lecture(personne_rechercher,1);
		free(personne_rechercher);
		return EXIT_SUCCESS;
	}
	if ((strcmp(client[milieu].prenom,prenomP)<0) && (strcmp(client[milieu].nom,nomP)<0) && (strcmp(client[milieu].mail,mailP)<0))
	{
		recherche_dichotomique_mail(client,personne_rechercher,prenomP,nomP,mailP,debut,milieu-1);
	}
	else if ((strcmp(client[milieu].prenom,prenomP)>0) && (strcmp(client[milieu].nom,nomP)>0) && (strcmp(client[milieu].mail,mailP)>0))
	{
		recherche_dichotomique_mail(client,personne_rechercher,prenomP,nomP,mailP,milieu,fin);
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
	scanf("%d",&critere_a_choisir);
	Personne *personne_rechercher;
	personne_rechercher=calloc(1,sizeof(char));
	if (critere_a_choisir==1)
	{
		printf("Rentrez le numéro de téléphone. Attention, il n'y a pas d'espace entre les nombres, il faut mettre un point : \n");
		scanf("%s",telP);
		int milieu=((0+nombre_client_actuel)/2);
		recherche_dichotomique_telephone(client,personne_rechercher,prenomP,nomP,telP,0,nombre_client_actuel,&milieu);
		lecture(personne_rechercher,1);
		free(personne_rechercher);
	}
	else
	{
		printf("Rentrez l'adresse mail : \n");
		scanf("%s",mailP);
		recherche_dichotomique_mail(client,personne_rechercher,prenomP,nomP,mailP,0,nombre_client_actuel);
	}
	return EXIT_SUCCESS;
}

/*-----------------------------------Switch 4-----------------------------------*/

int recherche_filtre_prenom(Personne client[], Personne client_filtre[], char critere)
{
	int indice=0, indice_filtre=0, nb_client_filtre;
	while ((strcmp(client[indice].prenom,critere)>=0)) 
	{
		if (strcmp(client[indice].prenom,critere)==0)
		{
			client_filtre=realloc(client_filtre,(nb_client_filtre+1)*sizeof(char));
			ajout_dans_un_tableau(client,client_filtre,indice,indice_filtre);
			indice_filtre++;
			nb_client_filtre++;
		}
		indice++;
	}
	lecture(client_filtre,nb_client_filtre);
	free(client_filtre);
	return EXIT_SUCCESS;
}

int recherche_filtre_nom(Personne client[], Personne client_filtre[], char critere)
{
	int indice=0, indice_filtre=0, nb_client_filtre;
	while ((strcmp(client[indice].nom,critere)>=0))
	{
		if (strcmp(client[indice].nom,critere)==0)
		{
			client_filtre=realloc(client_filtre,(nb_client_filtre+1)*sizeof(char));
			ajout_dans_un_tableau(client,client_filtre,indice,indice_filtre);
			indice_filtre++;
			nb_client_filtre++;
		}
		indice++;
	}
	lecture(client_filtre,nb_client_filtre);
	free(client_filtre);
	return EXIT_SUCCESS;
}

int recherche_filtre_metier(Personne client[], Personne client_filtre[], char critere)
{
	int indice=0, indice_filtre=0, nb_client_filtre;
	while ((strcmp(client[indice].metier,critere)>=0))
	{
		if (strcmp(client[indice].metier,critere)==0)
		{
			client_filtre=realloc(client_filtre,(nb_client_filtre+1)*sizeof(char));
			ajout_dans_un_tableau(client,client_filtre,indice,indice_filtre);
			indice_filtre++;
			nb_client_filtre++;
		}
		indice++;
	}
	lecture(client_filtre,nb_client_filtre);
	free(client_filtre);
	return EXIT_SUCCESS;
}

int recherche_filtre_code_postal(Personne client[], Personne client_filtre[], char critere)
{
	int indice=0, indice_filtre=0, nb_client_filtre;
	while ((strcmp(client[indice].code_postal,critere)<=0))
	{
		if (strcmp(client[indice].code_postal,critere)==0) 
		{
			client_filtre=realloc(client_filtre,(nb_client_filtre+1)*sizeof(char));
			ajout_dans_un_tableau(client,client_filtre,indice,indice_filtre);
			indice_filtre++;
			nb_client_filtre++;
		}
		indice++;
	}
	lecture(client_filtre,nb_client_filtre);
	free(client_filtre);
	return EXIT_SUCCESS;
}

int choisir_filtre(Personne client[],int *nombre_client_actuel)
{
	int filtre;
	char critere[60];

	Personne *client_filtre;
	client_filtre=calloc(0,sizeof(char));

	printf("Veuillez choisir l'élement à filtrer :\n 1) Prénom \n 2) Nom \n 3) Profession \n 4) Code postal \n");
    scanf("%d",&filtre);
	printf("Entrez le critère de filtre \n");
	fgets(critere,size_of_buff,stdin);
    switch (filtre)
	{
		case 1:
			quicksort_prenom(client,0,nombre_client_actuel);
			recherche_filtre_prenom(client,client_filtre,critere);
			break;
		case 2:
			quicksort_nom(client,0,nombre_client_actuel);
			recherche_filtre_nom(client,client_filtre, critere);
			break;
		case 3:
			quicksort_metier(client,0,nombre_client_actuel);
			recherche_filtre_metier(client,client_filtre, critere);
			break;
		case 4:
			quicksort_code_postal(client,0,nombre_client_actuel);
			recherche_filtre_code_postal(client,client_filtre, critere);
			break;
		default:
			break;
	}
	return EXIT_SUCCESS;
}

/*-----------------------------------Switch 5-----------------------------------*/

int affichage_client_sans_elements(Personne client[], int nombre_client_actuel)
{
	int indice=0;
	int nb_client_sans_element=0;
	Personne *client_sans_elements;
	client_sans_elements=calloc(nombre_client_actuel,sizeof(char));
	while (indice<nombre_client_actuel)
	{
		if ((client[indice].prenom==NULL) || (client[indice].nom==NULL) || (client[indice].ville==NULL) || (client[indice].code_postal==NULL) || (client[indice].telephone==NULL) || (client[indice].mail==NULL) || (client[indice].metier==NULL))
		{
			client_sans_elements=realloc(client_sans_elements,(nb_client_sans_element+1)*sizeof(char));
			ajout_dans_un_tableau(client,client_sans_elements,indice,nb_client_sans_element);
			nb_client_sans_element++;
		}
		indice++;
	}
	lecture(client_sans_elements,nb_client_sans_element);
	free(client_sans_elements);
	return EXIT_SUCCESS;
}

int affichage(Personne client[], int nombre_client_actuel)
{
	int affichage;
	printf("Voulez voir : \n 1) Tous les clients \n 2) Les clients a qui il manque un ou des éléments");
	scanf("%d",&affichage);
	switch (affichage)
	{
	case 1:
		lecture(client,nombre_client_actuel);
		break;
	case 2:
		affichage_client_sans_elements(client, nombre_client_actuel);
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
        printf("Veuillez choisir ce que vous voulez faire :\n 1) Insérer ou modifier une personne \n 2) Supprimer une personne \n 3) Recherche des informations d'une personne \n 4) Filtrer \n 5) Affichage \n 6) Quitter le programme \n");
        scanf("%d",&menu);
        switch (menu)
		{
			case 1:
				critere_insertion(client,nombre_client_actuel);
				printf("Veuillez choisir ce que vous voulez faire :\n 1) Insérer ou modifier une personne \n 2) Supprimer une personne \n 3) Recherche des informations d'une personne \n 4) Filtrer \n 5) Affichage \n 6) Quitter le programme \n");
       		 	scanf("%d",&menu);
				break;
			case 2:
				critere_suppression(client,nombre_client_actuel);
				printf("Veuillez choisir ce que vous voulez faire :\n 1) Insérer ou modifier une personne \n 2) Supprimer une personne \n 3) Recherche des informations d'une personne \n 4) Filtrer \n 5) Affichage \n 6) Quitter le programme \n");
        		scanf("%d",&menu);
				break;
			case 3:
				information_personne(client,nombre_client_actuel);
				printf("Veuillez choisir ce que vous voulez faire :\n 1) Insérer ou modifier une personne \n 2) Supprimer une personne \n 3) Recherche des informations d'une personne \n 4) Filtrer \n 5) Affichage \n 6) Quitter le programme \n");
        		scanf("%d",&menu);
				break;
			case 4:
				choisir_filtre(client,nombre_client_actuel);
				printf("Veuillez choisir ce que vous voulez faire :\n 1) Insérer ou modifier une personne \n 2) Supprimer une personne \n 3) Recherche des informations d'une personne \n 4) Filtrer \n 5) Affichage \n 6) Quitter le programme \n");
        		scanf("%d",&menu);
				break;
			case 5:
				affichage(client,nombre_client_actuel);
				printf("Veuillez choisir ce que vous voulez faire :\n 1) Insérer ou modifier une personne \n 2) Supprimer une personne \n 3) Recherche des informations d'une personne \n 4) Filtrer \n 5) affichage \n 6) Quitter le programme \n");
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
		printf("%s",token);
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