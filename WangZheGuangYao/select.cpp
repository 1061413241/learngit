#include<cstdlib>
#include"select.h"
#include <iostream>
#include<windows.h>
#include"heroes.h"
#include<conio.h>
char hero[6][10] = { "����","����","С��","����","������","�����" };
char a1 = '*';
using namespace std;
char screen[1000];
char *p = screen;
void Heroinfor(int i1, int j1); 
void Initialscreen()
{
	system("mode con cols=120 lines=30");
	system("color 0c");
}
inline void Set_mouse(int x, int y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x; pos.Y = y;
	SetConsoleCursorPosition(h, pos);
}

void Hide_mouse()				//��ͼ���ع�� 
{
	CONSOLE_CURSOR_INFO mouse = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &mouse);
}

void select_hero()
{
	Initialscreen();
	Set_mouse(55, 0);
	cout << "���߹�ҫ"<<endl;
	Set_mouse(0, 1);
	cout << "���� Enter ��ȷ��Ӣ��";
	for (int i = 0; i < 6; i++)
	{
		Set_mouse(0, i + 2);
		cout << hero[i];
		Set_mouse(106, i + 2);
		cout << hero[i] << endl;
	}
	Hide_mouse();
	int i = 0, j = 0;
	char temp;
	while (1)
	{
		temp = _getch();
		switch (temp)
		{
		case 'w':i--; break;
		case 's':i++; break;
		case 'H':j--; break;// ��
		case 'P':j++; break;            // ��
		case 13:Heroinfor(i, j); return;
		}
		i = (i + 6) % 6; j = (j + 6) % 6;
		for (int k=0; k < 6; k++)
		{
			Set_mouse(8, k + 2);
			if (k == i)
				cout << a1;
			else
				cout << " ";
			Set_mouse(104, k + 2);
			if (k == j)
			cout << a1;
			else cout << " ";
		}
	}
}


