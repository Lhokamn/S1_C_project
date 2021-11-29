#include <stdio.h>

/*
	cette fonction prend en parametre une suite de caracteres(Peut etre une lettre voire six lettres) et le type du filtre a applique.
	Si type_filtre == 1 c.a.d un filtre sur prenom
	Si type_filtre == 2 c.a.d un filtre sur nom
	Si type_filtre == 3 c.a.d un filtre sur profession
*/
void fonction_filtre_1(char caracteres, int type_filtre)
{
	struct CLIENT tableau[TAILLE_MAX];//tableau de type structure CLIENT qui contiendera les clients match avec le filtre
	
	if(type_filtre == 1)
	{
		//implementer le code qui cherche tout les prenoms qui commence par caracteres
	}
	else if(type_filtre == 2)
	{
		//implementer le code qui cherche tout les noms qui commence par caracteres	
	}
	else if(type_filtre == 3)
	{
		//implementer le code qui cherche tout les clients dont la profession commence par caracteres	
	}
	else if(type_filtre == 4)
	{
		//implementer le code qui cherche tout les clients dont la code postale commence par caracteres	
	}
}


//cette fonction est identique a la precedente cependant implmeneter avec un switch
void fonction_filtre_2(char caracteres, int type_filtre)
{
	struct CLIENT tableau[TAILLE_MAX];//tableau de type structure CLIENT qui contiendera les clients match avec le filtre
	
	switch ( type_filtre )
	{
		case 1:
			//implementer le code qui cherche tout les prenoms qui commence par caracteres
			break;
		case 2:
			//implementer le code qui cherche tout les noms qui commence par caracteres
			break;
		case 3:
			//implementer le code qui cherche tout les clients dont la profession commence par caracteres
			break;
		case 4:
			//implementer le code qui cherche tout les clients dont la code postale commence par caracteres	
			break;
		default:
			printf("Erreur surbenue pendant le traitement de votre demande");
	}
}
