#ifndef CHECKER_H
#define CHECKER_H
#include <string>
using namespace std;
class Checker{
private:
bool king;
char team;
int x;
int y;
string label;
public:
//team and position
Checker();
Checker(bool t, int x, int y);
bool getKing();
int* getPos();
void makeKing();
char getTeam();
bool getTeamBool();
void setPos(int x, int y);
string getLabel();
};
#endif