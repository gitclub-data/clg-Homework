#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
void create(struct node **,int);
void insertshort(struct node **,int);
void display(struct node *);
void main()
{
int i,num,loc;
struct node *root;
root=NULL;
while(i!=3)
{
display(root);
printf("\n please enter 1 to insert element in shorted form");
printf("\n please enter 2 to exit");
scanf("\n %d",&i);
if(i<1||i>2)
{
printf("please enter the valid options");
}
else
{
switch(i){
case 1:
printf("please enter the data");
scanf("\n %d",&num);
insertshort(&root,num);
break;
case 2:
exit(1);
break;
}
}
}
}
void insertshort(struct node **q,int num)
{
	struct node *temp,*abc;
	temp=*q;
	abc=(struct node*)malloc(sizeof(struct node));
	abc->data=num;
	if(*q==NULL ||num<temp->data)
	{
		abc->next=temp;
		*q=abc;
	}
	else
	{
		while(temp!=NULL)
		{
			if(temp->data<=num&&(temp->next->data>num||temp->next==NULL))
			{
				abc->next=temp->next;
				temp->next=abc;
				return; 
			}
			temp=temp->next;
		}
	}
}

void display(struct node *q)
{
while(q!=NULL)
{
printf("data %d memory %d \t",q->data,q->next);
q=q->next;
}
}