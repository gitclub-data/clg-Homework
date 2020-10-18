#include<stdio.h>
#include<conio.h>

struct node{
	struct node *pre;
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
	int i,num,data;
	struct node *root;
	root=NULL;
	while(i!=8)
	{
	display(root);
	printf("1:create the linked list \n");
	printf("2:insert node at first \n");
	printf("3:insert node at the mid by data \n");
	printf("4:insert node at the last \n");
	printf("5:delete first element \n");
	printf("6:delete node by data \n");
	printf("7:delete node at last \n");
	printf("8:exit from console \n \n");
	printf("Enter choice");
	scanf("%d",&i);
	switch(i)
	{
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
		printf("please enter the value to enter");
		scanf("\n %d",&num);
		printf("please enter the value after which you wanna add");
		scanf("\n %d",&data);
		insertmid(root,data,num);
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
	scanf("\n %d",&data);
	delmid(root,data);
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

void create(struct node **q,int num)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->pre=NULL;
	temp->data=num;
	temp->next=NULL;
	*q=temp;
}
void insertbeg(struct node **q,int num)
{
	struct node *abc,*temp;
	temp=*q;
	abc=(struct node*)malloc(sizeof(struct node));
	abc->pre=NULL;
	abc->data=num;
	abc->next=temp;
	temp->pre=abc;
	*q=abc;
}
void insertmid(struct node *q,int data,int num)
{
	struct node *temp,*abc;
	temp=q;
	while(temp->data!=data)
	{
		temp=temp->next;
	}
	abc=(struct node*)malloc(sizeof(struct node));
	abc->pre=temp;
	abc->data=num;
	abc->next=temp->next;
	temp->next=abc;
	abc->next->pre=abc;
}
void insertlast(struct node *q,int num)
{
	struct node *temp,*abc;
	temp=q;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	abc=(struct node*)malloc(sizeof(struct node));
	abc->pre=temp;
	abc->data=num;
	abc->next=NULL;
	temp->next=abc;
}
void delfirst(struct node **q)
{
	struct node *temp;
	temp=*q;
	temp->next->pre=NULL;
	*q=temp->next;
	free(temp);
	
}
void delmid(struct node *q,int data)
{
	struct node *temp;
	temp=q;
	while(temp->data!=data)
	{
		temp=temp->next;
	}
	temp->pre->next=temp->next;
	temp->next->pre=temp->pre;
	free(temp);
}
void dellast(struct node *q)
{
	struct node *temp;
	temp=q;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->pre->next=NULL;
	free(temp);
}
void display(struct node *q)
{
	while(q!=NULL)
	{
		printf("pre- %d data- %d next- %d \n",q->pre,q->data,q->next);
		q=q->next;
	}
}