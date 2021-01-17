#include <iostream>
//#include <string>
#include "structures.cpp" 
using namespace std;


/* ------------- Initialisation ------------- */

void initJoueur(Joueur * joueur) {
    cout << "Nom du joueur " << joueur->idJoueur << " : " ;
    cin >> joueur->nom;
    joueur->nbJetons = 0;
}

void initJeu(Jeu *jeu, Joueur j1, Joueur j2) {
    jeu->joueur1 = j1;
    jeu->joueur2 = j2;
}

void initJeton(Jeton * jeton, int id, int col, int lig){
    jeton->idJoueur = id;
    jeton->colonne = col;
    jeton->ligne = lig;
}

/* -------------- Affichage -------------- */

// affichage du jeton en fonction du joueur 
void displayJeton(Jeton jeton){   
    if (jeton.idJoueur == 0) {
        cout << " |    ";
    }
    else if (jeton.idJoueur == 1) {
        cout << " |  X " ;
    }
    else if (jeton.idJoueur == 2) {
        cout << " |  O ";
    }
    // fin de ligne 
    if (jeton.colonne==7) {
        cout << " |\n";
    }
}

// affichage d'une ligne (purement esthétique)
void printLine() {
    for (int i=0; i<8;i++) {      
        cout << "--+---";
        
        // fin de ligne        
        if (i==7) {
            cout <<"--+"<< endl;
        }
    }
}

// affichage de la grille 8x8
void afficheGrille(Jeu my_jeu) {
    // en-tête des colonnes 
    for (char colonne='A';colonne <='H';colonne++) {  
        cout << "  |  " << colonne;
        if (colonne == 'H') {
            cout << "  |\n";
        }
    }

    for (int ligne = 0; ligne < 8; ligne++) {
        printLine();
        cout << ligne + 1; // en-tête des lignes (+1 car décalage de l'indice)

        for (int colonne = 0; colonne < 8; colonne++) {
            int couleurToPrint; // correspond à l'ID du joueur
            if (my_jeu.tab[colonne][ligne] == NULL) {
                couleurToPrint = 0;
            }
            else {
                couleurToPrint = my_jeu.tab[colonne][ligne]->idJoueur;
            }

            //créer et afficher chaque case/jeton selon l'ID du joueur
            Jeton JetonToPrint;
            initJeton(&JetonToPrint, couleurToPrint, colonne, ligne);
            displayJeton(JetonToPrint);
        }
    }
    printLine();    
}


/* ---------- Infos joueur courant -------- */

// compteur de jetons par joueur
int countJeton(Jeu jeu, Joueur joueur) {
    int count = 0;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            // on compare l'id de la case et celle du joueur demandé et on compare
            if (jeu.tab[j][i] && jeu.tab[j][i]->idJoueur == joueur.idJoueur) {
                count++;
            }
        }
    }
    return count;
}

// affichage joueur courant 
void displayCurrentJoueur(Jeu jeu, Joueur joueur) {
    cout << "\nJoueur en cours : " << joueur.nom << " | Nombre de jetons : " << countJeton(jeu, joueur) << endl << endl;
}

// convertir les char en int (pour les coordonnées)
int charToInt(char charToConvert) { 
    int intToReturn;
    switch(charToConvert) 
    {
        case 'A': 
            intToReturn = 1;
            break;
        case 'B': 
            intToReturn = 2;
            break;
        case 'C': 
            intToReturn = 3;
            break;
        case 'D': 
            intToReturn = 4;
            break;
        case 'E': 
            intToReturn = 5;
            break;
        case 'F': 
            intToReturn = 6;
            break;
        case 'G': 
            intToReturn = 7;
            break;
        case 'H': 
            intToReturn = 8;
            break;    
    }
    return intToReturn;
}

// récupération de l'id de l'autre joueur 
int otherJoueur(int currentJoueur) {
    int otherid;
    if (currentJoueur = 1) {
        otherid = 2;
    }
    else {
        otherid = 1;
    }
    return otherid;
} 

// changement de joueur courant 
Joueur * alterneJoueur(Joueur * currentJoueur, Joueur * joueur1, Joueur * joueur2) {
    if (currentJoueur == joueur1) {
        currentJoueur = joueur2;
    }
    else {
        currentJoueur = joueur1;
    }
    return currentJoueur;
}

// demander la case à jouer 
string askCase(Jeu * my_jeu, Joueur currentJoueur) {
    cout << "Quelle case voulez-vous jouer ? [Format Colonne Ligne, ex : A1] "; 
    string caseToPlay;
    cin >> caseToPlay;

    return caseToPlay;
}

/* ----------------- Jetons ----------------- */

//ajout d'un jeton au tableau 
void addJeton(Jeu * jeu, Jeton * jeton) { 
    jeu->tab[jeton->colonne-1][jeton->ligne-1] = jeton; 
}

