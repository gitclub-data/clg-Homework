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
void insertlast(struct node *,int);
void display(struct node *);
void reverse(struct node **);
void main()
{
int i,num,loc;
struct node *root,*root1;
root=NULL;
root1=NULL;
while(i!=8)
{
display(root);
printf("\n please enter 1 to create element");
printf("\n please enter 2 to insert element at last");
printf("\n please enter 4 to reverse");
printf("\n please enter 3 to exit");
scanf("\n %d",&i);
if(i<1||i>5)
{
printf("please enter the valid options");
}
else
{
switch(i){
case 1:
if(root==NULL)
{
printf("please enter the data");
scanf("\n %d",&num);
create(&root,num);
}
else
{
printf("linked list is already created");
}
break;
case 2:
if(root!=NULL)
{
printf("please enter the data");
scanf("\n %d",&num);
insertlast(root,num);
}
else
{
printf("please create your linked list first");
}
break;
case 3:
exit(1);
break;
case 4:
reverse(&root);
break;
case 5:
display(root1);
}
}
}
}

void create(struct node **q,int num)
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=num;
temp->next=NULL;
*q=temp;
}

void insertlast(struct node *q,int num)
{
struct node *abc,*temp;
temp=q;
while(temp->next!=NULL)
{
temp=temp->next;
}
abc=(struct node*)malloc(sizeof(struct node));
abc->data=num;
abc->next=NULL;
temp->next=abc;
}
void display(struct node *q)
{
while(q!=NULL)
{
printf("data %d memory %d \t",q->data,q->next);
q=q->next;
}
}

void reverse(struct node **q)
{
struct node *temp,*start, *end;
temp=*q;
start=NULL;
while(temp!=NULL)
{
	end=temp->next;
	temp->next=start;
	start=temp;
	temp=end;
}
*q=start;
}