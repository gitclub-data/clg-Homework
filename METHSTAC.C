#include<stdio.h>
#include<conio.h>
#define max 5

struct stack{
	int arr[max];
	int top;
};

void push(struct stack *,int);
void pop(struct stack *);
void display(struct stack);

void main()
{
	struct stack s;
	int i,num;
	clrscr();
	s.top=-1;
while(i!=4)
{
	printf("press 1 to push the element");
	printf("press 2 to pop the element");
	printf("press 3 to display the element");
	printf("press 4 to exit");
	scanf("%d",&i);
	switch(i){
		case 1:
		printf("press the number to enter");
		scanf("%d",&num);
		push(&s,num);
		break;
		case 2:
		pop(&s);
		break;
		case 3:
		display(s);
		break;
		case 4:
		exit(1);
		break;
	}
}
}

void push(struct stack *s,int num)
{
	int i;
	i=max-1;
	if(s->top==i)
{
printf("stack is full");
}
else
{
s->top=s->top+1;
s->arr[s->top]=num;
}
}

void pop(struct stack *s)
{
if(s->top==-1)
{
printf("stack is empty");
}
else
{
s->top--;
}
}

void display(struct stack s)
{
	int i;
	for(i=s.top;i>=0;i--)
	{
		printf("elements %d",s.arr[i]);
	}
}