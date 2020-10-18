#include<stdio.h>
#include<conio.h>
#define max 5
struct queue
{
	arr[max];
	front;
	rear;
};
void add(struct queue *,int);
void del(struct queue *);
void display(struct queue);
void main()
{
	struct queue q;
	int m,i,num;
	q.front=-1;
	q.rear=-1;
	while(i!=3)
	{
		display(q);
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
			add(&q,num);
			break;
			case 2:
			del(&q);
			break;
			case 3:
			exit(1);
			break;
		}
	}
}

void add(struct queue *q,int num)
{
if(q->rear==max-1)
{
printf("your queue is full");
}
else
{
	if(q->front==-1&&q->rear==-1)
	{
		q->front=0;
		q->rear=0;
	}
	else
	{
		q->rear++;
	}
	q->arr[q->rear]=num;
}
}

void del(struct queue *q)
{
	int item;
	if(q->front==-1||q->front>q->rear)
	{
		printf("underflow");
	}
	else
	{
		item=q->arr[q->front];
		if(q->front==q->rear)
		{
			q->front=-1;
			q->rear=-1;
		}
		else
		{
		q->front++;
		}
		printf("%d deleted",item);
	}
}
void display(struct queue q)
{
	int i;
	if(q.rear==-1)
	{
		printf("queue is empty");
	}
	else{
	for(i=q.front;i<=q.rear;i++)
	{
		printf("%d \t",q.arr[i]);
	}
	}
}