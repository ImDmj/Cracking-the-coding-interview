#include<stdio.h>
#include<conio.h>

struct stack
{
    int num;
    int minnum;
}a[100];

void push(int n,int m,int top)
{
    top++;
    if (top>=100) {
	printf("Stack Full\n");
    }
    else{
	a[top].num = n;
	a[top].minnum = m;
    }
}

void pop(int top)
{
    if (top<0) {
	printf("Stack Empty\n");
    }
    else
    {
       top--;
    }
}

void print(int top)
{
    int j;
    printf("Stack: \n");
    for (j = 0; j<=top ; j++)
    {
	printf("(%d, %d)\n",a[j].num,a[j].minnum);
    }
}

void get_min(int top)
{
    if (top < 0)
    {
	printf("Empty Stack\n");
    }
    else
    {
	printf("Minimum element is: %d \n",a[top].minnum);
    }
}

void main()
{
    int top = -1,min=0,num=0;
    clrscr();
    do
    {
    printf("\nEnter the list to push (-1 to stop): ");
    scanf("%d",&num);
    if(num != -1)
       {
	if (top == -1)
	{
	    min = num;
	}
	else
	{
	    if (num < min)
	    {
		min = num;
	    }
	}
	push(num, min, top);
	top++;
       }
    }while(num != -1);
    print(top);
    get_min(top);
    getch();
}
