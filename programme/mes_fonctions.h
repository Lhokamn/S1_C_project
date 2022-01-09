#include "mes_variables.h"

/*
entrée : tableau de structure
sortie :
pré-condition :
post-condition :
*/


/*-------------------------Fonction de tri----------------------------------------------------*/

/*
entrée : tableau de structure, int, int
sortie : tableau de structure
pré-condition : aucune
post-condition : retourne le tableau trié par le critère choisi
*/
void quicksort_nom(Personne client[], int depart, int fin);
void quicksort_prenom(Personne client[], int depart, int fin);
void quicksort_metier(Personne client[], int depart, int fin);
void quicksort_code_postal(Personne client[], int depart, int fin);
void quicksort_mail(Personne client[], int depart, int fin);

//--------------------------------------------

/*
entrée : tableau de structure
sortie : tableau de structure
pré-condition : aucune
post-condition : lit tout le tableau
*/
int lecture (Personne client[], int nb_client_actuel);

/*
entrée : tableau de structure, tableau de structure, int, int
sortie : tableau de structure
pré-condition : aucune
post-condition : retourne dans le deuxième tableau, la valeur du premier tableau d'indice_client
*/

int ajout_dans_un_tableau(Personne client[], Personne tableau[],int indice_client, int indice_tableau);


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
entrée : tableau de structure, tableau de structure, int
sortie : tableau de structure
pré-condition : aucune
post-condition : modifie une personne du tableau
*/
int modification_client(Personne client[],Personne personne_trouve[],int champ_actuel);

/*main switch 1*/

/*
entrée : tableau de structure, int *
sortie : rien
pré-condition : aucune
post-condition : lance au choix la modification ou l'insertion d'un client
*/
int critere_insertion(Personne client[],int *nombre_client_actuel);

/*------------------------- Fonction Switch 2 ----------------------------------------------------*/

/*
entrée : tableau de structure, int *, int *
sortie : tableau de structure
pré-condition : aucune
post-condition : retourne le tableau de structure avec un client en moins si le client existe
*/
int suppression_client(Personne client[], int *milieu,int *nombre_client_actuel);

/*
entrée : tableau de structure, int *
sortie : rien
pré-condition : aucune
post-condition : execute les programmes pour supprimer un client
*/
int critere_suppression(Personne client[],int *nombre_client_actuel);

/*------------------------- Fonction Switch 3 ----------------------------------------------------*/

/*Switch 3.1*/
/*
entrée : tableau de structure,tableau de structure char, char, char int, int, int*
sortie : tableau de structure
pré-condition : aucune
post-condition : retourne le client qui possède les éléments choisi et son indice
*/
int recherche_dichotomique_tel(Personne client[],Personne personne_rechercher[], char *prenomP, char *nomP, char *telP, int debut, int fin, int *milieu);

/*
entrée : tableau de structure,tableau de structure char, char, char int, int
sortie : tableau de structure
pré-condition : aucune
post-condition : retourne le client qui possède les éléments choisi et son indice
*/
int recherche_dichotomique_mail(Personne client[],Personne personne_rechercher[], char *prenomP, char *nomP, char *mailP, int debut, int fin);

/* Switch 3.1 */

/*
entrée : tableau de structure, tableau de structure, int*, char*,char*,char*
sortie : tableau de structure
pré-condition : aucune
post-condition : affiche un tableau de structure de 1 client correspondant à nos trois critères
*/
int recherche_tel(Personne client[],Personne personne_rechercher[], int *nombre_client_actuel, char *nomP, char *prenomP, char *telP);
int recherche_mail(Personne client[],Personne personne_rechercher[], int *nombre_client_actuel, char *nomP, char *prenomP, char *telP);

/*main switch 3*/
/*
entrée : tableau de structure, int
sortie : rien
pré-condition : aucune
post-condition : appelle des fonctions 
*/
int information_personne(Personne client[],int nombre_client_actuel);

/*------------------------- Fonction Switch 4 ----------------------------------------------------*/

/*
entrée : tableau de structure, tableau de structure,char*, int *
sortie : tableau de structure
pré-condition : aucune
post-condition : retourne un tableau de structure avec tous les clients qui correspondent au filtre
*/
int recherche_filtre_prenom(Personne client[], Personne client_filtre[], char *critere, int *nombre_client_actuel);
int recherche_filtre_nom(Personne client[], Personne client_filtre[], char *critere, int *nombre_client_actuel);
int recherche_filtre_metier(Personne client[], Personne client_filtre[], char *critere, int *nombre_client_actuel);
int recherche_filtre_nom_code_postal(Personne client[], Personne client_filtre[], char *critere, int *nombre_client_actuel);

/*
entrée : tableau de structure, int*
sortie : rien
pré-condition : aucune
post-condition : appelle d'autres fonctions
*/
int choisir_filtre(Personne client[], int *nombre_client_actuel);

/*------------------------- Fonction Switch 5 ----------------------------------------------------*/

/*
entrée : tableau de structure, int*
sortie : tableau de structure
pré-condition : aucune
post-condition : retourne toutes les personnes a qui il manque au moins un élément
*/
int affichage_client_sans_elements(Personne client[], int *nombre_client_actuel);

/*
entrée : tableau de structure, int*
sortie : rien
pré-condition : aucune
post-condition : lance d'autre fonction
*/
int affichage(Personne client[], int *nombre_client_actuel);

/*------------------------- Fonction Switch 6 ----------------------------------------------------*/

/*
entrée : tableau de structure, int
sortie : .csv
pré-condition : aucune
post-condition : réécris sur le fichier CSV tous les changements
*/
int ecriture_fichier_csv(Personne client[],int nombre_client_actuel);

//--------------------------------------------

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
