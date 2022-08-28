#include<stdio.h>
#include<ctype.h>
#define MAX 100
char stack[MAX];
int top=-1;
char pop()
{
    if(top==-1)
    {
        printf("stack underflow::");
    }
    else
    {
        return (stack[top--]);
    }
}
void push(char x)
{
    if(top==MAX)
    {
        printf("stack overflow::");
    }
        else
    {
        stack[++top]=x;
    }
}
int priority(char x)
{
    if(x=='(')
        return 0;
    if(x=='^')
        return 3;
    if(x=='/' || x=='*')
        return 2;
    if(x=='+' || x=='-')
        return 1;
}
int main()
{
    char expr[100];
    char *e;
    char x;
    printf("enter the expression :: \n");
    scanf("%s",expr);
    e=expr;
    while(*e!='\0')
    {
        if(isalnum(*e))
        {
            printf("%c",*e);
        }
        else if(*e=='(')
        {
            push(*e);
        }
        else if(*e==')')
        {
            while (x=pop()!='(')
            {
                printf("%c",x);
            }
        }
        else
        {
            while(priority(stack[top])>=priority(*e))
            {
                printf("%c",pop());
            }
            push(*e);
        }
        e++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
    return 0;
}