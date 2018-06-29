#ifndef A_H
#define A_H
#include"heroes.h"
#include"fight.cpp"
using namespace std;

void Heroinfor(int i1, int j1)
{
	if (i1 == 0) hero1[0]=new liubang(3,5) ;
	else if (i1 == 1) hero1[0] = new houyi(3,5);
	else if (i1 == 2)hero1[0] = new xiaoqiao(3,5);
	else if (i1 == 3)hero1[0] = new lianpo(3,5);
	else if (i1 == 4) hero1[0] = new sunshangxiang(3,5);
	else if (i1 == 5)hero1[0] = new sunwukong(3,5);
	if (j1 == 0) hero1[1] = new liubang(55,5);
	else if (j1 == 1) hero1[1] = new houyi(55,5);
	else if (j1 == 2)hero1[1] = new xiaoqiao(55,5);
	else if (j1 == 3)hero1[1] = new lianpo(55,5);
	else if (j1 == 4) hero1[1] = new sunshangxiang(55,5);
	else if (j1 == 5)hero1[1] = new sunwukong(55,5);
	hero1[0]->x=1; hero1[0]->y=5;
	hero1[0]->anm=hero1[1];
	hero1[1]->anm=hero1[0];
	hero1[1]->x=26 ; hero1[1]->y=5;
	system("cls");
}
#endif
