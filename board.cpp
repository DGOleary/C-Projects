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

bool getPlayer(){
    return player;
}

void printBoard(){
    cout << "  A  B  C  D  E  F  G  H \n";
for(int i=0;i<8;i++){
    cout << i+1;
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
}else if((!player)&&game_board[x][y]==("|O|")){
    if(x!=xn&&y!=yn){
       game_board[x][y]="|_|";
       game_board[xn][yn]="|O|";
       player=!player;
       return;
    }
}
cout << "Illegal Move\n";
}

bool validMove(int x, int y, int xn, int yn){
if(x<0||x>8||y<0||y>8||xn<0||xn>8||yn>0||yn<8){
        cout << "Illegal Move\n";
        return;
    }
}

bool getWon(){
    return won;
}
};
