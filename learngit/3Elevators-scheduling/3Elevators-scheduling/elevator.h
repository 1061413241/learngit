#pragma once
class elevator
{
public:
	elevator();
	~elevator();
	int time = 0;
	int floor = 0;
	int currentfloor;//电梯当前所在楼层
	int state = 0;//电梯运行状态：停止为0，运行中为1
	int gotofloor_time(int fromfloor, int tofloor);//前往乘客所在位置耗时
	int wait_time(int time, int asktime);//等待下一次请求耗时
	int finish_time(int fromfloor, int tofloor);//前往乘客目的楼层耗时

};//电梯类
class passenger
{
public:
	passenger();
	~passenger();
	int asktime;
	int fromfloor;
	int tofloor;
};//乘客类

