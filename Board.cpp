#include <iostream>
#include "Board.h"
using namespace std;

Board::Board(){
player = true;
won = false;
x_count=12;
o_count=12;
for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        if(i<=2&&(j+i)%2!=0){
           
                game_board[i][j]="|x|";
                }else if(i>=5&&(j+i)%2!=0){
                game_board[i][j]="|o|";
            
        }else{
        game_board[i][j]="|_|";
        }
    }
}
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
if(player&&game_board[x][y]==("|x|")){
    if(checkCap(x,y,xn,yn)){
        o_count--;
    }
       game_board[x][y]="|_|";
       game_board[xn][yn]="|x|";
       player=!player;
       return true;
}else if((!player)&&game_board[x][y]==("|o|")){
    if(checkCap(x,y,xn,yn)){
        x_count--;
    }
       game_board[x][y]="|_|";
       game_board[xn][yn]="|o|";
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
if(player&&game_board[xn][yn]=="|x|"){
    return false;
}else if(!player&&game_board[xn][yn]=="|o|"){
    return false;
}

    return true;
}

//checks captures
bool Board::checkCap(int x, int y, int xn, int yn){
    if((player&&game_board[xn][yn]=="|o|")||(!player&&game_board[xn][yn]=="|x|")){
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
