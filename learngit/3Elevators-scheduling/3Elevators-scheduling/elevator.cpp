#include"stdafx.h"
#include<iostream>
#include "elevator.h"
#include<math.h>

int elevator::gotofloor_time(int fromfloor, int tofloor)
{
	int time = abs(tofloor - fromfloor);
	return time;
}//ǰ���˿�����λ�ú�ʱ

int elevator::wait_time(int time, int asktime)
{
	if (asktime > time)
	{
		time = asktime - time;
		return time;
	}
	else
		return 0;
}//�ȴ���һ�������ʱ

int elevator::finish_time(int fromfloor, int tofloor)
{
	int time = abs(tofloor - fromfloor);
	return time;
}//ǰ���˿�Ŀ��¥���ʱ


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
