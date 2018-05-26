#include"stdafx.h"
#include<iostream>
#include "elevator.h"
#include<math.h>

int elevator::gotofloor_time(int fromfloor, int tofloor)
{
	int time = abs(tofloor - fromfloor);
	return time;
}//前往乘客所在位置耗时

int elevator::wait_time(int time, int asktime)
{
	if (asktime > time)
	{
		time = asktime - time;
		return time;
	}
	else
		return 0;
}//等待下一次请求耗时

int elevator::finish_time(int fromfloor, int tofloor)
{
	int time = abs(tofloor - fromfloor);
	return time;
}//前往乘客目的楼层耗时


elevator::elevator()
{
}


elevator::~elevator()
{
}

passenger::passenger()
{

}

passenger::~passenger()
{

}
