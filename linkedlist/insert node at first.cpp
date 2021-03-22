#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* link;
};

struct node* head;

void print()
{
    struct node* temp;
    temp = head;
    while(temp!= NULL)
    {
        printf("%d ",temp->data);
        temp =temp->link;
    }
}

void insert_atfirst(int value)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = head;
    head = temp;

}

int main ()
{
    head = NULL;
    insert_atfirst(1);
    insert_atfirst(2);
    insert_atfirst(3);
    print();

    return 0;
}
