#include <iostream>
#include "structures.cpp" 
using namespace std;

void initJeton(Jeton * jeton, int ligne, int colonne){
    jeton->ligne=ligne;
    jeton->colonne=colonne;
}

void displayJeton(int player, Jeton jeton){   
    if (player == 0) {
        cout << " |    ";
    }
    else if (player == 1) {
        cout << " |  X " ;
    }
    else if (player == 2) {
        cout << " |  O ";
    }
    
    if (jeton.colonne=='H') {
        cout << " |\n";
    }
}

void printLine() {
    for (int i=0; i<8;i++) {      
        cout << "--+---";
        
        if (i==7) {
            cout <<"--+"<< endl;
        }
    }
}

void initJoueur(Joueur *joueur) {
    cout << "Nom du joueur " << joueur->id << " : " ;
    cin >> joueur->name;
    joueur->nbJetons=0;
}

void displayCurrentJoueur(Joueur joueur) {
    cout << "Joueur en cours : " << joueur.name << " | Nombre de jetons : " << joueur.nbJetons << endl;
}

int main(){
    Joueur joueur1;
    joueur1.id=1;
    Joueur joueur2;
    joueur2.id=2;

    initJoueur(&joueur1);
    initJoueur(&joueur2);

    cout << "\n";
    int currentPlayer=0; //test 

    displayCurrentJoueur(joueur1);

    /* AFFICHAGE DE LA GRILLE */
    for (char colonne='A';colonne <='H';colonne++) {  
        cout << "  |  " << colonne;
        if (colonne == 'H') {
            cout << "  |\n";
        }
    }

    for (int ligne=1;ligne<=8;ligne++) {
        printLine();
        cout << ligne;
        for (char colonne='A'; colonne<='H'; colonne++) {
            Jeton jeton;
            initJeton(&jeton, ligne, colonne);
            displayJeton(currentPlayer, jeton);
        }
    }
    printLine();
}