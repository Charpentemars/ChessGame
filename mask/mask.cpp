#include "../board/board.hpp"
#include "../view/view.hpp"
#include "../mask/mask.hpp"
#include "../game/game.hpp"
#include <iostream>
using namespace std;

Mask empty_mask(){
    // Retourne un masque vide
    Mask mask={};
    for(int i=0; i<8; i++){
        for (int j = 0; j < 8; j++) mask.tab[i][j] = 0;

    }
    return mask;
}

void clear_mask(Mask *mask){
    // Rempli le masque de 0 (case vide)
    // paramètre : mask (Pointeur Mask)

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++) mask->tab[i][j] = 0;
    }
}

int get_mask(Mask *mask,int x,int y){
    // Retourne la valeur d'une case du masque
    // paramètre : mask (Pointeur Mask)
    // paramètre : x (int)
    // paramètre : y (int)
    return mask->tab[x][y];
}


void set_mask(Mask *mask,int x,int y,int val){
    // Modifie la valeur d'une case du masque
    // paramètre : mask (Pointeur Mask)
    // paramètre : x (int)
    // paramètre : y (int)
    // paramètre : val (int)
    mask->tab[x][y] = val;
}

void highlight_possible_moves(Plateau *plateau,int x,int y,Mask* mask){
    // Affiche les déplacements possibles
    // paramètre : plateau (Pointeur Plateau)
    // paramètre : coord x (int)
    // paramètre : coord y (int)
    // paramètre : mask (Pointeur Mask)
    int val= get_square(plateau,x,y);
    if ((val==32) or (val==16)) highlight_possible_moves_king(plateau,x,y,mask);
    if ((val==9) or (val==10) or (val==25) or (val==26)) highlight_possible_moves_rook(plateau,x,y,mask);
    if ((val==13) or (val==14) or (val==29) or (val==30)) highlight_possible_moves_bishop(plateau,x,y,mask);
    if ((val==15) or (val==31)) highlight_possible_moves_queen(plateau,x,y,mask);
    if ((val==11) or (val==12) or (val==27) or (val==28)) highlight_possible_moves_knight(plateau,x,y,mask);
    for (int i=1;i<9;i++){
        if ((val==i) or (val==i+16)) highlight_possible_moves_pawn(plateau,x,y,mask);
    }
}
void highlight_possible_moves_king(Plateau *plateau, int x, int y, Mask *mask) {
    // Affiche les déplacements possibles du roi
    // paramètre : plateau (Pointeur Plateau)
    // paramètre : x (int)
    // paramètre : y (int)
    // paramètre : mask (Pointeur Mask)

    set_mask(mask, x, y, 5); // Position du roi
    if (get_square(plateau,x,y) > 16) { // Pièce blanche
        // Déplacement en ligne droite
        if ((x > 0) and (get_square(plateau,x - 1,y) <=16))set_mask(mask, x - 1, y, 4); // Déplacement vers le haut
        if ((x < 7) and (get_square(plateau,x + 1,y) <=16)) set_mask(mask, x + 1, y, 4); // Déplacement vers le bas
        if ((y > 0) and (get_square(plateau,x,y - 1) <=16)) set_mask(mask, x, y - 1, 4); // Déplacement vers la gauche
        if ((y < 7) and (get_square(plateau,x,y + 1) <=16)) set_mask(mask, x, y + 1, 4); // Déplacement vers la droite

        // Déplacement en diagonale
        if ((x > 0) and (y > 0) and (get_square(plateau,x - 1,y - 1) <=16)) set_mask(mask, x - 1, y - 1, 4); // Déplacement vers le haut à gauche
        if ((x > 0) and (y < 7) and (get_square(plateau,x - 1,y + 1) <=16)) set_mask(mask, x - 1, y + 1, 4); // Déplacement vers le haut à droite
        if ((x < 7) and (y > 0) and (get_square(plateau,x + 1,y - 1) <=16)) set_mask(mask, x + 1, y - 1, 4); // Déplacement vers le bas à gauche
        if ((x < 7) and (y < 7) and (get_square(plateau,x + 1,y + 1) <=16)) set_mask(mask, x + 1, y + 1, 4); // Déplacement vers le bas à droite
    }
    else { // Pièce noire
        // Déplacement en ligne droite
        if ((x > 0) and ((get_square(plateau,x - 1,y) == 0) or (get_square(plateau,x - 1,y) >16) )) set_mask(mask, x - 1, y, 4); // Déplacement vers le haut
        if ((x < 7) and ((get_square(plateau,x + 1,y) == 0) or (get_square(plateau,x + 1,y) >16) )) set_mask(mask, x + 1, y, 4); // Déplacement vers le bas
        if ((y > 0) and ((get_square(plateau,x,y - 1) == 0) or (get_square(plateau,x,y - 1) >16) )) set_mask(mask, x, y - 1, 4); // Déplacement vers la gauche
        if ((y < 7) and ((get_square(plateau,x,y + 1) == 0) or (get_square(plateau,x,y + 1) >16) )) set_mask(mask, x, y + 1, 4); // Déplacement vers la droite

        // Déplacement en diagonale
        if ((x > 0) and (y > 0) and (get_square(plateau,x - 1,y - 1) == 0 or get_square(plateau,x - 1,y - 1) >16) ) set_mask(mask, x - 1, y - 1, 4); // Déplacement vers le haut à gauche
        if ((x > 0) and (y < 7) and (get_square(plateau,x - 1,y + 1) == 0 or get_square(plateau,x - 1,y + 1) >16) ) set_mask(mask, x - 1, y + 1, 4); // Déplacement vers le haut à droite
        if ((x < 7) and (y > 0) and (get_square(plateau,x + 1,y - 1) == 0 or get_square(plateau,x + 1,y - 1) >16) ) set_mask(mask, x + 1, y - 1, 4); // Déplacement vers le bas à gauche
        if ((x < 7) and (y < 7) and (get_square(plateau,x + 1,y + 1) == 0 or get_square(plateau,x + 1,y + 1) >16) ) set_mask(mask, x + 1, y + 1, 4); // Déplacement vers le bas à droite
    }
}

