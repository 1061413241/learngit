#pragma once
class Elevator
{
public:
	int floor = 0;
	int gotofloor(int a, int b);//前往出发点耗时
	int wait(int time, int asktime);//等待请求时间
	int finish(int fromfloor, int tofloor);//前往目的楼层耗时

	Elevator();
	~Elevator();
};

