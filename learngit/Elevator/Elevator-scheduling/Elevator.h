#pragma once
class Elevator
{
public:
	int floor = 0;
	int gotofloor(int a, int b);//ǰ���������ʱ
	int wait(int time, int asktime);//�ȴ�����ʱ��
	int finish(int fromfloor, int tofloor);//ǰ��Ŀ��¥���ʱ

	Elevator();
	~Elevator();
};