void highlight_possible_moves_rook(Plateau *plateau, int x, int y, Mask *mask){
    // Affiche les déplacements possibles d'une tour
    // paramètre : Pointeur plateau
    // paramètre : x (int)
    // paramètre : y (int)
    // paramètre : mask (Pointeur Mask)

    set_mask(mask, x, y, 5); // Position de la tour
    // Déplacement vers le haut
    for (int i=x-1;i>=0;i--){
        if (get_square(plateau,i,y)==0) set_mask(mask,i, y, 4);
        else{
            if (((get_square(plateau,i,y)>16) and (get_square(plateau,x,y) < 17)) or ((get_square(plateau,x,y)>16) and (get_square(plateau,i,y) <17))) set_mask(mask, i, y, 1);
            break;

        }
    }
    // Déplacement vers le bas
    for (int i=x+1;i<8;i++){
        if (get_square(plateau,i,y)==0) set_mask(mask,i, y, 4);
        else{
            if (((get_square(plateau,i,y)>16) and (get_square(plateau,x,y) < 17)) or ((get_square(plateau,x,y)>16) and (get_square(plateau,i,y) <17))) set_mask(mask, i, y, 1);
            break;

        }
    }

    // Déplacement vers la gauche
    for (int i=y-1;i>=0;i--){
        if (get_square(plateau,x,i)==0) set_mask(mask,x, i, 4);
        else{
            if (((get_square(plateau,x,i)>16) and (get_square(plateau,x,y) < 17)) or ((get_square(plateau,x,y)>16) and (get_square(plateau,x,i) <17))) set_mask(mask, x, i, 1);
            break;
        }
    }

    // Déplacement vers la droite
    for (int i=y+1;i<8;i++){
        if (get_square(plateau,x,i)==0) set_mask(mask,x, i, 4);
        else{
            if (((get_square(plateau,x,i)>16) and (get_square(plateau,x,y) < 17)) or ((get_square(plateau,x,y)>16) and (get_square(plateau,x,i) <17))) set_mask(mask, x, i, 1);
            break;
        }
    }
}
void highlight_possible_moves_bishop(Plateau* plateau,int x,int y,Mask* mask){
    // Affiche les déplacements possibles d'un fou
    // paramètre : plateau (Pointeur Plateau)
    // paramètre : x (int)
    // paramètre : y (int)
    // paramètre : mask (Pointeur Mask)

    set_mask(mask, x, y, 5); // Position du bishop
        if ((x - 1 >= 0) and (y - 1 >= 0)) { // Déplacement haut gauche
            int i = x - 1;
            int j = y - 1;
            while ((i >= 0) and (j >= 0)) {
                if ((get_square(plateau, i, j) == 0))set_mask(mask, i, j, 4); // Si case vide
                else {
                    if (((get_square(plateau,i,j)>16) and (get_square(plateau,x,y) < 17)) or ((get_square(plateau,x,y)>16) and (get_square(plateau,i,j) <17))) set_mask(mask, i, j, 1);
                    break;
                }
                i--;
                j--;
            }
        }
        if ((x - 1 >= 0) and (y + 1 <8)) { // Déplacement bas gauche
            int i = x - 1;
            int j = y + 1;
            while ((i >= 0) and (j < 8)) {
                if ((get_square(plateau, i, j) == 0))set_mask(mask, i, j, 4); // Si case vide
                else {
                    if (((get_square(plateau,i,j)>16) and (get_square(plateau,x,y) < 17)) or ((get_square(plateau,x,y)>16) and (get_square(plateau,i,j) <17))) set_mask(mask, i, j, 1);
                    break;
                }
                i--;
                j++;
            }
        }
        if ((x + 1 <8) and (y - 1 >= 0)) { // Déplacement haut droite
            int i = x + 1;
            int j = y - 1;
            while ((i <8) and (j >= 0)) {
                if ((get_square(plateau, i, j) == 0))set_mask(mask, i, j, 4); // Si case vide
                else {
                    if (((get_square(plateau,i,j)>16) and (get_square(plateau,x,y) < 17)) or ((get_square(plateau,x,y)>16) and (get_square(plateau,i,j) <17))) set_mask(mask, i, j, 1);
                    break;
                }
                i++;
                j--;
            }
        }
        if ((x + 1 <8) and (y + 1 <8)) { // Déplacement bas droite
            int i = x + 1;
            int j = y + 1;
            while ((i <8) and (j <8)) {
                if ((get_square(plateau, i, j) == 0))set_mask(mask, i, j, 4); // Si case vide
                else {
                    if (((get_square(plateau,i,j)>16) and (get_square(plateau,x,y) < 17)) or ((get_square(plateau,x,y)>16) and (get_square(plateau,i,j) <17))) set_mask(mask, i, j, 1);
                    break;
                }
                i++;
                j++;
            }
        }
}

