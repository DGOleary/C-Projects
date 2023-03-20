#include <iostream>
#include "Board.h"
#include "Checker.h"
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
// //capping test pieces
//         piece_board[3][2]=Checker(true, 3, 2);
//         game_board[3][2]=piece_board[3][2].getLabel();
//         piece_board[4][3]=Checker(false, 4, 3);
//         game_board[4][3]=piece_board[4][3].getLabel();
//         piece_board[5][4]=Checker();
//         game_board[5][4]=piece_board[5][4].getLabel();

//         // piece_board[7][6]=Checker(true, 3, 2);
//         // game_board[7][6]=piece_board[3][2].getLabel();
//         piece_board[6][5]=Checker(false, 4, 3);
//         game_board[6][5]=piece_board[6][5].getLabel();
// //capping test pieces end
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
    bool cap=false;
    if(checkCap(x,y,xn,yn)){
        if(!player){
            x_count--;
        }else{
            o_count--;
        }
        checkWin();
        //removes piece from board when it is captured
        piece_board[min(x,xn)+1][min(y,yn)+1]=Checker();
        game_board[min(x,xn)+1][min(y,yn)+1]=piece_board[min(x,xn)+1][min(y,yn)+1].getLabel();
    }else if(possibleCap(x,y)){
        cout << "If there is a piece you can capture you must capture it\n";
        printBoard();
        return false;
    }
       //sets old spot to an empty object and puts the checker in the new spot
       piece_board[xn][yn]=piece_board[x][y];
       piece_board[xn][yn].setPos(xn,yn);
       piece_board[x][y]=Checker();
       checkKing(xn,yn);
       game_board[x][y]=piece_board[x][y].getLabel();
       game_board[xn][yn]=piece_board[xn][yn].getLabel();
       if(possibleCap(xn,yn)){
       multiCap(xn,yn);
       }else{
        player=!player;
       return true; 
       }
       return true;
}
cout << "Illegal Move\n";
return false;
}

bool Board::validMove(int x, int y, int xn, int yn){
    //checks for out of bounds
if(x<0||x>7||y<0||y>7||xn<0||xn>7||yn<0||yn>7){
        return false;
    }
    //checks for moving onto a piece
if(piece_board[xn][yn].getTeam()!='n'){
    return false;
}

    return true;
}

//checks captures
bool Board::checkCap(int x, int y, int xn, int yn){
    //checks if the enemy piece is in diagonally in between the player and an empty spot
    if((player&&piece_board[min(x,xn)+1][min(y,yn)+1].getTeam()=='o'&&piece_board[xn][yn].getTeam()=='n')
    ||(!player&&piece_board[min(x,xn)+1][min(y,yn)+1].getTeam()=='x'&&piece_board[xn][yn].getTeam()=='n')){
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

bool Board::getCheckKing(int x, int y){
    return piece_board[x][y].getKing();
}

void Board::checkWin(){
if(o_count==0||x_count==0){
    won=true;
}
}


string Board::getWinner(){
    if(won){
        if(x_count>o_count){
            return "X";
        }else{
            return "O";
        }
    }
    return "";
}

//checks if there is a possible capture to make and forces the player to make it if so
//takes in the location of the piece to be moved
bool Board::possibleCap(int x, int y){
if(player||getCheckKing(x,y)){
    try{
        //this if statement works because if it tries to get the team bool of an 
        //empty spot it throws an exception and breaks out of the statement
        if(piece_board[x+1][y+1].getTeamBool()!=player){
            if((x+2)<8&&(y+2)<8&&piece_board[x+2][y+2].getLabel()=="|_|"){
                return true;
            }
        }
        }catch (...){
    }
    try{
        if(piece_board[x+1][y-1].getTeamBool()!=player){
            if((x+2)<8&&(y-2)>-1&&piece_board[x+2][y-2].getLabel()=="|_|"){
                return true;
            }
        }
    }catch (...){
    }
}
if(!player||getCheckKing(x,y)){
    try{
        if(piece_board[x-1][y+1].getTeamBool()!=player){
            if((x-2)>-1&&(y+2)<8&&piece_board[x-2][y+2].getLabel()=="|_|"){
                return true;
            }
        }
        }catch (...){
    }
    try{
        if(piece_board[x-1][y-1].getTeamBool()!=player){
            if((x-2)>-1&&(y-2)>-1&&piece_board[x-2][y-2].getLabel()=="|_|"){
                return true;
            }
        }
    }catch (...){
    }
}
return false;
}

//caps another piece if there are multiple in a row
void Board::multiCap(int x, int y){
if(player||getCheckKing(x,y)){
    try{
        //this if statement works because if it tries to get the team bool of an 
        //empty spot it throws an exception and breaks out of the statement
        if(piece_board[x+1][y+1].getTeamBool()!=player){
            if((x+2)<8&&(y+2)<8&&piece_board[x+2][y+2].getLabel()=="|_|"){
                cout << "Multi-Capture! \n";
                makeMove(x, y, x+2, y+2);
            }
        }
        }catch (...){
    }
    try{
        if(piece_board[x+1][y-1].getTeamBool()!=player){
            if((x+2)<8&&(y-2)>-1&&piece_board[x+2][y-2].getLabel()=="|_|"){
                cout << "Multi-Capture! \n";
                makeMove(x, y, x+2, y-2);
            }
        }
    }catch (...){
    }
}
if(!player||getCheckKing(x,y)){
    try{
        if(piece_board[x-1][y+1].getTeamBool()!=player){
            if((x-2)>-1&&(y+2)<8&&piece_board[x-2][y+2].getLabel()=="|_|"){
                cout << "Multi-Capture! \n";
                makeMove(x, y, x-2, y+2);
            }
        }
        }catch (...){
    }
    try{
        if(piece_board[x-1][y-1].getTeamBool()!=player){
            if((x-2)>-1&&(y-2)>-1&&piece_board[x-2][y-2].getLabel()=="|_|"){
                cout << "Multi-Capture! \n";
                makeMove(x, y, x-2, y-2);
            }
        }
    }catch (...){
    }
}
}