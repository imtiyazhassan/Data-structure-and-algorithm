#include <bits/stdc++.h>
#include <stdio.h>
#define N 10


int hash(int key)
{
    return key % N;
}

int linear_probing(int arr[], int key)
{
    int index = hash(key);
    int i;

    while(arr[(index+i)%N] != 0)
        i+=1;
    return (index+i)%N;

}


void insert_hash(int arr[], int key)
{
    int index = hash(key);

    if(arr[index] != 0)
    {
        index = linear_probing(arr,key);
    }
    arr[index] = key;

}

int search(int arr[], int key)
{
    int index = hash(key);

    int i = 0;

   while(arr[(index + i) % N] != key)
    {
        i+=1;
    }

    return (index+i)%N;
}




int main()
{
    int arr[10] = {0};
    insert_hash(arr,10);
    insert_hash(arr,8);
    insert_hash(arr,11);
    insert_hash(arr,7);

    int i;
    for(i=0; i<N; i+=1)
    {
        if(arr[i] == 0)
        {
            printf("arr[%d] = NULL\n",i);
        }
        else
            printf("arr[%d] : %d\n",i, arr[i]);
    }

    if(search(arr,11))
        printf("value found\n");


    return 0;
}