void highlight_possible_moves_queen(Plateau* plateau,int x,int y,Mask* mask){
    // Affiche les déplacements possibles d'une reine
    // paramètre : plateau (Pointeur Plateau)
    // paramètre : x (int)
    // paramètre : y (int)
    // paramètre : mask (Pointeur Mask)
    set_mask(mask, x, y, 5); // Position de la reine
    Mask mask_rook=empty_mask();
    Mask mask_bishop=empty_mask();
    highlight_possible_moves_rook(plateau,x,y,&mask_rook);
    highlight_possible_moves_bishop(plateau,x,y,&mask_bishop);
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if ((get_mask(&mask_rook,i,j)==4) or (get_mask(&mask_bishop,i,j)==4)) set_mask(mask,i,j,4);
            if ((get_mask(&mask_rook,i,j)==1) or (get_mask(&mask_bishop,i,j)==1)) set_mask(mask,i,j,1);
        }
    }

}

void highlight_possible_moves_knight(Plateau* plateau,int x,int y,Mask* mask){
    // Affiche les déplacements possibles d'un cavalier
    // paramètre : plateau (Pointeur Plateau)
    // paramètre : x (int)
    // paramètre : y (int)
    // paramètre : mask (Pointeur Mask)

    set_mask(mask, x, y, 5);
    int val_piece = get_square(plateau, x, y);
    if ((y + 2 < 8) and (x - 1 >= 0)) {
        if ((get_square(plateau, x - 1, y + 2) == 0)) set_mask(mask, x - 1, y + 2, 4);
        else {
            if ((val_piece > 16) and (get_square(plateau, x - 1, y + 2) < 17)) set_mask(mask, x - 1, y + 2, 1); // Si pièce noire
            if ((val_piece < 17) and (get_square(plateau, x - 1, y + 2) > 16)) set_mask(mask, x - 1, y + 2, 1); // Si pièce blanche
        }
    }
    if ((y + 2 < 8) and (x + 1 < 8)) {
        if ((get_square(plateau, x + 1, y + 2) == 0)) set_mask(mask, x + 1, y + 2, 4); // Si case vide
        else {
            if ((val_piece > 16) and (get_square(plateau, x + 1, y + 2) < 17)) set_mask(mask, x + 1, y + 2, 1); // Si pièce noire
            if ((val_piece < 17) and (get_square(plateau, x + 1, y + 2) > 16)) set_mask(mask, x + 1, y + 2, 1); //Si pièce blanche
        }
    }
    if ((y - 2 >= 0) and (x - 1 >= 0)) {
        if (get_square(plateau, x - 1, y - 2) == 0) set_mask(mask, x - 1, y - 2, 4); // Si case vide
        else {
            if ((val_piece > 16) and (get_square(plateau, x - 1, y - 2) < 17)) set_mask(mask, x - 1, y - 2, 1); // Si pièce noire
            if ((val_piece < 17) and (get_square(plateau, x - 1, y - 2) > 16)) set_mask(mask, x - 1, y - 2, 1); // Si pièce blanche
        }
    }
    if ((y - 2 >= 0) and (x + 1 < 8)) {
        if ((get_square(plateau, x + 1, y - 2) == 0)) set_mask(mask, x + 1, y - 2, 4); // Si case vide
        else {
            if ((val_piece > 16) and (get_square(plateau, x + 1, y - 2) < 17)) set_mask(mask, x + 1, y - 2, 1); // Si pièce noire
            if ((val_piece < 17) and (get_square(plateau, x + 1, y - 2) > 16)) set_mask(mask, x + 1, y - 2, 1); // Si pièce blanche
        }
    }
    if ((y - 1 >= 0) and (x - 2 >= 0)) {
        if ((get_square(plateau, x - 2, y - 1) == 0)) set_mask(mask, x - 2, y - 1, 4); // Si case vide
        else {
            if ((val_piece > 16) and (get_square(plateau, x - 2, y - 1) < 17)) set_mask(mask, x - 2, y - 1, 1); // Si pièce noire
            if ((val_piece < 17) and (get_square(plateau, x - 2, y - 1) > 16)) set_mask(mask, x - 2, y - 1, 1); // Si pièce blanche
        }
    }
    if ((y + 1 < 8) and (x - 2 >= 0)) {
        if ((get_square(plateau, x - 2, y + 1) == 0)) set_mask(mask, x - 2, y + 1, 4); // Si case vide
        else {
            if ((val_piece > 16) and (get_square(plateau, x - 2, y + 1) < 17)) set_mask(mask, x - 2, y + 1, 1); // Si pièce noire
            if ((val_piece < 17) and (get_square(plateau, x - 2, y + 1) > 16)) set_mask(mask, x - 2, y + 1, 1); // Si pièce blanche
        }
    }
    if ((y - 1 >= 0) and (x + 2 < 8)) {
        if ((get_square(plateau, x + 2, y - 1) == 0)) set_mask(mask, x + 2, y - 1, 4); // Si case vide
        else {
            if ((val_piece > 16) and (get_square(plateau, x + 2, y - 1) < 17)) set_mask(mask, x + 2, y - 1, 1); // Si pièce noire
            if ((val_piece < 17) and (get_square(plateau, x + 2, y - 1) > 16)) set_mask(mask, x + 2, y - 1, 1); // Si pièce blanche
        }
    }
    if ((y + 1 < 8) and (x + 2 < 8)) {
        if ((get_square(plateau, x + 2, y + 1) == 0)) set_mask(mask, x + 2, y + 1, 4); // Si case vide
        else {
            if ((val_piece > 16) and (get_square(plateau, x + 2, y + 1) < 17)) set_mask(mask, x + 2, y + 1, 1); // Si pièce noire
            if ((val_piece < 17) and (get_square(plateau, x + 2, y + 1) > 16)) set_mask(mask, x + 2, y + 1, 1); // Si pièce blanche
        }
    }
}

