#include "stdafx.h"
#include "Elevator.h"
#include<iostream>
#include<math.h>
int Elevator::gotofloor(int a, int b)
{
	a = abs(a - b);
	return a;
}//ǰ������¥���ʱ
int Elevator::wait(int time, int asktime)
{
	if (asktime > time)
	{
		time = asktime - time;
		return time;
	}
	else
		return 0;
	}//�ȴ���һ�������ʱ
int Elevator::finish(int fromfloor, int tofloor)
{
	fromfloor = abs(tofloor - fromfloor);
	return fromfloor;
}//ǰ��Ŀ��¥���ʱ
Elevator::Elevator()
{
}


Elevator::~Elevator()
{
}
