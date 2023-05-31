// TP Info7 : Jeu d'Echec
// Antoine Ducourant & Khamzat Baoudinov : Team \(^_^)/

#include <iostream>
#include "../board/board.hpp"
#include "../mask/mask.hpp"

using namespace std;

void print_square(Plateau *plateau, int x, int y){
    // Affiche la case en (x, y)
    // paramètre : plateau (Pointeur Plateau)
    // paramètre : x (int)
    // paramètre : y (int)
    if(get_square(plateau, x, y) <= 16){ // Pièces noires
        if(get_square(plateau, x, y) == 0){ // Case vide
            cout << " - ";
        }
        if (get_square(plateau, x, y) == 1){ // Pion noir
            cout << " P ";
        }
        if (get_square(plateau, x, y) == 2){ // Pion noir
            cout << " P ";
        }
        if (get_square(plateau, x, y) == 3){ // Pion noir
            cout << " P ";
        }
        if (get_square(plateau, x, y) == 4){ // Pion noir
            cout << " P ";
        }
        if (get_square(plateau, x, y) == 5){ // Pion noir
            cout << " P ";
        }
        if (get_square(plateau, x, y) == 6){ // Pion noir
            cout << " P ";
        }
        if (get_square(plateau, x, y) == 7){ // Pion noir
            cout << " P ";
        }
        if (get_square(plateau, x, y) == 8){ // Pion noir
            cout << " P ";
        }
        if (get_square(plateau, x, y) == 9){ // Tour noir
            cout << " R ";
        }
        if (get_square(plateau, x, y) == 10){ // Tour noir
            cout << " R ";
        }
        if (get_square(plateau, x, y) == 11){ // Cavalier noir
            cout << " N ";
        }
        if (get_square(plateau, x, y) == 12){ // Cavalier noir
            cout << " N ";
        }
        if (get_square(plateau, x, y) == 13){ // Fou noir
            cout << " B ";
        }
        if (get_square(plateau, x, y) == 14){ // Fou noir
            cout << " B ";
        }
        if (get_square(plateau, x, y) == 15){ // Reine noire
            cout << " Q ";
        }
        if (get_square(plateau, x, y) == 16){ // Roi noir
            cout << " K ";
        }
    }
    if(get_square(plateau, x, y) > 16){ // Pièces blanches
        if (get_square(plateau, x, y) <= 24){ // Pion blanc
            cout << " p ";
        }
        if (get_square(plateau, x, y) == 25){ // Tour blanche
            cout << " r ";
        }
        if (get_square(plateau, x, y) == 26){ // Tour blanche
            cout << " r ";
        }
        if (get_square(plateau, x, y) == 27){ // Cavalier blanc
            cout << " n ";
        }
        if (get_square(plateau, x, y) == 28){ // Cavalier blanc
            cout << " n ";
        }
        if (get_square(plateau, x, y) == 29){ // Fou blanc
            cout << " b ";
        }
        if (get_square(plateau, x, y) == 30){ // Fou blanc
            cout << " b ";
        }
        if (get_square(plateau, x, y) == 31){ // Reine blanche
            cout << " q ";
        }
        if (get_square(plateau, x, y) == 32){  // Roi blanc
            cout << " k ";
        }
    }
}

void print_board(Plateau *plateau){
    // Affiche le plateau de jeu
    // paramètre : plateau (Pointeur Plateau)
    cout << "   A  B  C  D  E  F  G  H" << endl;
    int cpt=0;
    for(int i=0; i<8; i++){
        cout << 8-cpt << " ";
        for(int j=0; j<8; j++){
            print_square(plateau, i, j);
        }
        cout << endl;
        cpt++;
    }
}
void set_background(int color, int x, int y){
    // Défini la couleur de fond
    // paramètre : color (int)
    // paramètre : x (int)
    // paramètre : y (int)

    if (color== 0){
        if (x%2==0) {
            if (y%2==0) cout << "\x1b[48;5;216m"; // Case blanche
            else cout << "\x1b[48;5;214m"; // Case grise
        }
        else {
            if (y%2==0) cout << "\x1b[48;5;214m"; // Case grise
            else cout << "\x1b[48;5;216m"; // Case blanche
        }
    }
    if (color== 1) cout << "\x1b[48;5;196m"; // Case rouge

    if (color== 2) cout << "\x1b[48;5;35m"; // Case verte

    if (color== 3) cout << "\x1b[48;5;226m"; // Case jaune

    if (color== 4) cout << "\x1b[48;5;27m"; // Case bleu

    if (color== 5) cout << "\x1b[48;5;93m"; // Case violette

    if (color== 6) cout << "\x1b[48;5;51m"; // Case cyan

    if (color== 7) cout << "\x1b[48;5;240m"; // Case grise
}

