#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
#define Maxsize 100
///int n;
///scanf("%d",&n);
int s[Maxsize];

int top = -1;

void push (int value)
{
    if(top == Maxsize-1)
    {
        printf("Stack is overflow\n");
    }

    s[++top] = value;
}
void pop()
{
    if (top == -1)
    {
        printf("Stack is khali\n");
    }
    top--;
}
void  Top()
{
    int n;
    printf("Top element is  : %d \n",s[top]);
    ///return s[top];

}

int Isempty()
{
    if(top == -1)
        return 1;

}

void print ()
{
    int i;

    for (i =0; i<=top; i+=1)
    {
        printf("%d ",s[i]);
    }
    printf("\n");
}



int main ()
{

    while (1)
    {
        printf("Stack operation \n");
        printf("1 : Push \n");
        printf("2 : Pop \n");
        printf("3 : Top Element \n");
        printf("4 : print \n");
        printf("5 : Exit \n");

        int choice,n;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                scanf("%d",&n);
                push(n);
                break;
            }
            case 2 :
            {
                pop();
                break;
            }
            case 3 :
            {
                Top();
                break;
            }
            case 4 :
            {
                print();
                break;
            }
            default:
            {
                printf("Invalid choice \n");
            }
        }

    }
}
