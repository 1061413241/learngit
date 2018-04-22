#include "stdafx.h"
#include "Elevator.h"
#include<iostream>
#include<math.h>
int Elevator::gotofloor(int a, int b)
{
	a = abs(a - b);
	return a;
}//前往请求楼层耗时
int Elevator::wait(int time, int asktime)
{
	if (asktime > time)
	{
		time = asktime - time;
		return time;
	}
	else
		return 0;
	}//等待下一次请求耗时
int Elevator::finish(int fromfloor, int tofloor)
{
	fromfloor = abs(tofloor - fromfloor);
	return fromfloor;
}//前往目的楼层耗时
Elevator::Elevator()
{
}


Elevator::~Elevator()
{
}