void set_foreground(int color){
    // Défini la couleur du texte
    // paramètre : color (int)
    if (color== 0){
        cout << "\x1b[38;5;231m"; // Couleur des pièces blanches
    }
    if (color== 1){
        cout << "\x1b[38;5;0m"; // Couleur des pièces noires
    }
}

string IntToIcon(int Piece){
    // Retourne le caractère correspondant à la pièce
    // paramètre : Piece (int)
    if ((Piece > 0 and Piece < 9) or (Piece > 16 and Piece < 25)) return "♟";
    if (Piece == 9 or Piece == 10 or Piece == 25 or Piece == 26 ) return "♜";
    if (Piece == 11 or Piece == 12 or Piece == 27 or Piece == 28) return "♞";
    if (Piece == 13 or Piece == 14 or Piece == 29 or Piece == 30) return "♝";
    if (Piece == 15 or Piece == 31) return "♛";
    if (Piece == 16 or Piece == 32) return "♚";
    return "ERREUR: Impossible de trouver la pièce.";
}

void print_square_color(Plateau *plateau, int x, int y,int color){
    // Affiche la case en (x, y)
    // paramètre : plateau (Pointeur Plateau)
    // paramètre : x (int)
    // paramètre : y (int)
    // paramètre : color (int)
    set_background(color, x, y);
    if (get_square(plateau, x, y) == 0) { // Case vide
        set_foreground(0);
        cout << "   ";
    }
    if ((get_square(plateau, x, y)>=1) and (get_square(plateau, x, y)<=16)){
        set_foreground(1);
        cout << " " << IntToIcon(get_square(plateau, x, y)) << " ";
    }
    if ((get_square(plateau, x, y)>16) and (get_square(plateau, x, y)<33)){
        set_foreground(0);
        cout << " " << IntToIcon(get_square(plateau, x, y)) << " ";
    }
    cout << "\x1b[0m";
}

void print_board_color(Plateau *plateau){
    // Affiche le plateau de jeu
    // paramètre : plateau (Pointeur Plateau)
    cout << "   A  B  C  D  E  F  G  H" << endl;
    int cpt=0;
    for(int i=0; i<8; i++){
        cout << 8-cpt << " ";
        for(int j=0; j<8; j++){
            print_square_color(plateau, i, j,0);
        }
        cout << endl;
        cpt++;
    }
}

void print_board_color(Plateau *plateau, Mask *mask){
    // Affiche le masque du plateau de jeu
    // paramètre : plateau (Pointeur Plateau)
    // paramètre : mask (Pointeur Mask)
    cout << "   A  B  C  D  E  F  G  H" << endl;
    int cpt=0;
    for(int i=0; i<8; i++){
        cout << 8-cpt << " ";
        for(int j=0; j<8; j++){
            print_square_color(plateau, i, j,get_mask(mask,i,j));
        }
        cout << endl;
        cpt++;
    }
}

void rules(){
    // Affiche les règles de base des échecs
    cout << "Les règles de base des échecs sont les suivantes :" << endl;
    cout << "Le but du jeu est de mettre le roi adverse en échec et mat." << endl;
    cout << "Le roi est la pièce la plus importante du jeu, si il est capturée, la partie est perdue." << endl;
    cout << "Les pièces peuvent se déplacer sur les cases vides ou sur les cases occupées par une pièce adverse." << endl;
    cout << "Les pièces ne peuvent pas sauter par dessus d'autres pièces." << endl;
    cout << "Pour plus d'informations, veuillez consulter le lien suivant : https://fr.wikipedia.org/wiki/Règles_du_jeu_d'échecs" << endl;
    cout << endl;
}