/*!
\author Léo Renault
\date 14 novembre 2023
\file main.c
*/
#include "fonctions.h"

int main(){
	int exo;
	int i;
	int res;
	float tabtrans[taille]={3,7,2,-1,1,9};
	float tabtest[taille];
	float tabsomme[taille];
	int tab[N][N];
	char mot1[taille]="kayak\0";
	char mot2[taille]="palindrome\0";
	
	for (i=0; i<taille; i++){
	tabtest[i]=i;
	}
	
	printf("Quel est le numéro de l'exercice ? (entier entre 1 et 5) \n");
	scanf("%d",&exo);
	
	switch(exo){
		case 1:
			printf("Voici le tableau de départ: \n");
			afficherTableau(tabtest);
			inversion(tabtest);
			printf("Voici le tableau inversé: \n");
			afficherTableau(tabtest);
			break;
		case 2:
			printf("Voici le tableau de départ: \n");
			afficherTableau(tabtest);
			somme(tabtest,tabtest,tabsomme);
			printf("Voici le tableau somme qui est le double dans cette exemple: \n");
			afficherTableau(tabsomme);
			break;
		case 3:
			printf("Voici le tableau de départ: \n");
			afficherTableau(tabtrans);
			printf("Le tableau est transversal: %d (1 pour true, 0 pour false)\n", transversale(tabtrans));
			break;
		case 4:
			printf("Le mot %s est un palindrome ? %d (1 pour true, 0 pour false)\n", mot1, palindrome(mot1));
			printf("Le mot %s est un palindrome ? %d (1 pour true, 0 pour false)\n", mot2, palindrome(mot2));
			break;
		case 5:
			
			tourDejeu(tab);
	}
}
	
