#include "Checker.h"
using namespace std;

Checker::Checker(){
x=-1;
y=-1;
king=false;
team='n';
}

Checker::Checker(bool t, int x, int y){
this->x=x;
this->y=y;
king=true;//false;
if(t){
    team='x';
}else{
    team='o';
}

}

bool Checker::getState(){
    return king;
}

int* Checker::getPos(){
    static int temp[]={x,y};
    return temp;
}

void Checker::makeKing(){
    king=true;
}

char Checker::getTeam(){
    return team;
}

void Checker::setPos(int x, int y){
    this->x=x;
    this->y=y;
}