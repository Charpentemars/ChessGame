#pragma once
#include "../board/board.hpp"
#include "../view/view.hpp"

using namespace std;

Mask empty_mask();

void clear_mask(Mask*);

int get_mask(Mask*,int,int);

void set_mask(Mask*,int,int,int);

void highlight_possible_moves(Plateau*,int,int,Mask*);

void highlight_possible_moves_king(Plateau*, int, int, Mask*);

void highlight_possible_moves_rook(Plateau*, int, int, Mask*);

void highlight_possible_moves_bishop(Plateau*,int, int, Mask*);

void highlight_possible_moves_queen(Plateau*,int, int, Mask*);

void highlight_possible_moves_knight(Plateau*,int, int, Mask*);

void highlight_possible_moves_pawn(Plateau*,int, int, Mask*);

void highlight_movable_pieces(Plateau*,Mask*,int);

void highlight_attacked_pieces(Plateau*,Mask*,int);

void highlight_take_pieces(Plateau*,Mask*,int);

void mask_choices_menu(Plateau*,Mask*,int,int,int*);
