#include "mes_variables.h"

/*
entrée :
sortie :
pré-condition :
post-condition :
*/

/*
entrée : tableau de structure
sortie : un tableau 
pré-condition : aucune
post-condition : retourne un tableau avec les valeurs du fichier CSV
*/
int remplissage_tableau(Personne client[]);

/*
entrée : tableau de structure
sortie : entier
pré-condition : aucune
post-condition : se termine quand l'utilisateur veut terminer le programme
*/
int menu(Personne client[]);

/*
entrée : tableau de structure, int indice, int depart, int fin
sortie : tableau de structure
pré-condition : que 0<indice<6
post-condition : retourne le tableau triée selon la catégorie choisi
*/
void quicksort(Personne client[],int indice_colonne, int depart, int fin);

/*
entrée : tableau de structure, int indice, char element_a_trouver, int debut, int fin
sortie : un client
pré-condition : que 0<indice<6
post-condition : retourne le client qui possède l'élément
*/
int recherche_dichotomie(Personne client[],int indice, char element_a_trouver, int debut, int fin);

/*
entrée : char, char
sortie : char char
pré-condition : aucune
post-condition : échange les deux éléments
*/
void permuter(char *element1, char *element2);

/*
entrée : tableau de structure
sortie : tableau de structure
pré-condition : aucune
post-condition : retourne le tableau de structure
*/
int lecture (Personne client[]);

/*------------------------- Fonction Switch 1 ----------------------------------------------------*/

/*
entrée : tableau de structure
sortie : tableau de structure
pré-condion : aucune
post-condition : appelle une autre fonction 
*/
int critere_insertion(Personne client[]);

/*
entrée : tableau de structure
sortie : tableau de structure
pré-condition : aucune
post-condition : rajoute une personne au tableau
*/
int insertion_personne(Personne client []);

/*
entrée : tableau de structure
sortie : tableau de structure
pré-condition : aucune
post-condition : modifie une personne du tableau
*/
int modification_element(Personne client[]);

/*------------------------- Fonction Switch 2 ----------------------------------------------------*/

/*------------------------- Fonction Switch 3 ----------------------------------------------------*/

/*
entrée : tableau de structure, int, char, int, int
sortie : structure
pré-condition : aucune
post-condition : retourne les informations sur un client
*/
int recherche_dichotomie(Personne client[],int indice, char element_a_trouver, int debut, int fin);

/*
entrée : tableau de structure
sortie : int
pré-condition : aucune
post-condition : appelle des fonctions 
*/
int information_personne(Personne client[]);

/*------------------------- Fonction Switch 4 ----------------------------------------------------*/

/*
entrée : tableau de structure, char, int
sortie : int
pré-condition : aucune
post-condition : retourne les personnes correspondent au filtre
*/
int lancement_filtre(Personne client[], char critere, int indice);

/*
entrée : tableau de structure
sortie : int
pré-condition : aucune
post-condition : appelle d'autres fonctions
*/
int choisir_filtre(Personne client[]);