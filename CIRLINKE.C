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
void insertbeg(struct node **,int);
void insertmid(struct node *,int,int);
void insertlast(struct node *,int);
void delfirst(struct node **);
void delmid(struct node *,int);
void dellast(struct node *);
void display(struct node *);
void main()
{
int i,num,loc;
struct node *root;
root=NULL;
while(i!=8)
{
display(root);
printf("\n please enter 1 to create element");
printf("\n please enter 2 to insert element at begining");
printf("\n please enter 3 to insert element at mid by location");
printf("\n please enter 4 to insert element at last");
printf("\n please enter 5 to delete first element");
printf("\n please enter 6 to delete by entering its data");
printf("\n please enter 7 to delete last element");
printf("\n please enter 8 to exit");
scanf("\n %d",&i);
if(i<1||i>8)
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
insertbeg(&root,num);
}
else
{
printf("please create your linked list first");
}
break;
case 3:
if(root!=NULL)
{
printf("please enter the data");
scanf("\n %d",&num);
printf("please enter the location");
scanf("\n %d",&loc);
insertmid(root,loc,num);
}
else
{
printf("please create your linked list first");
}
break;
case 4:
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
case 5:
if(root!=NULL)
{
delfirst(&root);
}
else
{
printf("please create your linked list first");
}
break;
case 6:
if(root!=NULL)
{
printf("please enter the data to delete");
scanf("\n %d",&num);
delmid(root,num);
}
else
{
printf("please create your linked list first");
}
break;
case 7:
if(root!=NULL)
{
dellast(root);
}
else
{
printf("please create your linked list first");
}
break;
case 8:
exit(1);
break;
}
}
}
}

void create(struct node **q,int num)
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=num;
*q=temp;
temp->next=*q;
}

void insertbeg(struct node **q,int num)
{
struct node *temp,*abc;
abc=*q;
while(abc->next!=*q)
{
abc=abc->next;
}
temp=(struct node*)malloc(sizeof(struct node));
temp->data=num;
temp->next=*q;
*q=temp;
abc->next=*q;
}

void insertmid(struct node *q,int loca,int num)
{
struct node *abc,*temp;
int i;
temp=q;
for(i=1;i<loca;i++)
{
temp=temp->next;
}
if(temp!=NULL)
{
abc=(struct node*)malloc(sizeof(struct node));
abc->data=num;
abc->next=temp->next;
temp->next=abc;
}
else
{
printf("%d location does not exits in your link list",loca);
}
}

void insertlast(struct node *q,int num)
{
struct node *abc,*temp;
temp=q;
while(temp->next!=q)
{
temp=temp->next;
}
abc=(struct node*)malloc(sizeof(struct node));
abc->data=num;
abc->next=temp->next;
temp->next=abc;
}

void delfirst(struct node **q)
{
struct node *temp,*abc;
abc=*q;
temp=*q;
while(abc->next!=*q)
{
abc=abc->next;
}
*q=temp->next;
free(temp);
abc->next=*q;
}

void delmid(struct node *q,int num)
{
struct node *temp,*r;
temp=q;
while(temp->next->data!=num)
{
if(temp->next==q)
{
	break;
}
temp=temp->next;
}
if(temp->next==q)
{
	printf("The given data is not found in the list");
}
else
{
r=temp->next;
temp->next=r->next;
free(r);
}
}
void dellast(struct node *q)
{
struct node *temp;
temp=q;
while(temp->next->next!=q)
{
temp=temp->next;
}
free(temp->next);
temp->next=q;
}

void display(struct node *q)
{
	struct node *temp;
	temp=q;
while(q->next!=temp)
{
printf("data %d memory %d \t",q->data,q->next);
q=q->next;
}
printf("data %d memory %d \t",q->data,q->next);
}