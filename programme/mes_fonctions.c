#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mes_variables.h"

//------------Algorithme de tri-------------- 

void quicksort_prenom(Personne client[], int depart, int fin)
{   
	int pivot, i, j;
	Personne tmp;
    if(depart < fin) 
	{
        pivot = depart;
        i = depart;
        j = fin;
        while (i < j) {
            while((strcmp(client[i].prenom,client[pivot].prenom)<=0) && (i < fin))
			{
				i++;
			}   
            while(strcmp(client[j].prenom,client[pivot].prenom)>0)
			{
				j--;
			}
            if(i < j) {
                tmp=client[i];
				client[i]=client[j];
				client[j]=tmp;
			}
        }
		tmp=client[pivot];
		client[pivot]=client[i];
		client[i]=tmp;
        quicksort_prenom(client, depart, i-1);
        quicksort_prenom(client, i+1, fin);

    }
}

void quicksort_nom(Personne client[], int depart, int fin)
{   
	int pivot, i, j;
	Personne tmp;
    if(depart < fin) {
        pivot = depart;
        i = depart;
        j = fin;
        while (i < j) {
            while((strcmp(client[i].nom,client[pivot].nom)<=0) && (i < fin))
			{
                i++;
			}
            while((strcmp(client[j].nom,client[pivot].nom)>0))
			{
                j--;
			}
            if(i < j) {
                tmp=client[i];
				client[i]=client[j];
				client[j]=tmp;
            }
        }
        tmp=client[pivot];
		client[pivot]=client[i];
		client[i]=tmp;
        quicksort_nom(client, depart, i-1);
        quicksort_nom(client, i+1, fin);
    }
}

void quicksort_metier(Personne client[], int depart, int fin)
{   
	int pivot, i, j;
	Personne tmp;
    if(depart < fin) {
        pivot = depart;
        i = depart;
        j = fin;
        while (i < j) {
            while((strcmp(client[i].metier,client[pivot].metier)<=0) && (i < fin))
			{
                i++;
			}
			while(client[j].metier > client[pivot].metier)
			{
                j--;
			}
            if(i < j) {
                tmp=client[i];
				client[i]=client[j];
				client[j]=tmp;
            }
        }
        tmp=client[pivot];
		client[pivot]=client[i];
		client[i]=tmp;
        quicksort_metier(client, depart, i-1);
        quicksort_metier(client, i+1, fin);
    }
}

void quicksort_code_postal(Personne client[], int depart, int fin)
{   
	int pivot, i, j;
	Personne tmp;
    if(depart < fin) {
        pivot = depart;
        i = depart;
        j = fin;
        while (i < j) {
            while((strcmp(client[i].code_postal,client[pivot].code_postal)<=0) && i < fin)
			{
                i++;
			}
			while(strcmp(client[j].code_postal,client[pivot].code_postal)>0)
			{
                j--;
			}
            if(i < j) {
                tmp=client[i];
				client[i]=client[j];
				client[j]=tmp;
            }
        }
        tmp=client[pivot];
		client[pivot]=client[i];
		client[i]=tmp;
        quicksort_code_postal(client, depart, i-1);
        quicksort_code_postal(client, i+1, fin);
    }
}

void quicksort_mail(Personne client[], int depart, int fin)
{   
	int pivot, i, j;
	Personne tmp;
    if(depart < fin) {
        pivot = depart;
        i = depart;
        j = fin;
        while (i < j) {
            while((strcmp(client[i].mail,client[pivot].mail)<=0) && i < fin)
			{
                i++;
			}
			while(strcmp(client[j].mail,client[pivot].mail)>0)
            {
			    j--;
			}
            if(i < j) {
                tmp=client[i];
				client[i]=client[j];
				client[j]=tmp;
            }
        }
        tmp=client[pivot];
		client[pivot]=client[i];
		client[i]=tmp;
        quicksort_mail(client, depart, i-1);
        quicksort_mail(client, i+1, fin);
    }
}

//--------------------------------------------


//On fait appel à une fonction créée plus tard, pour garder une structure du code
int recherche_dichotomique_telephone(Personne client[],Personne personne_rechercher[], char *prenomP, char *nomP, char *telP, int debut, int fin, int *milieu);

