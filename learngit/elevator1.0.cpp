#include<stdio.h>
#include<math.h> 
int main ()
{
	struct elevator
	{
		int time;
		int start;
		int end;
	}ele[5],temp;//构造对应的结构体存储数据 
	int i,j,sum=0,t=0;
	for(i=0;i<5;i++)
	{
		scanf("%d %d %d",&ele[i].time,&ele[i].start,&ele[i].end);
		if(ele[i].end==0)
			ele[i].end=10;
	}//输入数据并将0转化为10方便计算 
	for(i=0;i<5;i++)
	 	for(j=0;j<4-i;j++)
	 	{
	 		if(ele[j].time>ele[j+1].time)
	 		{
	 			temp=ele[j];
	 			ele[j]=ele[j+1];
	 			ele[j+1]=temp;
			 }
		 }//利用冒泡法从小到大排序 
	for(i=0;i<5;i++)
	{
		if(i==0)
		{
			t=ele[i].time;
			t+=fabs(ele[i].start-1)+1+fabs(ele[i].end-ele[i].start);  
		}//计算第一趟所用时间 
		else
		{
			if(ele[i].time-t-fabs(ele[i].start-ele[i-1].end)>0)
				t+=ele[i].time-t-fabs(ele[i].start-ele[i-1].end);//判断电梯是否需要停止一段时间等待下一次命令发出 
			t+=fabs(ele[i].start-ele[i-1].end)+1+fabs(ele[i].end-ele[i].start);
		}//计算后四趟所用时间 
		sum+=t-ele[i].time;
		printf("%d时，停靠在%d楼\n",t,ele[i].end);	
		 }	 
	printf("%d",sum);
	return 0;
 } 
