#include<stdio.h>
#include<conio.h>
#define max 5

struct stack{
int arr[max];
int top;
};
struct stack push(struct stack,int);
struct stack pop(struct stack);
void display(struct stack);
void main()
{
int i,num;
struct stack s;
s.top=-1;
while(i!=4)
{
printf("press 1 to push");
printf("press 2 to pop");
printf("press 3 to display");
printf("press 4 to exit");
scanf("%d",&i);
switch(i)
{
case 1:
printf("press the number to enter");
scanf("%d",&num);
if(s.top==max)
{
printf("stack is full");
}
else
{
s.top=s.top+1;
s.arr[s.top]=num;
}
break;
case 2:
if(s.top==-1)
{
printf("stack is empty");
}
else
{
s.top--;
}
break;
case 3:
for(i=s.top;i>=0;i--)
{
printf("Elements %d",s.
arr[i]);
}
break;
case 4:
exit(1);
break;
}
}
}