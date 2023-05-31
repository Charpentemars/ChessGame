// TP Info7 : Jeu d'Echec
// Antoine Ducourant & Khamzat Baoudinov : Team \(^_^)/
#include <iostream>
#include "board/board.hpp"
#include "mask/mask.hpp"
#include "view/view.hpp"
#include "game/game.hpp"

int main(){
    Plateau plateau = start();
    Mask mask = empty_mask();

    // MOVE TEST // OK
    //move_piece(&plateau, 1, 0, 3, 0);
    //move_piece(&plateau, 1, 7, 3, 7);
    //move_piece(&plateau, 6, 0, 4, 0);
    //move_piece(&plateau, 6, 7, 4, 7);
    //print_board(&plateau);

    // PRINT_BOARD // OK
    // print_board(&plateau);

    // TEST_READ_FEN // OK
    //read_FEN(&plateau, "FEN/FEN0.txt");
    //print_board(&plateau);

    // TEST_WRITE_FEN // OK
    /* write_FEN(&plateau, "FEN/FEN0.txt");
    print_board(&plateau);*/

    // TEST_PRINT_BOARD_COLOR // OK
    // print_board_color(&plateau);

    // TEST_PRINT_BOARD_COLOR_WITH_MASK // OK
    /*Mask mask = empty_mask();
    set_mask(&mask, 0, 0, 0);
    set_mask(&mask, 1, 0, 0);
    set_mask(&mask, 2, 0, 0);
    set_mask(&mask, 3, 0, 0);
    set_mask(&mask, 4, 0, 0);
    set_mask(&mask, 5, 0, 0);
    set_mask(&mask, 6, 0, 0);
    set_mask(&mask, 7, 0, 0);
    set_mask(&mask, 0, 1, 1);
    set_mask(&mask, 1, 1, 1);
    set_mask(&mask, 2, 1, 1);
    set_mask(&mask, 3, 1, 1);
    set_mask(&mask, 4, 1, 1);
    set_mask(&mask, 5, 1, 1);
    set_mask(&mask, 6, 1, 1);
    set_mask(&mask, 7, 1, 1);
    set_mask(&mask, 0, 2, 2);
    set_mask(&mask, 1, 2, 2);
    set_mask(&mask, 2, 2, 2);
    set_mask(&mask, 3, 2, 2);
    set_mask(&mask, 4, 2, 2);
    set_mask(&mask, 5, 2, 2);
    set_mask(&mask, 6, 2, 2);
    set_mask(&mask, 7, 2, 2);
    set_mask(&mask, 0, 3, 3);
    set_mask(&mask, 1, 3, 3);
    set_mask(&mask, 2, 3, 3);
    set_mask(&mask, 3, 3, 3);
    set_mask(&mask, 4, 3, 3);
    set_mask(&mask, 5, 3, 3);
    set_mask(&mask, 6, 3, 3);
    set_mask(&mask, 7, 3, 3);
    set_mask(&mask, 0, 4, 4);
    set_mask(&mask, 1, 4, 4);
    set_mask(&mask, 2, 4, 4);
    set_mask(&mask, 3, 4, 4);
    set_mask(&mask, 4, 4, 4);
    set_mask(&mask, 5, 4, 4);
    set_mask(&mask, 6, 4, 4);
    set_mask(&mask, 7, 4, 4);
    set_mask(&mask, 0, 5, 5);
    set_mask(&mask, 1, 5, 5);
    set_mask(&mask, 2, 5, 5);
    set_mask(&mask, 3, 5, 5);
    set_mask(&mask, 4, 5, 5);
    set_mask(&mask, 5, 5, 5);
    set_mask(&mask, 6, 5, 5);
    set_mask(&mask, 7, 5, 5);
    set_mask(&mask, 0, 6, 6);
    set_mask(&mask, 1, 6, 6);
    set_mask(&mask, 2, 6, 6);
    set_mask(&mask, 3, 6, 6);
    set_mask(&mask, 4, 6, 6);
    set_mask(&mask, 5, 6, 6);
    set_mask(&mask, 6, 6, 6);
    set_mask(&mask, 7, 6, 6);
    set_mask(&mask, 0, 7, 7);
    set_mask(&mask, 1, 7, 7);
    set_mask(&mask, 2, 7, 7);
    set_mask(&mask, 3, 7, 7);
    set_mask(&mask, 4, 7, 7);
    set_mask(&mask, 5, 7, 7);
    set_mask(&mask, 6, 7, 7);
    set_mask(&mask, 7, 7, 7);
    print_board_color(&plateau, &mask);*/

    // HIGHLIGHT_MOVE_KING // OK
    /*move_piece(&plateau, 0, 4, 3, 3);
    move_piece(&plateau, 6, 4, 4, 4);
    move_piece(&plateau, 6, 3, 4, 3);
    move_piece(&plateau, 1, 4, 3, 4);
    highlight_possible_moves(&plateau, 3, 3);
    print_board_color(&plateau, &mask);*/

    // HIGHLIGHT_MOVE_ROOK // OK
    /*move_piece(&plateau, 0, 0, 3, 0);
    move_piece(&plateau, 6, 4, 4, 4);
    move_piece(&plateau, 6, 3, 4, 3);
    move_piece(&plateau, 1, 4, 3, 4);
    highlight_possible_moves_rook(&plateau, 3, 0);
    print_board_color(&plateau, &mask);*/

    // HIGHLIGHT_MOVE_BISHOP // OK
    /*move_piece(&plateau, 7, 5, 2, 5);
    highlight_possible_moves_bishop(&plateau, 2, 5);
    print_board_color(&plateau, &mask);*/

    // HIGHLIGHT_MOVE_QUEEN // OK
    /*move_piece(&plateau, 0, 3, 3, 3);
    move_piece(&plateau, 6, 6, 3, 6);
    highlight_possible_moves_queen(&plateau, 3, 3);
    print_board_color(&plateau, &mask);*/

    // HIGHLIGHT_MOVE_KNIGHT // OK
    /*move_piece(&plateau, 0, 1, 4, 1);
    move_piece(&plateau, 6, 6, 4, 6);
    highlight_possible_moves_knight(&plateau, 4, 1);
    print_board_color(&plateau, &mask);*/

    // HIGHLIGHT_MOVE_PAWN // OK
    //move_piece(&plateau, 0, 0, 3, 0);
    //move_piece(&plateau, 1, 6, 4, 6);
    //move_piece(&plateau, 6, 7, 3, 7);
    //move_piece(&plateau,1 , 3, 4, 3);
    //move_piece(&plateau, 1, 5, 4, 5);
    //move_piece(&plateau, 6, 4, 5, 4);
    //print_board_color(&plateau, &mask);

    // HIGHLIGHT_POSSIBLE_MOVES // OK
    //highlight_possible_moves(&plateau,0,0,&mask);
    //highlight_possible_moves(&plateau, 2, 2, &mask);

    // HIGHLIGHT_MOVABLE_PIECES // OK
    //highlight_movable_pieces(&plateau, &mask, 1);

    // HIGHLIGHT_ATTACKED_PIECES // OK
    //highlight_attacked_pieces(&plateau, &mask, 1);

    // HIGHLIGHT_TAKE_PIECES // OK
    //read_FEN(&plateau, "FEN/FEN3.txt");
    //highlight_take_pieces(&plateau, &mask, 1);
    //print_board_color(&plateau, &mask);

    // TEST_ONE_RUN_HUMAN // OK
    //read_FEN(&plateau, "FEN/FEN3.txt");
    //one_run_human(&plateau, &mask, 1);

    // HIGHLIGHT_ALL_TAKES_PIECES //
    highlight_possible_moves_pawn(&plateau, 1, 1, &mask);
    print_board_color(&plateau, &mask);

}