#ifndef CHECKER_H
#define CHECKER_H
class Checker{
private:
bool king;
char team;
int x;
int y;
public:
//team and position
Checker();
Checker(bool t, int x, int y);
bool getState();
int* getPos();
void makeKing();
char getTeam();
void setPos(int x, int y);
};
#endif