void highlight_possible_moves_pawn(Plateau* plateau,int x,int y,Mask* mask) {
    // Affiche les déplacements possibles d'un pion
    // paramètre : plateau (Pointeur Plateau)
    // paramètre : x (int)
    // paramètre : y (int)
    // paramètre : mask (Pointeur Mask)

    set_mask(mask, x, y, 5);
    int val_piece = get_square(plateau, x, y);
    if (val_piece < 17) { // Pièce noire
        if (x == 1) { // Ligne de départ
            if (get_square(plateau, x + 1, y) == 0) {
                set_mask(mask, x + 1, y, 4);
                if (get_square(plateau, x + 2, y) == 0) {
                    set_mask(mask, x + 2, y, 4);
                }
            }

        } else {
            if (get_square(plateau, x + 1, y) == 0) {
                set_mask(mask, x + 1, y, 4);
            }
        }
        if (get_square(plateau, x + 1, y + 1) > 16) { // Prise à droite
            set_mask(mask, x + 1, y + 1, 1);
        }
        if (get_square(plateau, x + 1, y - 1) > 16) { // Prise à gauche
            set_mask(mask, x + 1, y - 1, 1);
        }
    } else { // Pièce blanche
        if (x == 6) { // Ligne de départ
            if (get_square(plateau, x - 1, y) == 0) {
                set_mask(mask, x - 1, y, 4);
                if (get_square(plateau, x - 2, y) == 0) {
                    set_mask(mask, x - 2, y, 4);
                }
            }
        } else {
            if (get_square(plateau, x - 1, y) == 0) {
                set_mask(mask, x - 1, y, 4);
            }
        }
        if (get_square(plateau, x - 1, y - 1) < 17 and get_square(plateau, x - 1, y - 1) > 0) { // Prise à gauche
            set_mask(mask, x - 1, y - 1, 1);
        }
        if (get_square(plateau, x - 1, y + 1) < 17 and get_square(plateau, x - 1, y + 1) > 0) { // Prise à droite
            set_mask(mask, x - 1, y + 1, 1);
        }
    }
}
void highlight_movable_pieces(Plateau* plateau,Mask* mask,int color){
    // Affiche les déplacements possibles de toutes les pièces d'une couleur
    // paramètre : plateau (Pointeur Plateau)
    // paramètre : mask (Pointeur Mask)
    Mask mask_intermediaire = empty_mask();
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if (get_square(plateau,i,j)!=0) {
                if ((color == 0 and get_square(plateau, i, j) > 16) or (color == 1 and get_square(plateau, i, j) < 17))
                    highlight_possible_moves(plateau, i, j, &mask_intermediaire);
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if ((get_mask(&mask_intermediaire, k, l) == 4) or (get_mask(&mask_intermediaire, k, l) == 1)) {
                            set_mask(mask, i, j, 6);
                        }
                    }
                }
                clear_mask(&mask_intermediaire);
            }
        }
    }
}

