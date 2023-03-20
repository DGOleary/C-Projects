#include <iostream>
#include <string>
#include "Board.h"
#include "Checker.h"

using namespace std;

bool moveCheck(string m, char *c, int *i);

bool spotMove(string temp);

bool kingMove(string temp);

bool possibleMoves(int x, int y);

    Board board;
    char col;
    int row;
    char n_col;
    int n_row;
int main(){
    
    cout << "Word your moves as Letter, then Number of the spot, Example: A1\n\n";
    while(!board.getWon()){
        string move;
        board.printBoard();
        cout << "Current Player: ";
        if(board.getPlayer()){
            cout << "X's\n";
        }else{
            cout << "O's\n";
        }
         cout << "Select piece to move: ";
         cin >> move;
         cout << "\n";
         bool king=false;
        while(!moveCheck(move, &col, &row)){
            //add check to see if the piece has possible moves
            cout << "Select piece to move: ";
            cin >> move;
            cout << "\n";
        }
        if(board.getCheckKing(row-1, (int)col-65)){
            king=true;
        }
        
  
        bool run = false;
while(!run){
    if(!king){
            while(!spotMove(move)){
            cout << "Select spot to move to, r or l: ";
            cin >> move;
            cout << move << " \n";
        }
        if(board.getPlayer()){
        if(move=="r"){
            //-65 accounts for ascii value of letters to turn them into numbers
            if(board.validMove(row-1, (int)col-65, row, ((int)col+1)-65)){
                run = board.makeMove(row-1, (int)col-65, row, ((int)col+1)-65);
            }else{
                //alternate moves move one over in each direction its going in an attempt to capture
                run = board.makeMove(row-1, (int)col-65, row+1, ((int)col+2)-65);
            }
            
        }else{
            if(board.validMove(row-1, (int)col-65, row, ((int)col-1)-65)){
                run = board.makeMove(row-1, (int)col-65, row, ((int)col-1)-65);
            }else{
                run = board.makeMove(row-1, (int)col-65, row+1, ((int)col-2)-65);
            }
        }
        }else{
        if(move=="r"){
            if(board.validMove(row-1, (int)col-65, row-2, ((int)col+1)-65)){
                run = board.makeMove(row-1, (int)col-65, row-2, ((int)col+1)-65);
            }else{
                run = board.makeMove(row-1, (int)col-65, row-3, ((int)col+2)-65);
            }
        }else{
            if(board.validMove(row-1, (int)col-65, row-2, ((int)col-1)-65)){
                run = board.makeMove(row-1, (int)col-65, row-2, ((int)col-1)-65);
            }else{
                run = board.makeMove(row-1, (int)col-65, row-3, ((int)col-2)-65);
            }
        }
        }
        //move="";
        
    }else{
        //section for king moves which can go in any direction
        while(!kingMove(move)){
            cout << "Select direction to move to, u or d: ";
            cin >> move;
            cout << move << " \n";
        }
        string vert_move=move;
        while(!spotMove(move)){
            cout << "Select spot to move to, r or l: ";
            cin >> move;
            cout << move << " \n";
        }
        //whether going up or down
            int vert_amt=0;
            if(vert_move=="u"){
                vert_amt=-1;
            }else{
                vert_amt=1;
            }
            //move right, adds the vertical direction to the move
        if(move=="r"){
            //-65 accounts for ascii value of letters to turn them into numbers
            if(board.validMove(row-1, (int)col-65, (row-1)+vert_amt, ((int)col+1)-65)){
                //cout << row-1  << " " <<(int)col-65 << "\n wrong \n";
                run = board.makeMove(row-1, (int)col-65, (row-1)+vert_amt, ((int)col+1)-65);
            }else{
                run = board.makeMove(row-1, (int)col-65, (row-1)+(2*vert_amt), ((int)col+2)-65);
            }
            //move left
        }else{
            if(board.validMove(row-1, (int)col-65, (row-1)+vert_amt, ((int)col-1)-65)){
                run = board.makeMove(row-1, (int)col-65, (row-1)+vert_amt, ((int)col-1)-65);
            }else{
                run = board.makeMove(row-1, (int)col-65, (row-1)+(2*vert_amt), ((int)col-2)-65);
            }
        }
        //move="";
}
//cout << "end reached \n";
move="";
}
    }
    cout << board.getWinner() << " wins!\n";
return 0;
}

//todo: make sure piece has a valid possible move
bool moveCheck(std::string m, char *c, int *i){
    if(m.length()!=2){
            cout << "Incorrect move, Word your moves as Letter, then Number of the spot, Example: A1\n";
            board.printBoard();
            return false;
        }
        *c = m[0];
        if(*c<65||*c>72){
            cout << "Incorrect move, Column must be between A and H\n";
            board.printBoard();
            return false;
        }
        *i = atoi(&m[1]);
        if(*i<1||*i>8){
            cout << "Incorrect move, Row must be between 1 and 8\n";
            board.printBoard();
            return false;
        }
        if(board.getPlayer()){
            if(board.getSpot(row-1,(int)col-65)=="|o|"||board.getSpot(row-1,(int)col-65)=="|O|"){
                cout << "Incorrect move, you are playing as \"X\"\n";
                board.printBoard();
                return false;
            }
        }else{
                if(board.getSpot(row-1,(int)col-65)=="|x|"||board.getSpot(row-1,(int)col-65)=="|X|"){
                cout << "Incorrect move, you are playing as \"o\"\n";
                board.printBoard();
                return false;
            }
        }
        if(board.getSpot(row-1,(int)col-65)=="|_|"){
                cout << "Incorrect move, no piece is in that spot\n";
                board.printBoard();
                return false;
        }

        if(!possibleMoves(row-1,(int)col-65)&&!board.possibleCap(row-1,(int)col-65)){
                cout << "Incorrect move, no possible moves at that spot\n";
                board.printBoard();
                return false;
        }
        return true;
}

//test loops while making move
bool spotMove(string temp){
if(temp=="l"||temp=="r"){
return true;
}
return false;
}

bool kingMove(string temp){
if(temp=="u"||temp=="d"){
return true;
}
return false;
}

bool possibleMoves(int x, int y){
if(board.getPlayer()||board.getCheckKing(x,y)){
    try{
        if(board.validMove(x,y,x+1,y+1)){
            return true;
        }
        }catch (...){
    }
    try{
        if(board.validMove(x,y,x+1,y-1)){
            return true;
        }
    }catch (...){
    }
}
if(!board.getPlayer()||board.getCheckKing(x,y)){
    try{
        if(board.validMove(x,y,x-1,y+1)){
            return true;
        }
        }catch (...){
    }
    try{
        if(board.validMove(x,y,x-1,y-1)){
            return true;
        }
    }catch (...){
    }
}
return false;
}
