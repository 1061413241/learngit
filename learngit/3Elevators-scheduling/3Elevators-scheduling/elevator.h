#pragma once
class elevator
{
public:
	elevator();
	~elevator();
	int time = 0;
	int floor = 0;
	int currentfloor;//���ݵ�ǰ����¥��
	int state = 0;//��������״̬��ֹͣΪ0��������Ϊ1
	int gotofloor_time(int fromfloor, int tofloor);//ǰ���˿�����λ�ú�ʱ
	int wait_time(int time, int asktime);//�ȴ���һ�������ʱ
	int finish_time(int fromfloor, int tofloor);//ǰ���˿�Ŀ��¥���ʱ

};//������
class passenger
{
public:
	passenger();
	~passenger();
	int asktime;
	int fromfloor;
	int tofloor;
};//�˿���

