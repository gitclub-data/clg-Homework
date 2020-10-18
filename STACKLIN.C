#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
void push(struct node **,int);
void pop(struct node **);
void display(struct node *);
void main()
{
int i,num;
struct node *root;
root=NULL;
while(i!=8)
{
display(root);
printf("\n 1:push element");
printf("\n 2:pop  element");
printf("\n 3:exit \n\n");
scanf("\n %d",&i);
if(i<1||i>3)
{
printf("please enter the valid options");
}
else
{
switch(i){
case 1:
printf("Enter the element");
scanf("%d",&num);
push(&root,num);
break;
case 2:
pop(&root);
break;
case 3:
exit(1);
break;
}
}
}
}

void push(struct node **q,int num)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	if(*q==NULL)
	{
		temp->next=NULL;
		*q=temp;
	}
	else
	{
		temp->next=*q;
		*q=temp;
	}
}

void pop(struct node **q)
{
	struct node *temp;
	if(*q==NULL)
	{
		printf("stack is empty");
	}
	else
	{
		temp=*q;
		*q=temp->next;
		free(temp);
	}
}
void display(struct node *q)
{
	while(q!=NULL)
	{
	 printf("element  %d address %d",q->data,q->next);
	 q=q->next;
	}
}