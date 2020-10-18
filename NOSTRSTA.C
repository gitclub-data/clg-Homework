#include<stdio.h>
#include<conio.h>
#define max 5

void main()
{
int i,num;
int arr[max];
int top;
int m;
clrscr();
m=max-1;
top=-1;
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
if(top==m)
{
printf("stack is full");
}
else
{
top=top+1;
arr[top]=num;
}
break;
case 2:
if(top==-1)
{
printf("stack is empty");
}
else
{
top--;
}
break;
case 3:
for(i=top;i>=0;i--)
{
printf("Elements %d",arr[i]);
}
break;
case 4:
exit(1);
break;
}
}
}