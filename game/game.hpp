#pragma once
using namespace std;

#include "../board/board.hpp"
#include "../mask/mask.hpp"
#include "../view/view.hpp"

void one_run(Plateau* ,Mask* ,int, int, int*);

void H_coord_to_C_coord(string, int*, int*);

void choose_mouvement_human(Plateau* ,Mask* , int);

void one_run_human(Plateau* , Mask* , int, int, int*);

bool king_in_check(Plateau*,Mask*,int);