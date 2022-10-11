#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 100000

void sort(int *a,int l,int end)
{
    if(l<end)
    {
        int mid;
        mid = partition(a,l,end);
        sort(a,l,mid-1);
        sort(a,mid+1,end);
    }
}
int i,j;
int temp;
int partition(int *a,int l,int end)
{
    srand((unsigned int)time(NULL));


    i=(l+rand()%(end-l+1));

    int x;
    x = a[i];
    a[i] = a[end];
    a[end] = x;
    i = l - 1;

    for(j=l; j<end; j++)
    {
        if(a[j]<=x)
        {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    a[end] = a[i+1];
    a[i+1] = x;
    return i+1;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[max];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,0,n-1);
    for(int i=0; i<n; i++)
    {
        if(i > 0)
        {
            printf(" %d",a[i]);
        }
        else
            printf("%d",a[i]);
    }

    return 0;
}
