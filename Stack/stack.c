#include<stdio.h>
#include<stdlib.h>
#define max 5
int top,bottom,stack[max];
void init()
{
    top=bottom=-1;
}
int is_empty()
{
    return(top==bottom)?1:0;
}
int is_full()
{
    return(top==bottom)?1:0;
}
void push(int data)
{
    stack[++top]=data;
}
int pop()
{
    return stack[top--];
}
int peep()
{
    return top;
}
int main()
{
    int ch,data;
    init();
    while(1)
    {
    printf("Welcome to stack");
    printf("1.is empty");
    printf("2.is full");
    printf("3.push data");
    printf("4.pop");
    printf("5.peep");
    printf("6.Exit");
    }
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        if(!is_full())
        {
            printf("Enter data");
            scanf("%d",&data);
            push(data);
        }
        else
        {
            printf("Stack is full");
        }
        break;
    case 2:
        if (is_empty())
        {
        data=pop();
        printf("Popped data:%d\n",data);
        }
        else
        {
            printf("");

        }
    }
}