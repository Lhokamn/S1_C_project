#define chemin "../test_a_detruire.csv"
#define taille_tableau 6000
#define colonne_tableau 7
#define MAX_LENGTH 5000
#define taille_ligne 300

typedef struct 
{
    char prenom[46];
    char nom[46];
    char ville[46];
    char code_postal[7];
    char telephone[15];
    char mail[61];
    char metier[51];
} Personne;