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



/*int main ()
{
    head = NULL;
    insert_at_first(1);
    insert_at_first(2);
    print();
    insert_at_last(4);
    insert_at_last(5);
    print();

    return 0;
}*/

int main ()
{
    head = NULL;
    while(1)
    {
        int n,op,position;
        printf("1. Inset node at first\n");
        printf("2. Inset node at last\n");
        printf("3. print the list\n");
        printf("4. Delete Node\n");
        printf("5. Break\n");


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
        if (op ==5)
        {
            break;
        }
    }
    return 0;
}









