#include<stdio.h>
#include<conio.h>
#include"Q_functions.h"
int Q1,Q2,Q3;
int roundrobin(int a, int b);
int firstcomefirstserve(int a, int b);
int priority(int a , int b);
int waiting_time[20];
int main()
{
	//int Q1,Q2,Q3;
	printf("\n\t\tEnter number of processes in queue 1\t\t::\t\t");
	scanf("%d",&Q1);
	printf("\n\t\tEnter number of processes in queue 2\t\t::\t\t");
	scanf("%d",&Q2);
	printf("\n\t\tEnter number of processes in queue 3\t\t::\t\t");
	scanf("%d",&Q3);
	int p1,p2,p3;
	
	char name[3];
	printf("\n\t\tEnter priority of queue 1\t\t::\t\t");
	scanf("%d",&p1);
	while(1)
	{
	printf("\n\t\tEnter priority of queue 2\t\t::\t\t");
	scanf("%d",&p2);
	if(p1!=p2)
	{
		break;
	}
	else
	{
		printf("priorities cannot be equal");
	}
	}
	while(1)
	{
	printf("\n\t\tEnter priority of queue 3\t\t::\t\t");
	scanf("%d",&p3);
	if(p1!=p3&&p2!=p3)
	{
		break;
	}
	else
	{
		printf("priorities cannot be equal");
	}
	}
	if (p1<p2&&p1<p3)
	{
		roundrobin(Q1,1);
		if(p2<p3)
		{
			priority(Q2,2);
			firstcomefirstserve(Q3,3);
		}
		else
		{
			priority(Q3,3);
			firstcomefirstserve(Q2,2);
		}
	}
	else if(p2<p1&&p2<p3)
	{
		roundrobin(Q2,2);
		if(p1<p3)
		{
			priority(Q1,1);
			firstcomefirstserve(Q3,3);
		}
		else
		{
			priority(Q3,3);
			firstcomefirstserve(Q1,1);
		}
	}
	else
	{
		roundrobin(Q3,3);
		if(p1<p2)
		{
			priority(Q1,1);
			firstcomefirstserve(Q2,2);
		}
		else
		{
			priority(Q2,2);
			firstcomefirstserve(Q1,1);
		}
	}
}


