#include <stdio.h>
#include <math.h>
#include <string.h>
#define max 1000
int pa( int *a, int p, int r);
int s( int * a, int p, int r, int i);
void daoxuprintf(int *a,int n);
int main()
{
    int m,n;
    scanf( "%d %d", &n,&m);
    int a[n];
    for( int i = 1; i <=n; i ++)
    {
        scanf( "%d", & a [ i ]);
    }
    int min = s( a, 1,n, m);
    printf( "%d", min);

    return 0;
}
int pa( int *a, int p, int r)
{
    int x;
    x = a [ r ];
    int i;
    i = p - 1;
    int j;
    j = p;
    int temp;
    for(; j < r; j ++)
    {
        if( a [ j ] <= x)
        {
            i ++;
            temp = a [ i ];
            a [ i ] = a [ j ];
            a [ j ] = temp;
        }
    }
    temp = a [ i + 1 ];
    a [ i + 1 ] = a [ r ];
    a [ r ] = temp;
    return i + 1;
}
int s( int * a, int p, int r, int i)
{
    if(p == r)
        return a [p ];
    int q;
    q = pa( a,p, r);
    int k;
    k = q - p + 1;
    if( i > k)
    {
        return s( a, q + 1, r, i - k);
    }
    else if( i == k)
    {
        return a [ q ];
    }
    else
    {
        return s( a,p, q - 1, i);
    }

}
void daoxuprintf(int *a,int n)
{
    int b[max];
    for(int i = n,j = 0;i >= 0,j < n;i--,j++)
    {
        b[j] = a[i];
    }
}
