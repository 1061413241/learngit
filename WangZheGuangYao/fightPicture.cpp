#include<iostream>
#include<windows.h> 
#include"select.h"
#include"heroes.h"
using namespace std;

void draw(heroes *a[])
{
	Set_mouse(0, 0);
	int i,j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 55; j++)
		{
			if ((j == (a[0]->x *2) && i == a[0]->y) || (j == (a[1]->x *2) && i == a[1]->y)) cout << "¡â";
			else if ((i == 4 || i == 5 || i == 6) && (j == 0 || j == 54)) cout << "¨€";
			else if (i == 5 && (j == 6 || j == 48)) cout << "¡ñ";
			else if (i == 5 && (j == 9 || j == 45)) cout << "¨†";
			else cout << "  ";
			
		}
		cout << endl;
	}
	
}



