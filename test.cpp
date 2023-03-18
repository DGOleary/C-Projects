#include <iostream>
#include <string>
#include "board.cpp"

using namespace std;

int main(){
    board board;
    board.printBoard();
    board.makeMove(2,1,3,2);
    cout << "\n";
    board.printBoard();
    string t = "123456";
    string s(1,t[0]), a(1,t[1]);
    cout << stoi(s) <<"\n";
    int x = stoi(s)+stoi(a);
    cout << x <<"\n";
    cout << "Word your moves as Letter, then Number of the spot, Example: A1";
    while(!board.getWon()){
        string move;
        cout << "Current Player: ";
        if(board.getWon()){
            cout << "X's\n";
        }else{
            cout << "O's\n";
        }
        cout << "Select piece to move: ";
        cin >> move;
        if(move.length()>2){
            cout << "Incorrect move, Word your moves as Letter, then Number of the spot, Example: A1";
            continue;
        }
        char col = move[0];
        if(col<65||col>72){
            cout << "Incorrect move, Column must be between A and H";
            continue;
        }
        int row = atoi(&move[1]);
        if(row<1||row>8){
            cout << "Incorrect move, Row must be between 1 and 8";
            continue;
        }

   }
}

