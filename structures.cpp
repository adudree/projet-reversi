#include <iostream>
using namespace std;

struct Jeton {
    int idCouleur; // joueur 1 : idCouleur = 1 ( = X = noir) ; joueur 2 : idCouleur = 2 ( = O = blanc) ; joueur 0 : idCouleur = 0 ( = vide = vide) ;
    int ligne;
    int colonne;
    struct Jeton *next;    
} ;

struct Joueur {
    char name[30];
    int nbJetons; // nb de jetons actuels
    Jeton listeJetons;

    int id;
} ;

struct Jeu {
    Joueur joueur1;
    Joueur joueur2;
    Jeton *grille[8][8];
} ;