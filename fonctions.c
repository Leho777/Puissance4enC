#include "fonctions.h"


void afficherTableau(float tab[taille]) {
	int i;
	for (i =0; i <taille; ++i){
		printf(" %f ", tab[i]);
	}
}
void inversion(float tab[taille]){
	int i;
	float val;
	for (i=0; i<(taille/2); ++i){ //division entière donc fonctione pour taille pair et impair
		val=tab[i];
		tab[i]=tab[taille-1-i];
		tab[taille-1-i]=val;
	}
}

void somme(float tab1[taille], float tab2[taille], float tab[taille]){
	int i;
	for (i=0; i<taille; i++){
		tab[i]=tab1[i]+tab2[i];
	}
} 

int transversale(float tab[taille2]){
	int indice;
	int compt;
	indice=0;
	compt=0;
	while (indice<taille2 && compt<taille2){
		if (indice==(taille2-1)){
		return 1; //true 
		}
		else {
		indice=indice+(int)tab[indice]; // j'utilise des tableaux de floatant donc je convertis en entier
		compt++;
		}
	}
	return 0; //false
}

int palindrome(char mot[taille]){
	int indice;
	int longueur;
	indice=0;
	while (mot[indice] != '\0'){
		indice++;
	}
	longueur=indice;
	
	for (indice=0; indice<(longueur/2); indice++){
		if (mot[indice] != mot[longueur-1-indice]){
			return 0;
		}
	}
	return 1;
}

//PUISSANCE 4

void init(int tab[N][N]){
	int i,j;
	for (i=0; i<N; i++){
		for (j=0; j<N; j++){
			tab[i][j]=-1;
		}
	}
}

void affichage(int tab[N][N]){
	int i,j;

	for (i=0; i<N; i++){
		for (j=0; j<N; j++){
			
			if (j==N-1){
				if (tab[i][j]==-1){
					printf("\n");
				}
				else if (tab[i][j]==1){
					printf(" %c \n", 'X');
				}
				else{
					printf(" %c \n", 'O');
				}
			}
			else{
				if (tab[i][j]==-1){
					printf("   ");
				}
				else if (tab[i][j]==1){
					printf(" %c ", 'X');
				}
				else{
					printf(" %c ", 'O'); 
				}
			}
		}
	}
}

int jouer(int tab[N][N], int joueur, int col){
	int i;
	i=-1;
	while ((tab[i+1][col]==-1) && (i+1)<N){
		i++;
	}
	if (i==-1){
		return 0; //erreur colonne pleine 
	}
	else{
		tab[i][col]=joueur;
		return 1;
	}
}

int aGagne(int tab[N][N]){
	int i,j,l;

	for (i=0; i<N; i++){ //verif ligne
		for (j=0; (j+3)<N; j++){
			
			if ((tab[i][j]==tab[i][j+1]) && (tab[i][j]==tab[i][j+2]) && (tab[i][j]==tab[i][j+3]) && (tab[i][j]!=-1)){
				
				return tab[i][j];
			}
		}
	}
	
	for (j=0; j<N; j++){ //verif colonne
		for (i=0; (i+3)<N; i++){
			
			if ((tab[i][j]==tab[i+1][j]) && (tab[i][j]==tab[i+2][j]) && (tab[i][j]==tab[i+3][j]) && (tab[i][j]!=-1)){
				
				return tab[i][j];
			}
		}
	}
	for (i=0; i+3<N; i++){ //verif diag décroissante
		for (j=0; j+3<N; j++){
			
			if ((tab[i][j]==tab[i+1][j+1]) && (tab[i][j]==tab[i+2][j+2]) && (tab[i][j]==tab[i+3][j+3]) && (tab[i][j]!=-1)){
				return tab[i][j];
			}
		}
	}
	for (i=0; i+3<N; i++){ //verif diag croissante
		for (j=3; j<N; j++){
			
			if ((tab[i][j]==tab[i+1][j-1]) && (tab[i][j]==tab[i+2][j-2]) && (tab[i][j]==tab[i+3][j-3]) && (tab[i][j]!=-1)){
				return tab[i][j];
			}
		}
	}
	for (i=0; i<N; i++){
		for (j=0; j<N; j++){
			if (tab[i][j]==-1){
				return -1; //Partie non terminée 
			}
		}
	}
	
	return 0; //match nul toutes les cases sont remplit 		
}		
/*
\brief Faire une partie de puissance 4
*/			
void tourDejeu(int tab[N][N]){
	int joueur;
	int col;
	int verif;
	
	init(tab);
	affichage(tab);
	joueur=1;
	col=-1;
	verif=0;
	
	while (aGagne(tab)==-1){
	
		while ( (col>=N) || (col<=-1) || jouer(tab, joueur, col)==0){ //jouer permet de pas jouer sur une colonne pleine
			printf("Joueur %d dans quelle colonne voulez-vous jouer ?", joueur);
			scanf("%d", &col);
			
		}
		
		affichage(tab);
		col=-1; //pour rentrer dans la boucle while
		
		if (joueur==1){
			joueur=2;
		}
		else{
			joueur=1;
		}
	}
	printf("Bravo joueur %d !", aGagne(tab)); //joueur 0 en cas d'égalité
}

