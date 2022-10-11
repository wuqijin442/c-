#include <stdio.h>
#include <string.h>
#define max 100
int res[max*max];
int num[max];
char m[max];
void result(int num[],int res[],int len)
{
    int mod[max*max] = {0};
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < max*max; j++)
        {
            mod[i + j] += num[i]*res[j];
        }
    }
    for(int i = 0; i < max*max; i++)
    {
        if(mod[i] >= 10)
            mod[i + 1] += (mod[i]/10);
        res[i] = mod[i] % 10;
    }
}
int main()
{

    int n;          //n为指数，m为底数
    scanf("%d %s",&n,&m);
    printf("%s^%d = ",m,n);
    int len = strlen(m);
    int i,j,k;
    for(i = len - 1,j = 0,k = 0; i >= 0; i--)
    {
        num[j++] = m[i] - '0';
        res[k++] = m[i] - '0';
    }
    n--;
    while(n)
    {
        result(num,res,len);
        n--;
    }
    for(i = max*max-1; i > 0; i--)
    {
        if(res[i])
            break;
    }
    for(; i >= 0; i--)
        printf("%d",res[i]);
    return 0;
}
