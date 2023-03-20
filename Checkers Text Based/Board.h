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
void checkWin();
bool checkCap(int x, int y, int xn, int yn);
void checkKing(int x, int y);
public:
Board();
bool validMove(int x, int y, int xn, int yn);
bool getPlayer();
void printBoard();
bool makeMove(int x, int y, int xn, int yn);
bool getWon();
string getSpot(int x, int y);
bool getCheckKing(int x, int y);
string getWinner();
bool possibleCap(int x, int y);
void multiCap(int x, int y);
};
#endif