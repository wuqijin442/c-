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
    sort(a, 0, n);//�����׵�ַa,0,
    for(int i=0; i<n; i++)
    {
        if(i > 0)
            printf(" %d",a[i]);
        else printf("%d",a[i]);
    }
}
void sort(int *a, int l, int r)
{
    if(r>l)//�������a���ұ��±������ʼ�±�
    {
        int m;
        m = (r+l)/2;//�м�ֵ
        sort(a, l, m);//�������
        sort(a, m+1,r);//�����ұ� �ұ���������ʼ�±�Ϊ����յ��±�
        merge(a, l, r);//�ϲ���������Ϊa
    }
}
void merge(int *a, int l, int r)
{
    int m;
    m=(l+r)/2;
    int n;
    n=(r-l)+1;//nΪ�ϲ�������ĳ���
    int b[n];//�ϲ�����
    int i,j,k;//i �Ƚ�ǰһ�������� j�Ƚ̺�һ��������
    for(i=l, j=m+1,k = 0; i<=m&&j<=r;)
    {
        if(a[i] >= a[j]) //ǰһ��������С�Ͱ�a��ֵ�ŵ�b����
        {
            b[k]=a[j];
            j++;
            k++;
        }
        else//����Ѻ�һ���������ֵ�ŵ�b����
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }


    if(i<=m)//�������������±�û���м�ֵ
    {
        while(i<=m)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    if(j<=r)//�����һ��������Ƚ���û�е��ұ��±��յ�r
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
