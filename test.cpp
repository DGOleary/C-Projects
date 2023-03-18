#include <iostream>
#include <string>
#include "board.cpp"

using namespace std;

bool moveCheck(std::string m){
    if(m.length()>2){
            cout << "Incorrect move, Word your moves as Letter, then Number of the spot, Example: A1\n";
            return false;
        }
        char col = m[0];
        if(col<65||col>72){
            cout << "Incorrect move, Column must be between A and H\n";
            return false;
        }
        int row = atoi(&m[1]);
        if(row<1||row>8){
            cout << "Incorrect move, Row must be between 1 and 8\n";
            return false;
        }
        return false;
}

int main(){
    
    board board;
    board.printBoard();
    board.makeMove(2,1,3,2);
    cout << "\n";
    // board.printBoard();
    // string t = "123456";
    // string s(1,t[0]), a(1,t[1]);
    // cout << stoi(s) <<"\n";
    // int x = stoi(s)+stoi(a);
    // cout << x <<"\n";
    cout << "Word your moves as Letter, then Number of the spot, Example: A1\n";
    while(!board.getWon()){
        string move;
        cout << "Current Player: ";
        if(board.getWon()){
            cout << "X's\n";
        }else{
            cout << "O's\n";
        cout << "Select piece to move: ";
        cin >> move;
        //cin.clear();
        while(!moveCheck(move)){
            cout << "Select piece to move: ";
            cin >> move;
        }

   }
}
return 0;
}


