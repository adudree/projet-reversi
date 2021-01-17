#include <iostream>
using namespace std;

/* --------------- STRUCTURES ---------------- */ 

struct Jeton {
    int idJoueur; // joueur 1 : idJoueur = 1 ( = X = noir) ; joueur 2 : idJoueur = 2 ( = O = blanc) ; joueur 0 : idJoueur = 0 ( = vide = vide) ;
    int ligne; // coordonnée de ligne
    int colonne; // coordonnée de colonne
} ;

struct Joueur {
    char nom[30];
    int idJoueur;
    int nbJetons; // nb de jetons que ce joueur a actuellement de placés sur la grille
} ;

struct Jeu {
    Joueur joueur1;
    Joueur joueur2;
    
    Jeton *tab[8][8];
} ;
