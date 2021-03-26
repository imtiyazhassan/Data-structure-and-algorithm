#include <stdio.h>
#include <bits/stdc++.h>

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
    while (temp!= NULL)
    {
        printf("%d  ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void insert_at_last(int value)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node* t;
        t = head;
        while (t->link!=NULL)
        {
            t = t->link;
        }
        t->link = temp;

    }
}
void delete_node(int position)
{
    if(position == 1)
    {
        struct node* temp;
        temp = head;
        head = head->link;
        free(temp);
    }
    else
    {
        struct node* temp1;
        temp1 = head;
        for(int i = 0; i<=position-2; i+=1)
        {
            temp1 = temp1->link;
        }
        struct node* temp2;
        temp2 = temp1->link;
        temp1->link = temp2->link;
        free(temp2);
    }


}

int main()
{
    head = NULL;
    int n,cho,position;
    while(1)
    {
        printf("1. Insert node at last\n");
        printf("2. Delete node\n");
        printf("3. print\n");
        printf("4. Break\n");
        scanf("%d",&cho);

        if (cho==1)
        {
            scanf("%d",&n);
            insert_at_last(n);

        }
        if(cho ==2)
        {
            printf("The positon you want to delete\n");
            scanf("%d",&position);
            delete_node(position);
        }
        if (cho==3)
        {
            print();
        }
        if(cho == 4)
        {
            break;
        }

    }



    return 0;
}
