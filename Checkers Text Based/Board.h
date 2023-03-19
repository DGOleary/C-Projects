#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Checker.h"
using namespace std;

class Board{
private:
string game_board[8][8];
Checker piece_board[8][8];
//player true is x and false is o
bool player;
bool won;
//game is won when one person reaches 0 pieces
int x_count;
int o_count;

public:
Board();
bool getPlayer();
void printBoard();
bool makeMove(int x, int y, int xn, int yn);
bool validMove(int x, int y, int xn, int yn);
bool checkCap(int x, int y, int xn, int yn);
bool getWon();
string getSpot(int x, int y);
void MakeKing(int x);
bool getCheckState(int x, int y);
};
#endif