#include "../types/types.hpp"
#include <fstream>
#include <iostream>

using namespace std;

void empty(Plateau *plateau){
    // Rempli le plateau de 0 (case vide)
    // paramètre : plateau (Plateau*)

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            plateau->tab[i][j] = 0;
        }
    }
}

int get_square(Plateau *plateau, int x, int y){
    // Retourne la valeur de la case en (x,y)
    // paramètre : plateau (Pointeur Plateau)
    // paramètre : x (int )
    // paramètre : y (int)

    return plateau->tab[x][y];
}

void set_square(Plateau *plateau, int x, int y, int val){
    // Modifie la valeur de la case (x,y)
    // paramètre : plateau (Pointeur Plateau)
    // paramètre : x (int)
    // paramètre : y (int)
    // paramètre : val (int)
    plateau->tab[x][y] = val;
}

Plateau start(){
    // Initialise le plateau de jeu
    Plateau plateau;
    empty(&plateau);

    // Pions noirs
    for(int i=0; i<8; i++){
        set_square(&plateau, 1, i, i+1);
        //plateau.tab[1][i] = i+1;
    }
    // Tours noires
    set_square(&plateau, 0, 0, 9);
    set_square(&plateau, 0, 7, 10);
    //plateau.tab[0][0] = 9;
    //plateau.tab[0][7] = 10;
    // Cavaliers noirs
    set_square(&plateau, 0, 1, 11);
    set_square(&plateau, 0, 6, 12);
    //plateau.tab[0][1] = 11;
    //plateau.tab[0][6] = 12;
    // Fous noirs
    set_square(&plateau, 0, 2, 13);
    set_square(&plateau, 0, 5, 14);
    //plateau.tab[0][2] = 13;
    //plateau.tab[0][5] = 14;
    // Reine noire
    set_square(&plateau, 0, 3, 15);
    //plateau.tab[0][3] = 15;
    // Roi noir
    set_square(&plateau, 0, 4, 16);
    //plateau.tab[0][4] = 16;

    // Pions blancs
    for(int i=0; i<8; i++){
        set_square(&plateau, 6, i, i+17);
        //plateau.tab[6][i] = i+17;
    }
    // Tours blanches
    set_square(&plateau, 7, 0, 25);
    set_square(&plateau, 7, 7, 26);
    //plateau.tab[7][0] = 25;
    //plateau.tab[7][7] = 26;
    // Cavaliers blancs
    set_square(&plateau, 7, 1, 27);
    set_square(&plateau, 7, 6, 28);
    //plateau.tab[7][1] = 27;
    //plateau.tab[7][6] = 28;
    // Fous blancs
    set_square(&plateau, 7, 2, 29);
    set_square(&plateau, 7, 5, 30);
    //plateau.tab[7][2] = 29;
    //plateau.tab[7][5] = 30;
    // Reine blanche
    set_square(&plateau, 7, 3, 31);
    //plateau.tab[7][3] = 31;
    // Roi blanc
    set_square(&plateau, 7, 4, 32);
    //plateau.tab[7][4] = 32;

    return plateau;
}

void move_piece(Plateau *plateau, int x_init, int y_init, int x_final, int y_final){
    // Déplace une pièce du plateau
    // paramètre : plateau (Pointeur Plateau)
    // paramètre : x_init (int)
    // paramètre : y_init (int)
    // paramètre : x_final (int)
    // paramètre : y_final (int)

    set_square(plateau, x_final, y_final, get_square(plateau, x_init, y_init));
    set_square(plateau, x_init, y_init, 0);
}

string IntToChar(int Piece){
    // Retourne le caractère correspondant à la pièce
    // paramètre : Piece (int)
    if (Piece > 0 and Piece < 9) return "p";
    if (Piece == 9 or Piece == 10) return "r";
    if (Piece == 11 or Piece == 12) return "n";
    if (Piece == 13 or Piece == 14) return "b";
    if (Piece == 15) return "q";
    if (Piece == 16) return "k";
    if (Piece > 16 and Piece < 25) return "P";
    if (Piece == 25 or Piece == 26) return "R";
    if (Piece == 27 or Piece == 28) return "N";
    if (Piece == 29 or Piece == 30) return "B";
    if (Piece == 31) return "Q";
    if (Piece == 32) return "K";
    return "ERREUR: Impossible de trouver la pièce.";
}

void write_FEN(Plateau *plateau, char* filename){
    // Ecrit le plateau dans un fichier
    // paramètre : plateau (Pointeur Plateau)
    // paramètre : filename (char*)

    ofstream fic(filename);
    if(fic) {
        for(int i=0; i<8; i++){
            int nb_vide = 0;
            for(int j=0; j<8; j++){
                if (get_square(plateau, i, j) == 0) nb_vide++;
                else {
                    if (nb_vide != 0) fic << nb_vide;
                    fic << IntToChar(get_square(plateau, i, j));
                    nb_vide = 0;
                }
            }
            if (nb_vide != 0) fic << nb_vide;
            if (i != 7) fic << "/";
        }
        fic.close();
    }
    else {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}

void read_FEN(Plateau *plateau, char* filename){
    // Lit le plateau dans un fichier
    // paramètre : plateau (Pointeur Plateau)
    // paramètre : filename (char*)
    int pn=0;//compteur pion noir
    int pb=0;//compteur pion blanc
    int rn=0;//compteur tour noir
    int rb=0;//compteur tour blanc
    int nn=0;//compteur cavalier noir
    int nb=0;//compteur cavalier blanc
    int bn=0;//compteur fou noir
    int bb=0;//compteur fou blanc
    ifstream fic(filename);
    if(fic) {
        string ligne;
        getline(fic, ligne);
        int i = 0;
        int j = 0;
        for(char c : ligne){
            if (c == '/'){
                i++;
                j = 0;
            }
            else if (c >= '0' and c <= '9'){
                for(int k=0; k<c-'0'; k++){
                    set_square(plateau, i, j, 0);
                    j++;
                }
            }
            else {
                if (c == 'p'){
                    pn++;
                    set_square(plateau, i, j, pn);
                }
                if (c == 'r'){
                    rn++;
                    set_square(plateau, i, j, rn+8);
                }
                if (c == 'n'){
                    nn++;
                    set_square(plateau, i, j, nn+10);
                }
                if (c == 'b'){
                    bn++;
                    set_square(plateau, i, j, bn+12);
                }
                if (c == 'q'){
                    set_square(plateau, i, j, 15);
                }
                if (c == 'k'){
                    set_square(plateau, i, j, 16);
                }
                if (c == 'P'){
                    pb++;
                    set_square(plateau, i, j, pb+16);
                }
                if (c == 'R'){
                    rb++;
                    set_square(plateau, i, j, rb+24);
                }
                if (c == 'N'){
                    nb++;
                    set_square(plateau, i, j, nb+26);
                }
                if (c == 'B'){
                    bb++;
                    set_square(plateau, i, j, bb+28);
                }
                if (c == 'Q'){
                    set_square(plateau, i, j, 31);
                }
                if (c == 'K'){
                    set_square(plateau, i, j, 32);
                }
                j++;
            }
        }
        fic.close();
    }
    else {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}


