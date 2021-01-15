#include <iostream>
#include "structures.cpp" 
using namespace std;

void initJeton(Jeton *jeton, int ligne, int colonne){
    jeton->ligne = ligne;
    jeton->colonne = colonne;
}


// Affichage des jetons :
void displayJeton(int player, Jeton jeton){   
    if(player == 0){ // Le joueur 0 sert à placer des jetons "vides"
        cout << " |    ";
    }
    else if(player == 1){
        cout << " |  X " ; // X = noir
    }
    else if(player == 2){
        cout << " |  O "; // O = blanc
    }
    
    if(jeton.colonne == 'H'){
        cout << " |\n";
    }
}


// Tracé des lignes de la grille :
void printLine(){
    for(int i = 0; i < 8; i++){      
        cout << "--+---";
        
        if(i == 7){
            cout << "--+" << endl;
        }
    }
}


// Caractérisation du joueur :
void initJoueur(Joueur *joueur){
    cout << "Nom du joueur " << joueur->id << " : " ;
    cin >> joueur->name;
    joueur->nbJetons = 0;
}


// Affichage du nom du joueur courant et de son nombre actuel de jetons placés sur la grille :
void displayCurrentJoueur(Joueur joueur){
    cout << "C'est au tour de " << joueur.name << " | Nombre de jetons : " << joueur.nbJetons << endl;
}


// ----- DÉROULEMENT DU JEU -----
int main(){

    // Configuration des 2 joueurs :
    Joueur joueur1;
    joueur1.id = 1;
    Joueur joueur2;
    joueur2.id = 2;
    initJoueur(&joueur1);
    initJoueur(&joueur2);

    cout << "\n";
    int currentPlayer = 0; //test 

    // Affichage du joueur courant :
    displayCurrentJoueur(joueur1);

    /* AFFICHAGE DE LA GRILLE */

    // tracé des colonnes :
    for (char colonne = 'A'; colonne <= 'H'; colonne++){  
        cout << "  |  " << colonne;
        if (colonne == 'H') {
            cout << "  |\n";
        }
    }

    // tracé des lignes :
    for (int ligne = 1; ligne <= 8 ; ligne++){
        printLine();
        cout << ligne;
        for (char colonne = 'A'; colonne <= 'H'; colonne++){
            Jeton jeton;
            initJeton(&jeton, ligne, colonne);
            displayJeton(currentPlayer, jeton);
        }
    }
    printLine();
}