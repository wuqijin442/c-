#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int a[1000];
    int b[1000];
    int c[1000];
    int n,p,q,r;
    scanf("%d",&n);
    char str1[1000];
    char str2[1000];
    for(int m = 0; m < n; m++)
    {
        scanf("%s %s",&str1,&str2);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        int len1 = strlen(str1),len2 = strlen(str2);
        if(len1 <=len2)
        {
            r=len2;
        }
        else
        {
            r=len1;
        }
        int h = len1 - 1;
        for(int i=0; i<len1; i++)
        {
            a[i]=str1[h - i]-'0';
        }

        p=len1;
        int v = len2 - 1;
        for(int i=0; i<len2; i++)
        {
            b[i]=str2[v - i]-'0';
        }
        q=len2;
        for(int i=0; i<r; i++)
    {
        c[i]=c[i]+a[i]+b[i];
        c[i+1]+=c[i]/10;
        c[i]=c[i]%10;
        if(c[i]>=10)
        {
            c[i]=c[i]+a[i]+b[i];
            c[i+1]++;
            c[i]=c[i]%10;
        }
    }
    r++;
    while(c[r - 1]==0)
    {
        r--;
        if(r==1)
        {
            break;
        }
    }
        printf("Case %d:\n",m+1);
        printf("%s + %s = ",str1,str2);
        for(int i=r-1; i>=0; i--)
        {
            printf("%d",c[i]);
        }
        printf("\n");
        printf("\n");
    }
    return 0;
}