void highlight_attacked_pieces(Plateau* plateau,Mask* mask,int color){
    // Affiche les pièces qui peuvent être attaquées par le joueur
    // paramètre : plateau (Pointeur Plateau)
    // paramètre : mask (Pointeur Mask)
    Mask mask_intermediaire = empty_mask();
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if (get_square(plateau,i,j)!=0) {
                if ((color == 0 and get_square(plateau, i, j) > 16) or (color == 1 and get_square(plateau, i, j) < 17))
                    highlight_possible_moves(plateau, i, j, &mask_intermediaire);
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if (get_mask(&mask_intermediaire, k, l) == 1) {
                            set_mask(mask, k, l, 1);
                        }
                    }
                }
                clear_mask(&mask_intermediaire);
            }
        }
    }
}

void highlight_take_pieces(Plateau* plateau,Mask* mask,int color){
    // Affiche les pièces qui peuvent prendre une/des pièce/s du joueur
    // paramètre : plateau (Pointeur Plateau)
    // paramètre : mask (Pointeur Mask)
    Mask mask_intermediaire = empty_mask();
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if (get_square(plateau,i,j)!=0) {
                if ((color == 0 and get_square(plateau, i, j) <17) or (color == 1 and get_square(plateau, i, j) > 16))
                    highlight_possible_moves(plateau, i, j, &mask_intermediaire);
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if (get_mask(&mask_intermediaire, k, l) == 1) {
                            set_mask(mask, i, j, 1);
                        }
                    }
                }
                clear_mask(&mask_intermediaire);
            }
        }
    }
}

