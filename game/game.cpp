// TP Info7 : Jeu d'Echec
// Antoine Ducourant & Khamzat Baoudinov : Team \(^_^)/
#include <iostream>
#include "../board/board.hpp"
#include "../mask/mask.hpp"
#include "../view/view.hpp"
#include "../game/game.hpp"

void one_run(Plateau* plateau,Mask* mask,int player, int turn,int* abandon){
    // lance la fonction correspondante au type du joueur
    // paramètre : player (int) : 0 pour joueur1, 1 pour joueur2
    if(player == 0) {
            one_run_human(plateau,mask,player,turn,abandon);
    }
}
void H_coord_to_C_coord(string H_move, int* x, int* y){
    // convertit les coordonnées humaines en coordonnées de la matrice
    // paramètre : H_move (string) : coordonnées humaines(ex b4,b7)
    // paramètre : x (Pointeur int) : coordonnée x de la matrice
    // paramètre : y (Pointeur int) : coordonnée y de la matrice
    for(char c : H_move){
        if ((c == 'a') or (c == 'A')) *y = 0;
        if ((c == 'b') or (c == 'B')) *y = 1;
        if ((c == 'c') or (c == 'C')) *y = 2;
        if ((c == 'd') or (c == 'D')) *y = 3;
        if ((c == 'e') or (c == 'E')) *y = 4;
        if ((c == 'f') or (c == 'F')) *y = 5;
        if ((c == 'g') or (c == 'G')) *y = 6;
        if (c == 'h') *y = 7;
        if (c == '1') *x = 7;
        if (c == '2') *x = 6;
        if (c == '3') *x = 5;
        if (c == '4') *x = 4;
        if (c == '5') *x = 3;
        if (c == '6') *x = 2;
        if (c == '7') *x = 1;
        if (c == '8') *x = 0;
    }
}

void choose_mouvement_human(Plateau* plateau,Mask* mask, int player){
    // demande au joueur de choisir un mouvement
    // paramète : plateau (Pointeur plateau)
    // paramètre : mask (Pointeur mask)
    // paramètre : player (int) : 0 pour joueur1, 1 pour joueur2


    string mouvement;
    int x1, y1, x2, y2;
    if (king_in_check(plateau, mask, player)){
        cout << "Votre roi est en échec !" << endl;
        cout << "Vous devez le protéger !" << endl;
        cout << endl;

    }
    print_board_color(plateau, mask);
    cout << "Veuillez entrer la position de départ la pièce que vous voulez jouer :" << endl;
    cout << "- Format: 'B7' / 'C3' / 'F1' / ..." << endl;
    cout << "- Pour quitter, veuillez répondre 'Q'" << endl;
    cout<< "Votre choix : ";
    cin >> mouvement;
    if ((mouvement == "Q") or (mouvement == "q")) {
        return;
    }

    H_coord_to_C_coord(mouvement, &x1, &y1);
    if ((get_square(plateau, x1, y1) != 0) and (((get_square(plateau, x1, y1) < 17) and (player == 1)) or((get_square(plateau, x1, y1) > 16) and (player == 0)))) {
        cout << endl;
        cout << "Veuillez entrer la position finale de la pièce que vous voulez jouer :" << endl;
        cout << "- Format: 'B7' / 'C3' / 'F1' / ..." << endl;
        cout << "- Pour quitter, veuillez répondre 'Q'" << endl;
        cout << "- Pour revenir en arrière, veuillez répondre R"<< endl;
        cout<< "Votre choix : ";
        cin >> mouvement;
        H_coord_to_C_coord(mouvement, &x2, &y2);
        cout<< endl;
        if ((mouvement == "Q") or (mouvement == "q")) {
            cout<< endl;
            return;
        }
        if ((mouvement == "R") or (mouvement == "r")) {
            cout<< endl;
            return choose_mouvement_human(plateau, mask, player);

        }

        if ((get_square(plateau, x2, y2) == 0) or (((get_square(plateau, x2, y2) < 17) and (player == 0)) or((get_square(plateau, x2, y2) > 16) and (player == 1)))) {
            highlight_possible_moves(plateau, x1, y1, mask);
            if ((get_mask(mask, x2, y2)==1) or (get_mask(mask, x2, y2)==4))  {
                move_piece(plateau, x1, y1, x2, y2);
                clear_mask(mask);
                return;
            }
            else {
                cout << endl;
                cout << "Erreur: Vous ne pouvez pas attaquer votre propre pièce." << endl;
                cout << endl;
                clear_mask(mask);
                choose_mouvement_human(plateau, mask, player);
                return;
            }
        }
    }
    cout << endl;
    cout << "Erreur: Vous n'avez pas de pièce à cet endroit." << endl;
    cout << endl;
    return;
}
void one_run_human(Plateau* plateau, Mask* mask, int player, int turn, int* abandon) {
    // Réalise les étapes pour qu'un joueur puisse jouer
    // paramètre : plateau (Pointeur plateau)
    // paramètre : mask (Pointeur mask)
    // paramètre : player (int) : 0 pour joueur1, 1 pour joueur2

    int choix = 0;
    print_board_color(plateau);
    cout << "C'est au tour du joueur " << turn+1 << ":" << endl;
    cout << "1. Jouer un coup" << endl;
    cout << "2. Afficher les masks" << endl;
    cout << "3: Sauvegarder la partie" << endl;
    cout << "4. Charger une partie" << endl;
    cout << "5. Quitter la partie" << endl;
    cout << "Votre choix : ";
    cin >> choix;
    cout << endl;
    if (choix == 1) {
        choose_mouvement_human(plateau, mask, turn);
        return;
    }
    if (choix == 2) {
        mask_choices_menu(plateau, mask, player, turn, abandon);
        return;
    }
    if (choix == 3) {
        write_FEN(plateau, "FEN/save.txt");
        cout << "Partie sauvegardée avec succès." << endl;
        one_run_human(plateau, mask, player, turn, abandon);
        return;
    }
    if (choix == 4) {
        read_FEN(plateau, "FEN/save.txt");
        cout << "Partie chargée avec succès." << endl;
        one_run_human(plateau, mask, player, turn, abandon);
        return;
    }
    if (choix == 5) {
        if (turn==0){
            cout<< "Le joueur 2 a gagné par abandon du joueur 1." << endl;
            *abandon=turn;
        }
        else {
            cout<< "Le joueur 1 a gagné par abandon du joueur 2." << endl;
            *abandon=turn;
        }
        cout << "Partie quittée avec succès." << endl;
        cout << "Merci d'avoir joué à ChessGame. À bientôt :)" << endl;
        return;
    }
    cout << endl;
    cout << "Erreur: Ce choix n'est pas disponible ou n'existe pas." << endl;
    cout << endl;
    one_run_human(plateau, mask, player, turn, abandon);
    return;
}

bool king_in_check(Plateau* plateau,Mask* mask,int player) {
    // Vérifie si le roi du joueur est en échec
    // paramètre : plateau (Pointeur plateau)
    // paramètre : player (int) : 0 pour joueur1 (blanc), 1 pour joueur2 (noir)
    // retourne : True si le roi est en échec, False sinon

    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if (((get_square(plateau,i,j)== 16) and (player == 1)) or ((get_square(plateau,i,j)== 32) and (player == 0))){ // Roi noir et joueur1
                if (get_mask(mask,i,j)==1) { // Roi en échec
                    set_mask(mask,i,j,5);
                    return true;
                }
                else { // Roi pas en échec
                    clear_mask(mask);
                    return false;
                }
            }
        }
    }
    return false;
}













