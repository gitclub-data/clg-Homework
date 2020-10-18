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
void merge(struct node *,struct node *,struct node **);
void main()
{
int i,num,loc,j;
struct node *root,*root1,*root2;
root=NULL;
root1=NULL;
root2=NULL;
while(j!=4)
{
printf("\n please enter 1 for linked list 1 \n");
printf("please enter 2 for linked list 2 \n");
printf("please enter 3 to merge 1 and 2 list \n");
printf("please enter 4 for exit \n");
printf("please enter 5 to display merged linked list");
scanf("%d",&j);
switch(j)
{
case 1:
i=0;
while(i!=3)
{
display(root);
printf("\n please enter 1 to create element for first link list");
printf("\n please enter 2 to insert element at last first link list");
printf("\n enter 3 to do operation in other linked list");
scanf("\n %d",&i);
if(i<1||i>3)
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
}
}
}
break;
case 2:
i=0;
while(i!=3)
{
display(root1);
printf("\n please enter 1 to create element in second list");
printf("\n please enter 2 to insert element at last in second list");
printf("\n enter 3 to do operation in other linked list");
scanf("\n %d",&i);
if(i<1||i>3)
{
printf("please enter the valid options");
}
else
{
switch(i){
case 1:
if(root1==NULL)
{
printf("please enter the data");
scanf("\n %d",&num);
create(&root1,num);
}
else
{
printf("linked list is already created");
}
break;
case 2:
if(root1!=NULL)
{
printf("please enter the data");
scanf("\n %d",&num);
insertlast(root1,num);
}
else
{
printf("please create your linked list first");
}
break;
}
}
}
break;
case 3:
merge(root,root1,&root2);
break;
case 4:
exit(1);
break;
case 5:
display(root2);
break;
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
void merge(struct node *q,struct node *q1,struct node **q2)
{     struct node *temp;
	*q2=q;
	temp=*q2;
	while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=q1;
}