void mask_choices_menu(Plateau* plateau,Mask* mask,int player,int turn,int* abandon) {
    // Affiche le menu des masks
    int choix;
    cout << "Veuillez choisir un mask à visualiser : " << endl;
    cout << "1. Affichage des pièces qui peuvent bouger" << endl;
    cout << "2. Affichage des pièces qui peuvent attaquer une ou plusieurs de vos pièces" << endl;
    cout << "3. Affichage de vos pièces qui peuvent manger une pièces adverse" << endl;
    cout << "4. Affichage des coups possibles d'une de vos pièces en particulier" << endl;
    cout << "5. Quitter" << endl;
    cout << "Votre choix : ";
    cin >> choix;
    cout << endl;
    if (choix == 5) {
        one_run_human(plateau, mask, player, turn,abandon);
        return;
    }
    if (choix == 1) {
        highlight_movable_pieces(plateau, mask, turn);
        print_board_color(plateau, mask);
        clear_mask(mask);
        mask_choices_menu(plateau, mask, player, turn,abandon);
        return;
    }
    if (choix == 2) {
        highlight_take_pieces(plateau, mask, turn);
        print_board_color(plateau, mask);
        clear_mask(mask);
        mask_choices_menu(plateau, mask, player, turn,abandon);
        return;
    }
    if (choix == 3) {
        highlight_attacked_pieces(plateau, mask, turn);
        print_board_color(plateau, mask);
        clear_mask(mask);
        mask_choices_menu(plateau, mask, player, turn,abandon);
        return;
    }
    if (choix == 4) {
        int x, y;
        cout << "Veuillez entrer la position de la pièce que vous voulez consulter :" << endl;
        cout << "- Format: 'B7' / 'C3' / 'F1' / ..." << endl;
        cout << "Votre choix : ";
        string consulter;
        cin >> consulter;
        cout << endl;
        H_coord_to_C_coord(consulter, &x, &y);
        highlight_possible_moves(plateau, x, y, mask);
        while (get_mask(mask, x, y) == 0) {
            cout << endl;
            cout << "Erreur: Vous ne pouvez pas consulter les coups possibles d'une case vide." << endl;
            cout << endl;
            cout << "Veuillez entrer la position de la pièce que vous voulez consulter :" << endl;
            cout << "- Format: 'B7' / 'C3' / 'F1' / ..." << endl;
            cout << "Votre choix : ";
            string consulter;
            cin >> consulter;
            cout << endl;
            H_coord_to_C_coord(consulter, &x, &y);
            highlight_possible_moves(plateau, x, y, mask);
        }
        print_board_color(plateau, mask);
        clear_mask(mask);
        mask_choices_menu(plateau, mask, player, turn,abandon);
        return;
    }
    cout << endl;
    cout << "Erreur: Ce choix n'est pas disponible ou n'existe pas." << endl;
    cout << endl;
    mask_choices_menu(plateau, mask, player, turn,abandon);
    return;

}


