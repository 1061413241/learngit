
#include "stdafx.h"
#include<iostream>
#include<fstream>
#include"Elevator.h"
using namespace std;
class passenger
{
public:
	int asktime;
	int fromfloor;
	int tofloor;
};//乘客类
int time = 0;
int main()
{
	ifstream infile("./input.txt");
	ofstream outfile("./output.txt", ios::app);
	passenger pas[502];
	int n,i;
	infile >> n;//文件读入n
	for (i = 0;i < n;i++)
	{
		infile >> pas[i].asktime;
		infile >> pas[i].fromfloor;
		infile >> pas[i].tofloor;
	}//文件读入n位乘客的请求数据
	infile.close();
	Elevator ele;//电梯对象
	for (i = 0;i < n;i++)
	{
		if (ele.floor != pas[i].fromfloor)
		{
			time += ele.wait(time, pas[i].asktime) + ele.gotofloor(ele.floor, pas[i].fromfloor);
			outfile << time << ' '<< pas[i].fromfloor << endl;
			time += 1 + ele.finish(pas[i].fromfloor, pas[i].tofloor);
			outfile << time << ' '<< pas[i].tofloor << endl;
			ele.floor = pas[i].tofloor;
			time += 1;
		}//电梯位置与乘客位置不相同
		else
		{
			time += ele.finish(pas[i].fromfloor, pas[i].tofloor);
			outfile << time << ' '<< pas[i].tofloor << endl;
			time += 1;
			ele.floor = pas[i].tofloor;
		}//电梯位置与乘客位置相同
	}
	outfile.close();
	return 0;
}

