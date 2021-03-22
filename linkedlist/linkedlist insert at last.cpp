#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* link;
};

struct node* head;

/// print function
void print()
{
    struct node* temp;
    temp = head;
    while (temp!= NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

///insert function
void insert(int value)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = NULL;
    if(head == NULL)
    {
        head = temp;
        printf("%d \n",head);
        printf("%d \n",temp);
    }
    else
    {
        struct node* t;
        t = head;
        while(t->link != NULL)
        {
            t = t->link;
        }
        t->link = temp;
    }
}

int main ()
{
    head = NULL;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        insert(n);
        print();
    }
    return 0;
}
