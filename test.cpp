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
    while(!board.getWon()){
        cout << "Current Player: ";
        if(board.getWon()){
            cout << "X's";
        }else{
            cout << "O's";
        }
   }
}

