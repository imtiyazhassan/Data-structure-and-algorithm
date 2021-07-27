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
    struct node* t;
    t = head;
    while(t != NULL)
    {
        printf("%d ",t->data);
        t = t->link;
    }
    printf("\n");
}

void insert_at_first(int value)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = head;
    head = temp;

}

void insert_at_last(int value)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {

        struct node* temp2;
        temp2 = head;
        while (temp2->link!= NULL)
        {
            temp2 = temp2->link;
        }
        temp2->link = temp;
    }
}

void delete_node(int position)
{

    if (position == 1)
    {
        struct node *temp;
        temp = head;
        head = head->link;
        free(temp);
    }
    else
    {
        struct node* temp1;
        temp1 = head;
        for(int i=1; i<=position-2; i+=1)
        {
            temp1 = temp1->link;

        }
        struct node* temp2;
        temp2 = temp1->link;
        temp1->link = temp2->link;

        free(temp1);
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

int search_element(struct node*head, int key)
{
    while(head != NULL)
    {
        if(head->data == key)
        {
            return 1;
        }
        head = head->link;
    }
    return 0;
}



int main ()
{
    head = NULL;
    while(1)
    {
        int n,op,position,value;
        printf("1. Inset node at first\n");
        printf("2. Inset node at last\n");
        printf("3. print the list\n");
        printf("4. Delete Node\n");
        printf("5. Sorted linked list\n");
        printf("6. search element\n");
        printf("7. Break\n");


        scanf("%d",&op);
        if (op==1)
        {
            scanf("%d",&n);
            insert_at_first(n);
        }
        if (op==2)
        {
            scanf("%d",&n);
            insert_at_last(n);
        }
        if (op == 3)
        {
            print();
        }
        if (op == 4)
        {
            printf("Enter the position you want to delete \n");
            scanf("%d",&position);
            delete_node(position);

        }
        /*if(op == 5)
        {
            scanf("%d",&n);
            insert_at_sorted(n)
        }*/

        if(op == 6)
        {
            int key,result;
            printf("The element you want to search\n");
            scanf("%d",&key);

            result = search_element(head, key);

            if(result)
                printf("%d found \n",key);
            else
                printf("Not found\n");

        }

        if (op ==7)
        {
            break;
        }
    }
    return 0;
}









