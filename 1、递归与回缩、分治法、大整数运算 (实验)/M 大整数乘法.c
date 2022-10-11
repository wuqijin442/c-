#include<stdio.h>
#include<math.h>
#include<string.h>
int len = 0;
void po(int *a, int *b, int *c, int len1, int len2)
{
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            c[i+j] += a[i]*b[j];
        }
    }
    for (int i = len1 + len2 - 1 - 1; i > 0; i--)
    {
        if (c[i] >=10)
        {
            c[i-1] += c[i] / 10;
            c[i] =c[i]% 10;
        }
    }
}
int main()
{
    char str1[1000];
    scanf("%s", str1);
    char str2[1000];
    scanf("%s", str2);
    int a[1000] = {0};
    int b[1000] = {0};
    int c[1000] = {0};
    int len1 = strlen(str1),len2 = strlen(str2);
    int p = 0,q = 0;
    int g = p + q;
    int len = len1 + len2 - 1;
    if (str1[0] == '-')
    {
        p = 1;
        len1--;
    }
    if (str2[0] == '-')
    {
        q++;
        len2--;
    }
    for(int i = 0;i < len1;i++)
    {
        int d = i + p;
        a[i] = str1[d] - '0';
    }
    for(int j = 0;j < len2; j++)
    {
        int f = j + q;
        b[j] = str2[f] - '0';
    }
    po(a, b, c, len1, len2);

    if (g == 1)
    {
        printf("-");
    }
    if (c[0] == 0)
    {
        printf("%d", c[0]);
    }
    printf("Product : ");
    for (int i = 0; i < len; i++)
    {
        if (c[0] != 0)
        {
            printf("%d", c[i]);
        }
    }
    printf("\n");
    return 0;
}
