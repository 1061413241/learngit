#include"stdafx.h"
#include<iostream>
#include"elevator.h"
#include<fstream>
using namespace std;
int main()
{
	if (argc == 2)
	{
		ifstream infile(argv[1]);
		ofstream outfile1("./output1.txt");
		ofstream outfile2("./output2.txt");
		ofstream outfile3("./output3.txt");
	}
	else
	{
		ifstream infile(argv[1]);
		ofstream outfile1(argv[2]);
		ofstream outfile2(argv[3]);
		ofstream outfile3(argv[4]);
	}
	/*ifstream infile("./input.txt");
	ofstream outfile1("./output1.txt",ios::app);
	ofstream outfile2("./output2.txt",ios::app);
	ofstream outfile3("./output3.txt",ios::app);*/ 
	passenger pas[502];//����passenger�����
	int n, i;
	infile >> n;//�ļ�����n
	for (i = 0;i < n;i++)
	{
		infile >> pas[i].asktime;
		infile >> pas[i].fromfloor;
		infile >> pas[i].tofloor;
	}//�ļ�����nλ�˿͵���������
	infile.close();
	elevator oddele;//�����������
	elevator allele;//���ܵ�����
	elevator evenele;//ż���������
	for (i = 0;i < n;i++)
	{
		if (pas[i].fromfloor % 2 != 0)//�������������
		{
			if (oddele.floor != pas[i].fromfloor)
			{
				oddele.time += oddele.wait_time(oddele.time, pas[i].asktime) + oddele.gotofloor_time(oddele.floor, pas[i].fromfloor);
				outfile1 << oddele.time << " " << pas[i].fromfloor << endl;
				oddele.time += 1 + oddele.finish_time(pas[i].fromfloor, pas[i].tofloor);
				outfile1 << oddele.time << " " << pas[i].tofloor << endl;
				oddele.floor = pas[i].tofloor;
				oddele.time += 1;
			}//����λ����˿�λ�ò���ͬ
			else
			{
				oddele.time += oddele.finish_time(pas[i].fromfloor, pas[i].tofloor);
				outfile1 << oddele.time << " " << pas[i].tofloor << endl;
				oddele.time += 1;
				oddele.floor = pas[i].tofloor;
			}//����λ����˿�λ����ͬ
		}
		else//ż�����������
		{
			if (evenele.floor != pas[i].fromfloor)
			{
				evenele.time += evenele.wait_time(evenele.time, pas[i].asktime) + evenele.gotofloor_time(evenele.floor, pas[i].fromfloor);
				outfile3 << evenele.time << " " << pas[i].fromfloor << endl;
				evenele.time += 1 + evenele.finish_time(pas[i].fromfloor, pas[i].tofloor);
				outfile3 << evenele.time << " " << pas[i].tofloor << endl;
				evenele.floor = pas[i].tofloor;
				evenele.time += 1;
			}//����λ����˿�λ�ò���ͬ
			else
			{
				evenele.time += evenele.finish_time(pas[i].fromfloor, pas[i].tofloor);
				outfile3 << evenele.time << " " << pas[i].tofloor << endl;
				evenele.time += 1;
				evenele.floor = pas[i].tofloor;
			}//����λ����˿�λ����ͬ
		}
	}
	outfile1.close();
	outfile2.close();
	outfile3.close();
	return 0;
}
