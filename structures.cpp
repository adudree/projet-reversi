#include <iostream>
using namespace std;

typedef struct Jeton {
    int ligne;
    int colonne;
    struct Jeton* next;    
}Jeton;

typedef struct Joueur {
    char name[30];
    int nbJetons;
    Jeton listeJetons;

    int id;
}Joueur;

typedef struct Jeu {
    Joueur joueur1;
    Joueur joueur2;
    Jeton * grille[8][8];
}Jeu;