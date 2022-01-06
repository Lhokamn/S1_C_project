#define chemin "../test_a_detruire.csv"
#define taille_tableau 6000
#define colonne_tableau 7
#define MAX_LENGTH 5000
#define taille_ligne 300

typedef struct 
{
    char prenom[45];
    char nom[45];
    char ville[45];
    char code_postal[6];
    char telephone[14];
    char mail[60];
    char metier[50];
} Personne;