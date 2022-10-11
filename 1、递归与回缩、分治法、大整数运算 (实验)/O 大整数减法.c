#include <stdio.h>
#include<string.h>
#include<math.h>
#define MIN 666
int i;
char r[100];
int main()
{
    int m;
    char a[100],b[100];
    int p[100]= {0};
    int q[100]= {0};
    scanf("%s %s",&a,&b);
    int len1 = strlen(a),len2 = strlen(b);
    int max,k;
    if(len1 <= len2)
        max=len2;
    else
        max=len1;
    if(len1 <= len2)
    {
        m=max;
        for(i=0; i<len2; i++,m--)
            p[m]=b[len2-1-i]-'0';
        m=max;
        for(i=0; i<len1; i++,m--)
            q[m]=a[len1-1-i]-'0';
    }
    else
    {
        m=max;
        for(i=0; i<len1; i++,m--)
            p[m]=a[len1-1-i]-'0';
        m=max;
        for(i=0; i<len2; i++,m--)
            q[m]=b[len2-1-i]-'0';
    }

    for(i=max; i>=0; i--)
    {
        p[i] -= q[i];
        if(p[i]<0)
        {
            p[i-1]--;
            p[i] += 10;

        }
    }
    if(len1<len2)
        printf("-");
    for(i=1; i< max+1; i++)
    {
        printf("%d",p[i]);
    }
    printf("\n");

}

