#include <bits/stdc++.h>
#include <stdio.h>


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
    while(temp->link!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
}

void insert_at_sorted(int value)
{
    struct node* temp1;
    temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = value;

    if(head == NULL || temp1->data < head->data)
    {
        temp1->link = head;
        head = temp1;
    }
    else
    {
        struct node* prev = head;
        struct node* Forward;
        Forward = prev->link;
        while(Forward!=NULL && temp1->data > Forward->data)
        {
            prev = Forward;
            Forward = Forward->link;
        }
        prev->link = temp1;
        temp1->link = Forward;
    }

}

int main()
{
    head = NULL;
    insert_at_sorted(8);
    insert_at_sorted(6);
    insert_at_sorted(9);
    insert_at_sorted(1);
    insert_at_sorted(5);
    insert_at_sorted(11);
    print();
    return 0;
}
