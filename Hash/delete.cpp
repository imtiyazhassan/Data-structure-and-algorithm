#include <stdio.h>

void insert(int arr[],int n)
{
    int temp,i = n;
    temp = arr[i];

    while(i>1 && temp > arr[i/2])
    {
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;

}

int delete_heap(int arr[],int n)
{
   int i,j,x,val,temp;
   val = arr[1];
   x = arr[n];

   arr[1] = arr[n];
   arr[n] = val;

   i=1, j=i*2;

   while(j < n-1)
   {
       if(arr[j+1] > arr[j])
       {
           j=j+1;
       }

       if(arr[i] < arr[j])
       {
           temp = arr[i];
           arr[i] = arr[j];
           arr[j] = temp;


           i = j;
           j = 2*j;
       }
       else
         break;

   }
   return val;
}


int main()
{
    int i,n;
    scanf("%d",&n);
    int arr[n];

    for(i=0; i<n; i+=1)
    {
        scanf("%d",&arr[i]);
    }

   ///insert
   for(i=2; i<n; i+=1)
   {
       insert(arr,i);
   }

   ///int m = delete_heap(arr,n);
   ///printf("Delete element is: %d\n",delete_heap(arr,n));

   printf("Max Heap is \n");
   for(i=1; i<n; i+=1)
   {
       printf("%d ",arr[i]);
   }

   printf("\n");

   return 0;
}

