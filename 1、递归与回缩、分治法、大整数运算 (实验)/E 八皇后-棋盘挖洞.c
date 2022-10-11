#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int N=9;
int q[9];
int s[9];
int l[17];
int r[17];
char ch[10][10];

void Try(int row);

int main()
{
    int i,j;
    for(i=1; i<9; i++)
    {
        for(j=1; j<9; j++)
            scanf("%c",&ch[i][j]);
        getchar();
    }

    for(i=0; i<9; i++)
        s[i]=1;
    for(i=0; i<17; i++)
    {
        l[i]=1;
        r[i]=1;
    }
    Try(1);
    return 0;
}

void Try(int row)
{
    int i,j;
    if(row!=9)
    {
        for(i=1; i<9; i++)
        {
            if(ch[row][i]=='.')
            {
                if(s[i]&&r[row+i]&&l[i-row+N])
                {
                    q[row] = i;
                    s[i] = 0;
                    l[i-row+N]=0;
                    r[i+row]=0;
                    Try(row+1);
                    s[i]=l[i-row+N]=r[i+row]=1;
                }
            }
        }
    }
    else
    {
        for(i=1; i<9; i++)
        {
            if(i==8)
                printf("%d\n",q[i]);
            else
                printf("%d",q[i]);
        }
        exit(0);
    }

}

