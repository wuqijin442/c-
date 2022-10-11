#include<stdio.h>
#include<stdbool.h>
#define NB 20
int jz,ii,n,T;
char ai[5][5];
int x[NB],y[NB],a[NB],b[NB];
bool biaoji=false;

void dfs(int n)
{
    if (biaoji)
        return;
    if (n==jz)
    {
        biaoji=true;
        return;
    }
    int i,k;
    char j;
    bool sign1,sign2,sign3;
    for (j='1'; j<='4'; j++)
    {
        if (biaoji)
            return;
        sign1=true;
        sign2=true;
        sign3=true;
        ai[x[n]][y[n]]=j;

        for (i=0; i<4; i++)
        {
            if (i==y[n])
                continue;
            if (j==ai[x[n]][i])
            {
                sign1=false;
                break;
            }
            if (i==x[n])
                continue;
            if (j==ai[i][y[n]])
            {
                sign2=false;
                break;
            }
        }
        if (!sign1||!sign2)
        {
            ai[x[n]][y[n]]=0;
            continue;
        }

        for (i = a[n]; i < a[n]+2; i++)
        {
            for (k = b[n]; k < b[n]+2; k++)
            {
                if (i == x[n] && k == y[n])
                    continue;
                if (j == ai[i][k])
                {
                    sign3 = false;
                    break;
                }
            }
        }
        if (!sign3)
        {
            ai[x[n]][y[n]] =  0;
            continue;
        }

        dfs(n+1);

    }
}

void input()
{
    for (int i = 0; i < 4; i++)
    {
        scanf("%s",ai[i]);
        for (int j = 0; j < 4; j++)
        {
            if (ai[i][j] == '*')
            {
                x[n] = i;
                y[n] = j;
                n++;
            }
        }
    }
}
void output()
{
    printf("Case #%d:\n",ii);
    for (int i = 0; i <= 3; i++)
    {
        printf("%s\n",ai[i]);
    }
    if(ii!=T)
        printf("\n");
}

int main()
{
    scanf("%d",&T);
    for(ii = 1; ii <= T; ii++)
    {
        n=0;
        biaoji=false;
        input();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 0; k <= 1; k++)
                {
                    if (x[i]>=2*j && x[i]<=2*j+1 && y[i]>=2*k && y[i]<=2*k+1)
                    {
                        a[i] = j*2;
                        b[i] = k*2;
                    }
                }
            }
        }
        jz=n;
        dfs(0);
        output();
    }
    return 0;
}