// vérification des conditions de placement de jeton 
bool emplacementOk(Jeu my_jeu, Jeton jetonToCreate, Joueur * currentJoueur) {
    bool isOk = true; 

    // décalage de 1 dû au décalage d'indice dans la grille
    int trueColonne = jetonToCreate.colonne - 1;
    int trueLigne = jetonToCreate.ligne - 1;

    int otherid = otherJoueur(currentJoueur->idJoueur);

    // on vérifie si la case est libre 
    if (my_jeu.tab[trueColonne][trueLigne] == NULL) {
        cout << "La case est libre." << endl;
        isOk = true; 
       
        // on vérifie que les cases à proximité contiennent un jeton, et que ce jeton est de couleur adverse
        if (
            (my_jeu.tab[trueColonne + 1][trueLigne + 1] && my_jeu.tab[trueColonne + 1][trueLigne + 1]->idJoueur == otherid) ||
            (my_jeu.tab[trueColonne + 1][trueLigne] && my_jeu.tab[trueColonne + 1][trueLigne]->idJoueur == otherid) ||            
            (my_jeu.tab[trueColonne + 1][trueLigne - 1] && my_jeu.tab[trueColonne + 1][trueLigne - 1]->idJoueur == otherid) ||
            (my_jeu.tab[trueColonne][trueLigne + 1] && my_jeu.tab[trueColonne][trueLigne + 1]->idJoueur == otherid) ||            
            (my_jeu.tab[trueColonne][trueLigne - 1] && my_jeu.tab[trueColonne][trueLigne - 1]->idJoueur == otherid) ||
            (my_jeu.tab[trueColonne - 1][trueLigne + 1] && my_jeu.tab[trueColonne - 1][trueLigne + 1]->idJoueur == otherid) ||            
            (my_jeu.tab[trueColonne - 1][trueLigne] && my_jeu.tab[trueColonne - 1][trueLigne]->idJoueur == otherid) ||
            (my_jeu.tab[trueColonne - 1][trueLigne - 1] && my_jeu.tab[trueColonne - 1][trueLigne - 1]->idJoueur == otherid)            
        ){
            cout << "Il y a un jeton adverse a proximite." << endl;
            isOk = true; 
        }

        // si pas de jeton de l'adversaire à proximité 
        else {
            cout << "coup impossible" << endl;
            isOk = false;
        }
    }

    // si la case a déjà un jeton 
    else {
        cout << "La case est prise." << endl;
        isOk = false;
    }

    return isOk;
}

/* =================== PROGRAMME ================== */
/* ----- variables ----- */

Joueur joueur1;
Joueur joueur2;
Joueur noJoueur;
Jeu my_jeu;
Joueur * currentJoueur;

int main() {

    /* ------- Initialisation joueurs ----- */    
    
    joueur1.idJoueur=1;
    joueur2.idJoueur=2;
    initJoueur(&joueur1);
    initJoueur(&joueur2);
   
    noJoueur.idJoueur = 0;

    /* --------- Initialisation jeu ------- */    

    initJeu(&my_jeu, joueur1, joueur2);

    /* -- Initialisation joueur courant  -- */
    currentJoueur = &joueur1;

    /* -- Initialisation premiers jetons -- */
   
    Jeton debut1;
    Jeton debut2;
    Jeton debut3;
    Jeton debut4;   

    // jetons présents en début de partie
    initJeton(&debut1, joueur1.idJoueur, 4, 4); 
    initJeton(&debut2, joueur1.idJoueur, 5, 5);
    initJeton(&debut3, joueur2.idJoueur, 4, 5); 
    initJeton(&debut4, joueur2.idJoueur, 5, 4);

    // on ajoute les jetons de début de partie à la tab
    addJeton(&my_jeu, &debut1);
    addJeton(&my_jeu, &debut2);
    addJeton(&my_jeu, &debut3);
    addJeton(&my_jeu, &debut4);

    /* ---------- Affichage de la grille -------- */
    afficheGrille(my_jeu);

    /* ================= DEBUT DU JEU ================ */

    // affichage infos joueur courant 
    displayCurrentJoueur(my_jeu, *currentJoueur); 
    
    // Demande d'un jeton  
    string caseToPlay = askCase(&my_jeu, *currentJoueur); 

    // récupération des coordonnées demandées + conversion des char en int
    int ligneToPlay = atoi(&caseToPlay[1]);
    int colonneToPlay = charToInt(caseToPlay[0]);

    // création et initialisation du jeton entré par le joueur
    Jeton jetonToCreate; 
    initJeton(&jetonToCreate, currentJoueur->idJoueur, colonneToPlay, ligneToPlay);

    // si les conditions sont réunies, on le place dans la grille. 
    if (emplacementOk(my_jeu, jetonToCreate, currentJoueur)) {
        cout << "Le jeton peut etre joue." << endl;
        addJeton(&my_jeu, &jetonToCreate); 
    }

    /* A FAIRE : SINON, ON REJOUE */ 

    // on affiche de nouveau la grille pour vérifier 
    afficheGrille(my_jeu);

    // changement de joueur 
    currentJoueur = alterneJoueur(currentJoueur, &joueur1, &joueur2);
}