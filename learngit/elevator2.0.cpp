#include<stdio.h>
#include<math.h> 
FILE* stream;
FILE* outputfile;
int main ()
{
	struct elevator
	{
		int time;
		int start;
		int end;
	}ele[5],temp;//�����Ӧ�Ľṹ��洢���� 
	int i,j,sum=0,t=0;
	stream=fopen("input.txt","r");
	outputfile=fopen("output.txt","w");
	if(stream==NULL)
	    printf("error");
	else
	{
		for(i=0;i<5;i++)
		{
			fscanf(stream,"%d %d %d",&ele[i].time,&ele[i].start,&ele[i].end);
		}		
	}//�ļ����� 
	for(i=0;i<5;i++)
	 	for(j=0;j<4-i;j++)
	 	{
	 		if(ele[j].time>ele[j+1].time)
	 		{
	 			temp=ele[j];
	 			ele[j]=ele[j+1];
	 			ele[j+1]=temp;
			 }
		 }//����ð�ݷ���С�������� 
	for(i=0;i<5;i++)
	{
		if(i==0)
		{
			t=ele[i].time;
			t+=fabs(ele[i].start-1)+1+fabs(ele[i].end-ele[i].start);  
		}//�����һ������ʱ�� 
		else
		{
			if(ele[i].time-t-fabs(ele[i].start-ele[i-1].end)>0)
				t+=ele[i].time-t-fabs(ele[i].start-ele[i-1].end);//�жϵ����Ƿ���Ҫֹͣһ��ʱ��ȴ���һ������� 
			t+=fabs(ele[i].start-ele[i-1].end)+1+fabs(ele[i].end-ele[i].start);
		}//�������������ʱ�� 
		sum+=t-ele[i].time;
		if(outputfile==NULL)
	    	printf("error");
		else
			fprintf(outputfile,"%dʱ��ͣ����%d¥\n",t,ele[i].end);//�ļ���� 
	 }	 
	if(outputfile==NULL)
	    printf("error");
	else
		fprintf(outputfile,"�ȴ�ʱ���ܺͣ�%d",sum);
	return 0;
 } 
