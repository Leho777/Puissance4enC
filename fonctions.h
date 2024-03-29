#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define taille 20
#define taille2 6
#define N 5

void afficherTableau(float tab[taille]);
void inversion(float tab[taille]);
void somme(float tab1[taille], float tab2[taille], float tab[taille]);
int transversale(float tab[taille]);
int palindrome(char mot[taille]);

//PUISSANCE 4

void init(int tab[N][N]);
void affichage(int tab[N][N]); 
int jouer(int tab[N][N], int joueur, int col);
int aGagne(int tab[N][N]);
void tourDejeu(int tab[N][N]);