int lecture (Personne client[], int nb_client_actuel)
{
	int indice=0;
	while (indice<nb_client_actuel)
	{
		printf("\nclient n°=%d\n",indice);
		printf("Prénom=%s\n",client[indice].prenom);
		printf("Nom=%s\n",client[indice].nom);
		printf("Ville=%s\n",client[indice].ville);
		printf("Code postal=%s\n",client[indice].code_postal);
		printf("Téléphone=%s\n",client[indice].telephone);
		printf("Mail=%s\n",client[indice].mail);
		printf("Métier=%s\n",client[indice].metier);
		indice++;
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
	char nomP[46], prenomP[46], villeP[46], code_postalP[7], telephoneP[15], mailP[61], metierP[51];
	clock_t premier_temps, deuxieme_temps;
	float temps_total;
	printf("Insérez le prénom \n");
    scanf("%s",prenomP);
	printf("Insérez le nom \n");
    scanf("%s",nomP);
	printf("Insérez la ville \n");
    scanf("%s",villeP);
	printf("Insérez le code postal \n");
    scanf("%s",code_postalP);
	printf("Insérez le telephone. Attention les nombres sont séparés par des points \n");
    scanf("%s",telephoneP);
	printf("Insérez le mail \n");
    scanf("%s",mailP);
	printf("Insérez le metier \n");
    scanf("%s",metierP);
	premier_temps=clock();
	strcpy(client[*nombre_client_actuel].prenom,prenomP);
	strcpy(client[*nombre_client_actuel].nom,nomP);
	strcpy(client[*nombre_client_actuel].ville,villeP);
	strcpy(client[*nombre_client_actuel].code_postal,code_postalP);
	strcpy(client[*nombre_client_actuel].telephone,telephoneP);
	strcpy(client[*nombre_client_actuel].mail,mailP);
	strcpy(client[*nombre_client_actuel].metier,metierP);
	(*nombre_client_actuel)++;
	client=realloc(client,(*nombre_client_actuel)*sizeof(Personne));
	deuxieme_temps=clock();
	temps_total=(float)(deuxieme_temps-premier_temps);
	printf("Le temps d'insertion de la personne est de : %f s\n",(temps_total/CLOCKS_PER_SEC));
	return EXIT_SUCCESS;
}

/* switch 1.2 */

int modification_client(Personne client[], Personne personne_trouve[],int milieu)
{
	int critere;
	char mot_a_remplacer[61];
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
	clock_t premier_temps, deuxieme_temps;
	float temps_total;
	int i=0, test;
	char prenom[46], nom[46], telephone[15];
	printf("Que voulez faire ?: \n 1) Insérez tous les éléments d'une personne \n 2) Modifier une donnée d'une personne \n");
    scanf("%d",&insertion);
	premier_temps=clock();
	switch (insertion)
	{
		case 1:
			printf("combien de personne voulez vous ajouter ? \n");
			scanf("%d",&nombre);
			while (i<nombre)
			{
				insertion_personne(client,nombre_client_actuel);
				i++;
			}
			break;
		case 2: ;
			Personne *personne_rechercher;
			personne_rechercher=(Personne *)calloc(1,sizeof(Personne));
			printf("Rentrer le prénom, le nom de famille et le numéro de téléphone \n");
			scanf("%s %s %s",prenom,nom,telephone);
			int milieu=(0+*nombre_client_actuel)/2;
			printf("début recherche dicho\n");
			quicksort_nom(client,0,*nombre_client_actuel);
			test=recherche_dichotomique_telephone(client,personne_rechercher,prenom,nom,telephone,0,*nombre_client_actuel,&milieu);
			if (test==0)
			{
				printf("La fonction est ici\n");
				modification_client(client,personne_rechercher,milieu);
			}
			else
			{
				printf("La personne n'existe pas\n");
			}
			printf("Fin de la fonction dicho\n");
			free(personne_rechercher);
			break;
		default:
			break;
	}
	deuxieme_temps=clock();
	temps_total=(float)(deuxieme_temps-premier_temps);
	printf("temps d'execution du programme de modification=%f s\n",(temps_total/CLOCKS_PER_SEC));
	return EXIT_SUCCESS;
}

/*-----------------------------------Switch 2-----------------------------------*/

int suppression_client(Personne client[], int *milieu, int *nombre_client_actuel)
{
	int i=*milieu;
	int fin=1;
	while (fin==1)
	{
		if ((i+1)==*nombre_client_actuel)
		{
			(*nombre_client_actuel)--;
			client=realloc(client,(*nombre_client_actuel)*sizeof(Personne));
			return EXIT_SUCCESS;
		}
		Personne *client_a_decaler;
		client_a_decaler=(Personne *)calloc(1,sizeof(Personne));
		ajout_dans_un_tableau(client_a_decaler,client,0,i);
		free(client_a_decaler);
	}	
	return EXIT_SUCCESS;	
}

int critere_suppression(Personne client[],int *nombre_client_actuel)
{
	char prenom[46], nom[46], telephone[15];
	int milieu=((0+*nombre_client_actuel)/2), test;
	clock_t premier_temps, deuxieme_temps;
	float temps_total;
	Personne *personne_rechercher;
	personne_rechercher=(Personne *)calloc(1,sizeof(Personne));

	printf("Rentrer le prénom, le nom de famille et le numéro de téléphone \n");
	scanf("%s %s %s",prenom,nom,telephone);
	premier_temps=clock();
	quicksort_nom(client,0,*nombre_client_actuel);
	test=recherche_dichotomique_telephone(client,personne_rechercher,prenom,nom,telephone,0,*nombre_client_actuel,&milieu);	
	if (test==0)
	{
		suppression_client(client,&milieu,nombre_client_actuel);
	}
	else
	{
		printf("La personne n'existe pas");
	}
	free(personne_rechercher);
	deuxieme_temps=clock();
	temps_total=(float)(deuxieme_temps-premier_temps);
	printf("Le temps de suppression d'une personne est de : %f s\n",(temps_total/CLOCKS_PER_SEC));
	return EXIT_SUCCESS;
}

/*-----------------------------------Switch 3-----------------------------------*/

/* recherche dichotomique */

int recherche_dichotomique_telephone(Personne client[],Personne personne_rechercher[], char *prenomP, char *nomP, char *telP, int debut, int fin, int *milieu)
{    
	printf("Début de la recherche %i %i\n",debut,fin);
    int i,j;
    while (debut<fin)
	{
		printf("%i %i\n",debut,fin);
        (*milieu)=(debut+fin)/2;
		printf("%s %s \n",client[*milieu].nom,nomP);
        if (strcmp(client[*milieu].nom,nomP)==0)
        {
			printf("Le nom est bon\n");
            i=(*milieu), j=(*milieu);
            while ((strcmp(client[i].nom,nomP)==0) || (strcmp(client[j].nom,nomP)==0))
            {
				printf("i=%i, j=%i\n",i,j);
				printf("client[i]=%s,client[j]=%s\n",client[i].prenom,client[j].prenom);
                if ((strcmp(client[i].prenom,prenomP)==0) && (strcmp(client[i].telephone,telP)==0))
                {
                    (*milieu)=i;
					ajout_dans_un_tableau(client,personne_rechercher,(*milieu),0);
					printf("fonction dicho réussi\n");
            		return 0;
                }
                else if ((strcmp(client[j].prenom,prenomP)==0) && (strcmp(client[j].telephone,telP)==0))
                {
                    (*milieu)=j;
					ajout_dans_un_tableau(client,personne_rechercher,(*milieu),0);
					printf("fonction dicho réussi\n");
            		return 0;
                }
				i--;
            	j++;   
				printf("client[i]=%s,client[j]=%s\n",client[i].nom,client[j].nom);   
            }
			return 1;
        }
        else if (strcmp(client[*milieu].nom,nomP)>0)
        {
            fin=(*milieu);
        }
        else
        {
            debut=(*milieu)+1;
        }
    }
	printf("Sortie dicho\n");
    return 1;
}

int recherche_dichotomique_mail(Personne client[],Personne personne_rechercher[], char *prenomP, char *nomP, char *mailP, int debut, int fin)
{	
	int i,j,milieu;
	while (debut<=fin)
	{
		milieu=(debut+fin)/2;
		if (strcmp(client[milieu].nom,nomP)==0)
		{
			i=milieu, j=milieu;
			while ((strcmp(client[i].nom,nomP)==0)||(strcmp(client[j].nom,nomP)==0))
			{
				if ((strcmp(client[i].prenom,prenomP)==0) && (strcmp(client[i].mail,mailP)==0))
				{
					milieu=i;
					ajout_dans_un_tableau(client,personne_rechercher,milieu,0);
					return 0;
				}
				else if ((strcmp(client[j].prenom,prenomP)==0) && (strcmp(client[j].telephone,mailP)==0))
				{
					milieu=j;
					ajout_dans_un_tableau(client,personne_rechercher,milieu,0);
					return 0;
				}		
				i--;
				j++;
			}
			return 1;	
		}
		else if (strcmp(client[milieu].nom,nomP)>0)
		{
			fin=(milieu)-1;
		}
		else
		{
			debut=(milieu);
		}
	}
	return EXIT_FAILURE;
}

/* Switch 3.1 */

int recherche_tel(Personne client[],Personne personne_rechercher[], int *nombre_client_actuel, char *nomP, char *prenomP, char *telP)
{
	printf("Rentrez le numéro de téléphone. Attention, il n'y a pas d'espace entre les nombres, il faut mettre un point : \n");
	scanf("%s",telP);
	int milieu=(*nombre_client_actuel/2);
	quicksort_nom(client, 0, *nombre_client_actuel);
	if (recherche_dichotomique_telephone(client,personne_rechercher,prenomP,nomP,telP,0,*nombre_client_actuel,&milieu)==0)
	{
		lecture(personne_rechercher,1);
	}
	else
	{
		printf("La personne n'existe pas\n");
	}
	free(personne_rechercher);
	return EXIT_SUCCESS;
}

int recherche_mail(Personne client[],Personne personne_rechercher[], int *nombre_client_actuel, char *nomP, char *prenomP, char *mailP)
{
	printf("Rentrez l'adresse mail : \n");
	scanf("%s",mailP);
	quicksort_mail(client,0,*nombre_client_actuel);
	if (recherche_dichotomique_mail(client,personne_rechercher,prenomP,nomP,mailP,0,*nombre_client_actuel)==0)
	{
		lecture(personne_rechercher,1);
	}
	else
	{
		printf("La personne n'existe pas\n");
	}
	free(personne_rechercher);
	return EXIT_SUCCESS;
}

/*main switch 3*/

int information_personne(Personne client[],int *nombre_client_actuel)
{
	char nomP[46], prenomP[46], mailP[61], telP[15];
	int critere_a_choisir;
	clock_t premier_temps, deuxieme_temps;
	float temps_total;
	printf("Rentrez le Prénom et le nom de la personne :\n");
	scanf("%s %s",prenomP,nomP);
	printf("Vous connaissez le numéro de téléphone ou l'adresse mail ? \n 1) Le numéro de téléphone \n 2) L'adresse mail\n");
	scanf("%d",&critere_a_choisir);
	Personne *personne_rechercher;
	personne_rechercher=(Personne *)calloc(1,sizeof(Personne));
	premier_temps=clock();
	quicksort_nom(client,0,*nombre_client_actuel);
	if (critere_a_choisir==1)
	{
		recherche_tel(client, personne_rechercher,nombre_client_actuel,nomP,prenomP,telP);
	}
	else
	{
		recherche_mail(client, personne_rechercher,nombre_client_actuel,nomP,prenomP,mailP);
	}
	deuxieme_temps=clock();
	temps_total=(float)(deuxieme_temps-premier_temps);
	printf("Le temps pour rechercher une personne est de : %f s\n",(temps_total/CLOCKS_PER_SEC));
	return EXIT_SUCCESS;
}

/*-----------------------------------Switch 4-----------------------------------*/


int recherche_filtre_prenom(Personne client[], Personne client_filtre[], char *critere, int *nombre_client_actuel)
{
	int indice=0, indice_filtre=0, nb_client_filtre=0;
	char *comparaison;
	while (indice<*nombre_client_actuel) 
	{	
		comparaison=strstr(client[indice].prenom,critere);
		if (comparaison!=NULL)
		{
			nb_client_filtre++;
			client_filtre=realloc(client_filtre,(nb_client_filtre)*sizeof(Personne));
			ajout_dans_un_tableau(client,client_filtre,indice,indice_filtre);
			indice_filtre++;
		}
		indice++;
	}
	lecture(client_filtre,nb_client_filtre);
	free(client_filtre);
	return EXIT_SUCCESS;
}

int recherche_filtre_nom(Personne client[], Personne client_filtre[], char *critere, int *nombre_client_actuel)
{
	int indice=0, indice_filtre=0, nb_client_filtre=0;
	char *comparaison;
	while (indice<*nombre_client_actuel)
	{
		comparaison=strstr(client[indice].nom,critere);
		if (comparaison!=NULL)
		{
			nb_client_filtre++;
			client_filtre=realloc(client_filtre,(nb_client_filtre+1)*sizeof(Personne));
			ajout_dans_un_tableau(client,client_filtre,indice,indice_filtre);
			indice_filtre++;
		}
		indice++;
	}
	lecture(client_filtre,nb_client_filtre);
	free(client_filtre);
	return EXIT_SUCCESS;
}

int recherche_filtre_metier(Personne client[], Personne client_filtre[], char *critere, int *nombre_client_actuel)
{
	int indice=0, indice_filtre=0, nb_client_filtre=0;
	char *comparaison;
	while (indice<*nombre_client_actuel)
	{
		comparaison=strstr(client[indice].metier,critere);
		if (comparaison!=NULL)
		{
			nb_client_filtre++;
			client_filtre=realloc(client_filtre,(nb_client_filtre+1)*sizeof(Personne));
			ajout_dans_un_tableau(client,client_filtre,indice,indice_filtre);
			indice_filtre++;
		}
		indice++;
	}
	lecture(client_filtre,nb_client_filtre);
	free(client_filtre);
	return EXIT_SUCCESS;
}

int recherche_filtre_code_postal(Personne client[], Personne client_filtre[], char *critere, int *nombre_client_actuel)
{
	int indice=0, indice_filtre=0, nb_client_filtre=0;
	char *comparaison;
	while (indice<*nombre_client_actuel)
	{
		comparaison=strstr(client[indice].code_postal,critere);
		if (comparaison!=NULL)
		{
			nb_client_filtre++;
			client_filtre=realloc(client_filtre,(nb_client_filtre+1)*sizeof(Personne));
			ajout_dans_un_tableau(client,client_filtre,indice,indice_filtre);
			indice_filtre++;
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
	char critere[61];
	clock_t premier_temps, deuxieme_temps;
	float temps_total;

	Personne *client_filtre;
	client_filtre=(Personne *)calloc(1,sizeof(Personne));

	printf("Veuillez choisir l'élement à filtrer :\n 1) Prénom \n 2) Nom \n 3) Profession \n 4) Code postal \n");
    scanf("%d",&filtre);
	printf("Entrez le critère de filtre \n");
	scanf("%s",critere);
	premier_temps=clock();
    switch (filtre)
	{
		case 1:
			quicksort_prenom(client,0,*nombre_client_actuel);
			recherche_filtre_prenom(client,client_filtre,critere,nombre_client_actuel);
			break;
		case 2:
			quicksort_nom(client,0,*nombre_client_actuel);
			lecture(client,*nombre_client_actuel);
			// recherche_filtre_nom(client,client_filtre,critere,nombre_client_actuel);
			break;
		case 3:
			quicksort_metier(client,0,*nombre_client_actuel);
			recherche_filtre_metier(client,client_filtre,critere,nombre_client_actuel);
			break;
		case 4:
			quicksort_code_postal(client,0,*nombre_client_actuel);
			recherche_filtre_code_postal(client,client_filtre,critere,nombre_client_actuel);
			break;
		default:
			break;
	}
	deuxieme_temps=clock();
	temps_total=(float)(deuxieme_temps-premier_temps);
	printf("Le temps pour filtrer la liste de client est de : %f s\n",(temps_total/CLOCKS_PER_SEC));
	return EXIT_SUCCESS;
}

/*-----------------------------------Switch 5-----------------------------------*/

int affichage_client_sans_elements(Personne client[], int *nombre_client_actuel)
{
	int indice=0, number=0;
	int nb_client_sans_element=0;
	Personne *client_sans_elements;
	client_sans_elements=(Personne *)calloc(*nombre_client_actuel,sizeof(Personne));
	char comparaison=number + '\0';
	while (indice<*nombre_client_actuel)
	{
		printf("rentre dans la boucle\n");
		if ((strcmp(client[indice].prenom,&comparaison)==0) || (strcmp(client[indice].nom,&comparaison)==0) || (strcmp(client[indice].ville,&comparaison)==0) || (strcmp(client[indice].code_postal,&comparaison)==0) || (strcmp(client[indice].telephone,&comparaison)==0) || (strcmp(client[indice].mail,&comparaison)==0) || (strcmp(client[indice].metier,&comparaison)==0))
		{
			client_sans_elements=realloc(client_sans_elements,(nb_client_sans_element+1)*sizeof(Personne));
			ajout_dans_un_tableau(client,client_sans_elements,indice,nb_client_sans_element);
			nb_client_sans_element++;
		}
		indice++;
	}
	lecture(client_sans_elements,nb_client_sans_element);
	free(client_sans_elements);
	return EXIT_SUCCESS;
}

int affichage(Personne client[], int *nombre_client_actuel)
{
	int affichage;
	clock_t premier_temps, deuxieme_temps;
	float temps_total;
	printf("Voulez voir : \n 1) Tous les clients \n 2) Les clients a qui il manque un ou des éléments\n");
	scanf("%d",&affichage);
	premier_temps=clock();
	switch (affichage)
	{
	case 1:
		lecture(client,*nombre_client_actuel);
		break;
	case 2:
		affichage_client_sans_elements(client, nombre_client_actuel);
		break;
	default:
		break;
	}
	deuxieme_temps=clock();
	temps_total=(float)(deuxieme_temps-premier_temps);
	printf("Le temps d'affichage est de : %f s\n",(temps_total/CLOCKS_PER_SEC));
	return EXIT_SUCCESS;
}

/*-----------------------------------Switch 6-----------------------------------*/
int ecriture_fichier_csv(Personne client[],int nombre_client_actuel)
{
	clock_t premier_temps, deuxieme_temps;
	float temps_total;
	premier_temps=clock();
	FILE *fichier = fopen(chemin,"w+");
	int indice=0;
	// quicksort_prenom(client,0,nombre_client_actuel);
	while(indice<taille_tableau)
	{
		
		fprintf(fichier,"%s,%s,%s,%s,%s,%s,%s",client[indice].prenom,client[indice].nom,client[indice].ville,client[indice].code_postal,client[indice].telephone,client[indice].mail,client[indice].metier);
		indice++;	
	}
	while (indice<nombre_client_actuel)
	{
		fprintf(fichier,"\n%s,%s,%s,%s,%s,%s,%s",client[indice].prenom,client[indice].nom,client[indice].ville,client[indice].code_postal,client[indice].telephone,client[indice].mail,client[indice].metier);
		indice++;
	}
	
	fclose(fichier);
	deuxieme_temps=clock();
	temps_total=(float)(deuxieme_temps-premier_temps);
	printf("Le temps de réécriture du fichier est de : %f",(temps_total/CLOCKS_PER_SEC));
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
				break;
			case 2:
				critere_suppression(client,nombre_client_actuel);
				break;
			case 3:
				information_personne(client,nombre_client_actuel);
				break;
			case 4:
				choisir_filtre(client,nombre_client_actuel);
				break;
			case 5:
				affichage(client,nombre_client_actuel);
				break;
			case 6:
				ecriture_fichier_csv(client,*nombre_client_actuel);
				return EXIT_SUCCESS;
			default:
				break;
		}
		if (menu==6)
		{
			ecriture_fichier_csv(client,*nombre_client_actuel);
		}
	}
	return EXIT_SUCCESS;
}

int remplissage_tableau(Personne client[taille_tableau], int *nombre_client_actuel)
{
	FILE *fichier = fopen(chemin,"r");
    char ligne[taille_ligne];
    char *token;
    int champ_actuel;
	while(fgets(ligne, taille_ligne, fichier) != NULL)
	{
	    champ_actuel = 0;
	    char *copie_ligne = strdup(ligne);//dupliquer la chaîne ligne avec strdup car le strsep modifie
	                                      //le pointeur passé, et nous ne voulons pas perdre la valeur 
									  
		while( (token = strsep(&copie_ligne, ",")) != NULL)
	    {
		    if(*token == '\n')
		    {
		    	//ne rien faire
		    }
		    else if(token == NULL)
			{	
				//ne rien faire
			}
		    else{
			
		    	if(champ_actuel ==0 ){//pre
					strcpy(client[*nombre_client_actuel].prenom,token);
		    	}
		    	else if(champ_actuel==1)
	            {//nom
					strcpy(client[*nombre_client_actuel].nom,token);
		    	}
				else if(champ_actuel==2)
	            {//ville
		    	    strcpy(client[*nombre_client_actuel].ville,token);
		    	}
	            else if(champ_actuel==3)
	            {//code postal
		    	    strcpy(client[*nombre_client_actuel].code_postal,token);
		    	}
	            else if(champ_actuel==4)
	            {//telephone
		    	    strcpy(client[*nombre_client_actuel].telephone,token);
		    	}
	            else if(champ_actuel==5)
	            {//mail
		    	    strcpy(client[*nombre_client_actuel].mail,token);
		    	}
	            else if(champ_actuel==6)
	            {//metier
		    	    strcpy(client[*nombre_client_actuel].metier,token);
		    	}
		    }
		    champ_actuel++;
	    }
		(*nombre_client_actuel)++;	
	}
	fclose(fichier);
	return EXIT_SUCCESS;
}