#include "Checker.h"
using namespace std;

Checker::Checker(){
x=-1;
y=-1;
king=false;
team='n';
label="|_|";
}

Checker::Checker(bool t, int x, int y){
this->x=x;
this->y=y;
king=false;
if(t){
    team='x';
    label="|x|";
}else{
    team='o';
    label="|o|";
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
    if(team=='x'){
        label="|X|";
    }else{
        label="|O|";
    }
}

char Checker::getTeam(){
    return team;
}

void Checker::setPos(int x, int y){
    this->x=x;
    this->y=y;
}

string Checker::getLabel(){
    return label;
}