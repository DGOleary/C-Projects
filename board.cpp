#include <iostream>
using namespace std;

class board{
private:
string game_board[8][8];
bool player;
bool won;

public:
board(){
player = true;
won = false;
for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        if(i<=2&&(j+i)%2!=0){
           
                game_board[i][j]="|X|";
                }else if(i>=5&&(j+i)%2!=0){
                game_board[i][j]="|O|";
            
        }else{
        game_board[i][j]="|_|";
        }
    }
}
}

void printBoard(){
for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        cout << game_board[i][j];
    }
    cout << "\n";
}
}

void makeMove(int x, int y, int xn, int yn){
if(player&&game_board[x][y]==("|X|")){
    if(x!=xn&&y!=yn){
       game_board[x][y]="|_|";
       game_board[xn][yn]="|X|";
       player=!player;
       return;
    }
}else if(!player&&game_board[x][y]==("|O|")){
    if(x!=xn&&y!=yn){
       game_board[x][y]="|_|";
       game_board[xn][yn]="|O|";
       player=!player;
       return;
    }
}
cout << "Illegal Move\n";
}

bool getWon(){
    return won;
}
};
