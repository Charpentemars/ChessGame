#pragma once
#include "../types/types.hpp"
#include <fstream>
using namespace std;

void empty(Plateau*);

int get_square(Plateau*, int, int);

void set_square(Plateau*, int, int, int);

Plateau start();

void move_piece(Plateau*, int, int, int, int);

string IntToString(int);

void write_FEN(Plateau*, char*);

void read_FEN(Plateau*, char*);