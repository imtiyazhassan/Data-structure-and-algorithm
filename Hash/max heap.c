#include <stdio.h>


void display(int arr[],int n)
{
    int i;
    for (i=1; i<n; i+=1)
    {
        printf("%d ",arr[i]);
    }
}

void insert(int arr[],int n)
{
    int temp, i = n;
    printf("i = %d\n",i);
    temp = arr[i];

    while(i>1 && temp > arr[i/2])
    {
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}

int main()
{
    int i,n;
    ///int arr[100];
    printf("Enter the element of array\n");
    scanf("%d",&n);
    int arr[n];
    for(i=0; i<n; i+=1)
    {
        scanf("%d",&arr[i]);

    }
    ///int arr[] = {0,10,20,30,25,4,40,35};
    ///display(arr,n);

    ///insert ->
    for(i=2; i<n; i+=1)
    {
        insert(arr,i);
    }

    ///print
    /*for(i=1; i<n; i+=1)
    {
        printf("%d ",arr[i]);
    }*/

    display(arr,n);
    printf("\n");
    return 0;
}
