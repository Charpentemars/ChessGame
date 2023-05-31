// TP Info7 : Jeu d'Echec
// Antoine Ducourant & Khamzat Baoudinov : Team \(^_^)/
#include <iostream>
#include "board/board.hpp"
#include "mask/mask.hpp"
#include "view/view.hpp"
#include "game/game.hpp"

int main(int argc, char* argv[]){
    int choix = 0;
    int abandon = -1;
    while (choix != 2){
        cout << "Bienvenue dans le jeu d'echec !" << endl;
        cout << endl;
        cout << "Sélectionnez une option : " << endl;
        cout << "1. Afficher les règles" << endl;
        cout << "2. Commencer la partie" << endl;
        cout << "3. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;
        cout << endl;
        if ((choix == 3) or (choix ==2))break;
        if (choix == 1) rules();

    }
    if (choix == 2){
        Plateau plateau = start();
        Mask mask = empty_mask();

        int turn = 0; // Tour
        int player1 = 0; // Joueur 1
        int player2 = 0; // Joueur 2

        // Choix du joueur 1
        int choix = 0;
        cout << "Sélectionnez le type du joueur 1 : " << endl;
        cout << "1. Humain" << endl;
        cout << "2. Aléatoire (IA)" << endl;
        cout << "Votre choix : ";
        cin >> choix;
        cout << endl;

        if (choix == 1){
            player1 = 0;
        }
        if (choix == 2){
            player1 = 1;
        }

        // Choix du joueur 2
        choix = 0;
        cout << "Sélectionnez le type du joueur 2 : " << endl;
        cout << "1. Humain" << endl;
        cout << "2. Aléatoire (IA)" << endl;
        cout << "Votre choix : ";
        cin >> choix;
        cout << endl;

        if (choix == 1){
            player2 = 0;
        }
        if (choix == 2){
            player2 = 1;
        }
        int fin=0;
        // Début de la partie
        while (fin==0){
            if (turn == 0) {
                if (player1 == 0) { // Joueur1 humain
                    one_run(&plateau, &mask, 0, turn, &abandon);

                }
                if (player1 == 1) { // Joueur1 Aléatoire (IA)
                    one_run(&plateau, &mask, 1, turn, &abandon);
                }
                if (abandon == 0)return 0;
                turn = 1;
            }
            else { // (turn == 1)
                if (player2 == 0) { // Joueur2 humain
                    one_run(&plateau, &mask, 0, turn, &abandon);

                }
                if (player2 == 1) { // Joueur2 Aléatoire (IA)
                    one_run(&plateau, &mask, 1, turn, &abandon);

                }
                if (abandon == 1)return 0;
                turn = 0;
            }


        }
    }
    return 0;
}
