#include<iostream>
#include<string>
#include<conio.h>
#include"heroes.h"
#include"fightPicture.cpp"
#include"select.cpp"
using namespace std;
turret p1(5,9,"p1");
turret p2(5,45,"p2");
spring s1(5,0);
spring s2(5,54);
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

void move(char a,char b)
{
	if(a)
	hero1[1]->move(a);
	if(b)
	hero1[0]->move(b);
}
void drawinfor()
{
	Set_mouse(10, 10);
	cout<<hero1[0]->name<<" :   ";
	cout<<hero1[0]->HP<<"   ";
	Set_mouse(10, 20);
	cout<<hero1[1]->name<<" :   ";
	cout<<hero1[1]->HP<<"   ";
	Set_mouse(30, 10);
	cout<<p1.name<<" :  ";
	cout<<p1.HP<<"  ";
	Set_mouse(30, 20);
	cout<<p2.name<<" :  ";
	cout<<p2.HP<<"  ";
}
void attack()
{
	if((hero1[0]->x==hero1[1]->x-1)){
			if((hero1[0]->y==hero1[0]->y+1)||(hero1[0]->y==hero1[0]->y)||(hero1[0]->y==hero1[0]->y-1))
			{
				hero1[0]->Attack(*hero1[1]);
				hero1[1]->Attack(*hero1[0]); 
			} 
		}
		else if(hero1[0]->x==hero1[1]->x+1){
				if((hero1[0]->y==hero1[0]->y+1)||(hero1[0]->y==hero1[0]->y)||(hero1[0]->y==hero1[0]->y-1))
			{
				hero1[0]->Attack(*hero1[1]);
				hero1[1]->Attack(*hero1[0]); 
			} 
		}
		p1.attack_action(*hero1[1]);
		p2.attack_action(*hero1[0]);
		s1.recovery(*hero1[1]);
		s2.recovery(*hero1[0]);
}
void input()
{
	char move1=0,move2=0;
	if(kbhit())
	{
		move1=getch();
		if(move1>90)
		{
			move2=move1;
			move1=0;
		}
	}
	move(move1,move2);
}
int main()
{
	select_hero();
	draw(hero1);
	while(1)
	{
		input();
		attack();
		draw(hero1);
		drawinfor();
	}
}
