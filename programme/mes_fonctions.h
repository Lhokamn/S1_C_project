#include "mes_variables.h"

/*
entrée : tableau de structure
sortie :
pré-condition :
post-condition :
*/

/*
entrée : tableau de structure, int *
sortie : un tableau 
pré-condition : aucune
post-condition : retourne un tableau avec les valeurs du fichier CSV
*/
int remplissage_tableau(Personne client[],int *nombre_client_actuel);

/*
entrée : tableau de structure, int *
sortie : entier
pré-condition : aucune
post-condition : se termine quand l'utilisateur veut terminer le programme
*/
int menu(Personne client[],int *nombre_client_actuel);

/*-------------------------Fonction de tri----------------------------------------------------*/

/*
entrée : tableau de structure, int, int
sortie : tableau de structure
pré-condition : aucune
post-condition : retourne le tableau par son critère
*/
void quicksort_nom(Personne client[], int depart, int fin);
void quicksort_prenom(Personne client[], int depart, int fin);
void quicksort_metier(Personne client[], int depart, int fin);
void quicksort_code_postal(Personne client[], int depart, int fin);
void quicksort_mail(Personne client[], int depart, int fin);

/*
entrée : char *, char *
sortie : char char
pré-condition : aucune
post-condition : échange les deux éléments
*/
void permuter(char *element1, char *element2);

//-------------------------------------------

/*
entrée : tableau de structure, char *, char *
sortie : tableau de structure
pré-condion : aucune
post-condition : appelle une autre fonction 
*/
int critere_recherche(Personne client[], char *nom, char *telephone);


/*------------------------- Fonction Switch 1 ----------------------------------------------------*/


/* Switch 1.1 */
/*
entrée : tableau de structure, int *
sortie : tableau de structure
pré-condition : aucune
post-condition : rajoute une personne au tableau
*/
int insertion_personne(Personne client [],int *nombre_client_actuel);

/* switch 1.2 */

/*
entrée : tableau de structure, int
sortie : tableau de structure
pré-condition : aucune
post-condition : modifie une personne du tableau
*/
int modification_client(Personne client[],int champ_actuel);

/*
entrée :tableau de structure, char *, char *
sortie : booléen
pré-condition : aucune
post-condition : execute la fonction modification-client ssi le client existe
*/
int verification_client(Personne client[], char *nom, char *telephone);

/*main switch 1*/

/*
entrée : tableau de structure, int *
sortie : booléen
pré-condition : aucune
post-condition : lance au choix la modification ou l'insertion d'un client
*/
int critere_insertion(Personne client[],int *nombre_client_actuel);

/*------------------------- Fonction Switch 2 ----------------------------------------------------*/

/*
entrée : tableau de structure, char *, char *, int *
sortie : tableau de structure
pré-condition : aucune
post-condition : retourne le tableau de structure avec un client en moins si le client existe
*/
int suppression_client(Personne client[], char *nom, char *telephone,int *nombre_client_actuel);

/*
entrée : tableau de structure, int *
sortie : booléen
pré-condition : aucune
post-condition : execute les programmes pour supprimer un client
*/
int critere_suppression(Personne client[],int *nombre_client_actuel);

/*------------------------- Fonction Switch 3 ----------------------------------------------------*/

/*Switch 3.1*/
/*
entrée : tableau de structure, char, char, char int, int
sortie : tableau de structure
pré-condition : aucune
post-condition : retourne le client qui possède les éléments choisi
*/
int recherche_dichotomique(Personne client[], char prenomP, char nomP, char caracteristiqueP, int debut, int fin);

/*main switch 3*/
/*
entrée : tableau de structure, int
sortie : int
pré-condition : aucune
post-condition : appelle des fonctions 
*/
int information_personne(Personne client[],int nombre_client_actuel);

/*------------------------- Fonction Switch 4 ----------------------------------------------------*/

/*
entrée : tableau de structure, tableau de structure
sortie : tableau de structure
pré-condition : aucune
post-condition : retourne un tableau de structure avec tous les clients qui correspondent au filtre
*/
int recherche_filtre(Personne client[], Personne client_filtre[]);

/*
entrée : tableau de structure, char
sortie : booléen
pré-condition : aucune
post-condition : execute les fonctions de filtres
*/
int lancement_filtre(Personne client[], char critere);

/*
entrée : tableau de structure
sortie : int
pré-condition : aucune
post-condition : appelle d'autres fonctions
*/
int choisir_filtre(Personne client[]);

/*------------------------- Fonction Switch 5 ----------------------------------------------------*/

/*
entrée : tableau de structure
sortie : tableau de structure
pré-condition : aucune
post-condition : lit tout le tableau
*/
int lecture (Personne client[]);

/*------------------------- Fonction Switch 6 ----------------------------------------------------*/

/*
entrée : tableau de structure, int
sortie : .csv
pré-condition : aucune
post-condition : réécris sur le fichier CSV tous les changements
*/
int ecriture_fichier_csv(Personne client[],int nombre_client_actuel);