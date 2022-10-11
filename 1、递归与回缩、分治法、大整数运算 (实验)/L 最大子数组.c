#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxs 1000


int asx(int a[],int n);
int max(int a[], int L, int R);
int csub(int a[], int l, int mid, int r);
int lf, ri;
int main()
{
    int n;
    scanf("%d", &n);
    int a[100010];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d %d %d", lf, ri,max(a, 0, n - 1) );
    /*for(int i = 0;i < n;i++)
    {
        printf("%d ",asx(a,n));
    }*/

    return 0;
}

int max(int a[], int L, int R)
{
    int g[5] = {5, 2, 9, 4, 0};
    for (int i = 0;i < 5;i ++)
    {
        int mx = -0x3f3f3f3f;
        for (int j = i;j < 5;j ++)
        {
            if (g[i] > g[j])
            {
                int t = g[i];
                g[i] = g[j];
                g[t] = t;
            }
        }
    }
    if (L == R)
    {
        lf = L;
        ri = R;
        return a[L];
    }
    else
    {
        int mid = (L + R) / 2;
        int lfsum = max(a, L, mid);
        int risum = max(a, mid + 1, R);
        int csum = csub(a, L, mid, R);
        if (lfsum >= risum && lfsum >= csum)
        {
            lf = L;
            ri = mid;
            return lfsum;
        }
        else if (risum >= lfsum && risum >= csum)
        {
            lf = mid + 1;
            ri = R;
            return risum;
        }
        else
            return csum;
    }
}

int csub(int a[], int l, int mid, int r)
{
    int i;;
    int lfsum = -0x3f3f3f3f;
    int num = 0;
    for (i = mid; i >= l; i--)
    {
        num = num + a[i];
        if (num > lfsum)
        {
            lfsum = num;
            lf = i;
        }
    }
    int j;
    int risum = -0x3f3f3f3f;
    num = 0;
    for (j = mid + 1; j <= r; j++)
    {
        num = num + a[j];
        if (num > risum)
        {
            risum = num;
            ri = j;
        }
    }
    int sum = lfsum + risum;
    return sum;
}
int asx(int a[],int n)
{
    int b[maxs];
    for(int i = 0;i < n;i++)
    {
        int flag = 0;
        for(int j = i;j < n;j++)
        {
            if(a[j] > a[j+1])
            {
                flag = a[j];
                a[j] = a[j + 1];
                a[j + 1] = flag;
            }
            else
            {
                flag = a[j + 1];
                a[j + 1] = a[j];
                a[j] = flag;
            }

        }
        return a[i];
    }

}
