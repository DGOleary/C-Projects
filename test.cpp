#include <iostream>
#include <string>
#include "Board.cpp"

using namespace std;

bool moveCheck(string m, char *c, int *i);

bool spotMove(string temp);

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
        while(!moveCheck(move, &col, &row)){
            cout << "Select piece to move: ";
            cin >> move;
            cout << "\n";
        }

        cout << "Select spot to move to, r or l: ";
        cin >> move;
        cout << "\n";
        
  
        bool run = false;
while(!run){
            while(!spotMove(move)){
            cout << "Select spot to move to, r or l: ";
            cin >> move;
            cout << move << " \n";
        }
        if(board.getPlayer()){
        if(move=="r"){
            run = board.makeMove(row-1, (int)col-65, row, ((int)col+1)-65);
        }else{
            run = board.makeMove(row-1, (int)col-65, row, ((int)col-1)-65);
        }
        }else{
        if(move=="r"){
            run = board.makeMove(row-1, (int)col-65, row-2, ((int)col+1)-65);
        }else{
            run = board.makeMove(row-1, (int)col-65, row-2, ((int)col-1)-65);
        }
        }
        move="";
        } 
}
return 0;
}

//todo: make sure piece has a valid possible move
bool moveCheck(std::string m, char *c, int *i){
    if(m.length()!=2){
            cout << "Incorrect move, Word your moves as Letter, then Number of the spot, Example: A1\n";
            return false;
        }
        *c = m[0];
        if(*c<65||*c>72){
            cout << "Incorrect move, Column must be between A and H\n";
            return false;
        }
        *i = atoi(&m[1]);
        if(*i<1||*i>8){
            cout << "Incorrect move, Row must be between 1 and 8\n";
            return false;
        }
        if(board.getPlayer()){
            if(board.getSpot(row-1,(int)col-65)=="|o|"){
                cout << "Incorrect move, you are playing as \"X\"\n";
                return false;
            }
        }else{
                if(board.getSpot(row-1,(int)col-65)=="|x|"){
                cout << "Incorrect move, you are playing as \"o\"\n";
                return false;
            }
        }
        return true;
}

bool spotMove(string temp){
if(temp=="l"||temp=="r"){
return true;
}
return false;
}