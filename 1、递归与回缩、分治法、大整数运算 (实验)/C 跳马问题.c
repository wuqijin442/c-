#include<stdio.h>

void tiaoma(int m,int n);
int x,y,sum = 0;
int main()
{
    int qipan[100][100];
    scanf("%d %d", &x,&y);
    tiaoma(0,0);
    printf("%d\n",sum);
    return 0;
}
void tiaoma(int m,int n)
{
    if(m<0||n<0||m>x||n>y)
    {
        return;
    }
    else if(m==x&&n==y)
    {
        sum++;
    }
    else
    {
        tiaoma(m+1,n+2);
        tiaoma(m+2,n+1);
        tiaoma(m+1,n-2);
        tiaoma(m+2,n-1);
    }

}
