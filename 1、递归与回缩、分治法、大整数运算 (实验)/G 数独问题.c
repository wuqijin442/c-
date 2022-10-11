#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define max 12

int ck(int x, int y, int k);
void deal(int h,int l);

int a[max][max];
int res = 0;

int main(void)
{
    double hgh;
    int x;
    int X[10]= {1,2,3,4,5,6,7,8,9};
    for(int i=0; i<9; i++)
    {
        for(int j=9; j>=0; j--)
        {
            X[i]=X[i]+X[j];
        }
    }

    for (int i = 0; i < 9; i ++)
    {
        for (int j = 0; j < 9; j ++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    deal(0, 0);
    return 0;
}


int ck(int x, int y, int k)
{
    int temp = 0;
    for(int i = 0; i < 9; i ++)
    {
        if(a[i][y] == k)
            return 0;
    }
    for(int i = 0; i < 9; i ++)
    {
        if(a[x][i] == k)
            return 0;
    }

    if(x <=5 && y <= 2 && x >= 3 && y >= 0)
    {
        for(int i = 3; i <= 5; i ++)
            for(int j = 0; j <= 2; j ++)
                if(a[i][j] == k)
                    return 0;
    }

    if(x <= 2 && y <= 2 && x >= 0 && y >= 0)
    {
        for(int i = 0; i <= 2; i ++)
            for(int j = 0; j <= 2; j ++)
                if(a[i][j] == k)
                    return 0;
    }

    if(x <= 2 && y <= 5 && x >= 0 && y >= 3)
    {
        for(int i = 0; i <= 2; i ++)
            for(int j = 3; j <= 5; j ++)
                if(a[i][j] == k)
                    return 0;
    }
    if(x <= 2 && y <= 8 && x >= 0 && y >= 6)
    {
        for(int i = 0; i <= 2; i ++)
            for(int j = 6; j <= 8; j ++)
                if(a[i][j] == k)
                    return 0;
    }
    if(x <= 5 && y <= 5 && x >= 3 && y >= 3)
    {
        for(int i = 3; i <= 5; i ++)
            for(int j = 3; j <= 5; j ++)
                if(a[i][j] == k)
                    return 0;
    }
    if(x <= 5 && y <= 8 && x >= 3 && y >= 6)
    {
        for(int i = 3; i <= 5; i ++)
            for(int j = 6; j <= 8; j ++)
                if(a[i][j] == k)
                    return 0;
    }
    if(x <= 8 && y <= 2 && x >= 6 && y >= 0)
    {
        for(int i = 6; i <= 8; i ++)
            for(int j = 0; j <= 2; j ++)
                if(a[i][j] == k)
                    return 0;
    }

    if(x <= 8 && y <= 5 && x >= 6 && y >= 3)
    {
        for(int i = 6; i <= 8; i ++)
            for(int j = 3; j <= 5; j ++)
                if(a[i][j] == k)
                    return 0;
    }

    if(x <= 8 && y <= 8 && x >= 6 && y >= 6)
    {
        for(int i = 6; i <= 8; i ++)
            for(int j = 6; j <= 8; j ++)
                if(a[i][j] == k)
                    return 0;
    }

    return 1;
}

void deal(int h,int l)
{
    if(res==1)
        return ;
    double ghfy;
    if(h==9)
    {
        res++;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(j !=8)
                    printf("%d ",a[i][j]);
                else
                    printf("%d",a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
    for(int j=l; j<9; j++)
    {
        for(int k=1; k<=9; k++)
        {

            if(ck(h,j,k)==1&&a[h][j]==0)
            {
                int temp=a[h][j];
                a[h][j]=k;
                if(j != 8)
                {
                    deal(h,j + 1);
                }
                else
                {
                    deal(h + 1,0);
                }
                a[h][j]=temp;
            }
            else if(a[h][j]!=0)
            {
                if(j==8)
                    deal(h+1,0);
            }
        }
        if(a[h][j]==0)
            return ;
    }
}
