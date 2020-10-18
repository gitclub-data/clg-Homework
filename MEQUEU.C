#include<stdio.h>
#include<conio.h>
#define max 5
struct queue
{
int arr[max];
int front;
int rear;
};

void main()
{
struct queue q;
int i,item,num,j;
q.front=-1;
q.rear=-1;
while(i!=3)
{
		if(q.rear==-1)
		{
	      printf("queue is empty");
		}
		else
		{
	     for(j=q.front;j<=q.rear;j++)
	     {
	      printf("%d \t \n",q.arr[j]);
	     }
	     }
		printf("1:add element in the queue \n");
		printf("2:delete element from the queue \n");
		printf("3:exit \n \n");
		printf("Enter choice");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
			printf("please enter the data");
			scanf("%d",&num);
			if(q.rear==max-1)
			{
			 printf("queue is overlow");
			}
			else
			{
			if(q.front==-1&&q.rear==-1)
			{
			  q.front=0;
			  q.rear=0;
			}
			else
			{
			  q.rear++;
			}
			q.arr[q.rear]=num;
			}
			break;
			case 2:
			if(q.rear==-1||q.front>q.rear)
			{
			 printf("queue is unerflow");
			}
			else
			{
			item=q.arr[q.front];
			if(q.front==q.rear)
			{
			q.front=-1;
			q.rear=-1;
			}
			else
			{
			q.front++;
			}
			printf("%d deleted \n",item);
			}
			break;
			case 3:
			exit(1);
			break;
}
}
}