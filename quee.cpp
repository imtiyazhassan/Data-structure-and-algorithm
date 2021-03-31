#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

#define Maxsize 3
int arr[Maxsize];
int rear = -1;
int ffront = -1;


void enqueue (int value)
{
    if (rear == Maxsize-1)
    {
        printf("Queue is full \n");
    }
    else
    {
        if (ffront == -1)
            ffront = 0;
        rear++;
        arr[rear] = value;
    }
}
void dequeue()
{
    if (ffront == -1)
    {
        printf("No element in array \n");
    }
    else
    {
        printf ("\nDeleted Items %d \n",arr[ffront]);
        ffront++;
        if (ffront > rear)
        {
            ffront = rear = -1;
        }

    }
}
void front ()
{
    if (ffront == -1 || ffront > rear)
        printf("No element\n");
    else
    {
        printf("Front element is %d\a\n",arr[ffront]);
    }


}

void display ()
{
    if (ffront == -1 ||  ffront > rear)
    {
        printf("Queue is empty \n");
    }
    int i;
    for (i=ffront; i<=rear; i+=1)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int main ()
{
    int n;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
     enqueue(40);
    enqueue(80);
    display();
    front();
    display();
    enqueue(90);
    enqueue(110);
    display();

    return 0;
}
