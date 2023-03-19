#include <iostream>
#include "Board.h"
#include "Checker.cpp"
using namespace std;

//player true is x and false is o
Board::Board(){
player = true;
won = false;
x_count=12;
o_count=12;
for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        if(i<=2&&(j+i)%2!=0){
                piece_board[i][j]=Checker(true, i, j);
                }else if(i>=5&&(j+i)%2!=0){
                piece_board[i][j]=Checker(false, i, j);
            
        }else{
        piece_board[i][j]=Checker();
        }
        game_board[i][j]=piece_board[i][j].getLabel();
    }
}
//capping test pieces
        piece_board[3][2]=Checker(true, 3, 2);
        game_board[3][2]=piece_board[3][2].getLabel();
        piece_board[4][3]=Checker(false, 4, 3);
        game_board[4][3]=piece_board[4][3].getLabel();
//capping test pieces end
}

bool Board::getPlayer(){
    return player;
}

void Board::printBoard(){
    cout << "  A  B  C  D  E  F  G  H \n";
for(int i=0;i<8;i++){
    cout << i+1;
    for(int j=0;j<8;j++){
        cout << game_board[i][j];
    }
    cout << "\n";
}
}

bool Board::makeMove(int x, int y, int xn, int yn){
     //cout << x << " " << y << " " << xn << " " << yn << "\n"; 
if(validMove(x,y,xn,yn)){
    //checks to make sure youre moving your own piece
if((player&&piece_board[x][y].getTeam()=='x')||(!player&&piece_board[x][y].getTeam()=='o')){
    if(checkCap(x,y,xn,yn)){
        if(player){
            x_count--;
        }else{
            o_count--;
        }
        checkWin();
        //removes piece from board when it is captured
        piece_board[xn][yn]=Checker();
    }
       //sets old spot to an empty object and puts the checker in the new spot
       piece_board[xn][yn]=piece_board[x][y];
       piece_board[xn][yn].setPos(xn,yn);
       piece_board[x][y]=Checker();
       checkKing(xn,yn);
       game_board[x][y]=piece_board[x][y].getLabel();
       game_board[xn][yn]=piece_board[xn][yn].getLabel();
       player=!player;
       return true;
}
}
cout << "Illegal Move\n";
return false;
}

bool Board::validMove(int x, int y, int xn, int yn){
    //checks for out of bounds
if(x<0||x>7||y<0||y>7||xn<0||xn>7||yn<0||yn>7){
        return false;
    }
    //checks for moving onto a piece on your own team
if(player&&piece_board[xn][yn].getTeam()=='x'){
    return false;
}else if(!player&&piece_board[xn][yn].getTeam()=='o'){
    return false;
}

    return true;
}

//checks captures
bool Board::checkCap(int x, int y, int xn, int yn){
    if((player&&piece_board[xn][yn].getTeam()=='o')||(!player&&piece_board[xn][yn].getTeam()=='x')){
        return true;
    }
    return false;
}

bool Board::getWon(){
    return won;
}

string Board::getSpot(int x, int y){
    return game_board[x][y];
}

void Board::checkKing(int x, int y){
    if(player&&x==7){
        piece_board[x][y].makeKing();
    }else if(!player&&x==0){
        piece_board[x][y].makeKing();
    }
}

bool Board::getCheckState(int x, int y){
    return piece_board[x][y].getState();
}

void Board::checkWin(){

}