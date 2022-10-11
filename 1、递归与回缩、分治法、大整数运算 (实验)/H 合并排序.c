#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int x,y;
void sort(int *a, int l, int r);

void merge(int *a, int l, int r);
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a, 0, n);//传参首地址a,0,
    for(int i=0; i<n; i++)
    {
        if(i > 0)
            printf(" %d",a[i]);
        else printf("%d",a[i]);
    }
}
void sort(int *a, int l, int r)
{
    if(r>l)//如果数组a最右边下标大于起始下标
    {
        int m;
        m = (r+l)/2;//中间值
        sort(a, l, m);//排序左边
        sort(a, m+1,r);//排序右边 右边子数组起始下标为左边终点下标
        merge(a, l, r);//合并两个数组为a
    }
}
void merge(int *a, int l, int r)
{
    int m;
    m=(l+r)/2;
    int n;
    n=(r-l)+1;//n为合并后数组的长度
    int b[n];//合并数组
    int i,j,k;//i 比较前一个子数组 j比教后一个子数组
    for(i=l, j=m+1,k = 0; i<=m&&j<=r;)
    {
        if(a[i] >= a[j]) //前一个子数组小就把a的值放到b里面
        {
            b[k]=a[j];
            j++;
            k++;
        }
        else//否则把后一个子数组的值放到b里面
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }


    if(i<=m)//如果左边子数组下标没到中间值
    {
        while(i<=m)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    if(j<=r)//如果后一个子数组比较完没有到右边下标终点r
    {
        while(j<=r)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    for(int i=0; i<n; i++)
    {
        a[l]=b[i];
        l++;
    }
}
