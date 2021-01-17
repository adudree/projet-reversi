#include <iostream>
using namespace std;

/* --------------- STRUCTURES ---------------- */ 

typedef struct  {
    int idJoueur;
    int ligne;
    int colonne;
} Jeton;

typedef struct  {
    char nom[30];
    int idJoueur;
    int nbJetons;
} Joueur;

typedef struct  {
    Joueur joueur1;
    Joueur joueur2;
    
    Jeton* tab[8][8];
}Jeu;
