#include <bits/stdc++.h>
#include <stdio.h>

#define N 10

void print();
void insert_hash(int value);

struct chaining
{
    int data;
    struct chaining* next;
};

struct chaining *chain[N];

void init()
{
    int i;
    for(i=0; i<N; i+=1)
    {
        chain[i] = NULL;
    }
}


void insert_hash(int value)
{
    struct chaining *newnode = (struct chaining*) malloc(sizeof(struct chaining));
    newnode->data = value;
    newnode->next = NULL;

    int key;
    key = value%N;
    /// printf("value %d ,key : %d  \n",value,key);

    ///if chain key is empty
    if(chain[key] == NULL)
    {
        chain[key] = newnode;
    }

    ///collision
    else
    {
        struct chaining* temp = chain[key];
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

int search_element(int value)
{
    int key = value % N;

    struct chaining *temp = chain[key];

    while(temp != NULL)
    {
        if(temp->data == value)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}





int del(int value)
{
    int key = value % N;

    struct chaining *temp = chain[key], *temp1;

    if(temp != NULL)
    {
        if(temp->data == value)
        {
            temp1 = temp;
            temp = temp->next;
            free(temp1);
            return 1;
        }
        else
        {
            while(temp->next != NULL)
            {
                if(temp->next->data == value)
                {
                    temp1 = temp->next;
                    temp->next = temp->next->next;
                    free(temp1);
                    return 1;
                }
                temp = temp->next;
            }
        }
    }

    return 0;
}



void print()
{
    int i;
    for(i=0; i<N; i+=1)
    {
        struct chaining *temp = chain[i];
        printf("Chain[(%d] --> ",i);

        while(temp != NULL)
        {
            printf("%d --> ",temp->data);
            temp  = temp->next;
        }
        printf("NULL\n");
    }
}





int main()
{

    init();
    int i,n;

    insert_hash(7);
    insert_hash(11);
    insert_hash(0);
    insert_hash(3);
    insert_hash(10);
    insert_hash(4);
    insert_hash(5);
    insert_hash(15);
    insert_hash(25);

    print();

    int key,val;

    printf("Enter the search value\n");
    scanf("%d",&key);

    if(search_element(key))
        printf("%d Element Found\n",key);
    else
        printf("%d Element Not Found\n",key);

    ///delete operation
    printf("The value u want to delete\n");
    scanf("%d",&val);

    if(del(val)){
        printf("%d is deleted\n",val);
        printf("After deleted chain is \n");
        print();
    }
    else
        printf("Not In array\n");

    return 0;
}
