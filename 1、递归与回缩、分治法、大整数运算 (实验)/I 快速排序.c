#include<stdio.h>
#include <math.h>
#define max 100000

void quick_sort(int s[], int l, int r);
int main()
{
    int n;
    scanf("%d",&n);
    int a[max];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    quick_sort(a,0,n-1);
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
void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {

        int i;
        i = l;
        int j;
        j = r;
        int x;
        x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x)
                j--;
            if(i < j)
                s[i++] = s[j];

            while(i < j && s[i] < x)
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1);
        quick_sort(s, i + 1, r);
    }
}
