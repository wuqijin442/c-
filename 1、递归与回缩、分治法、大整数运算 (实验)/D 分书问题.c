#include<stdio.h>
#include<math.h>
int x,y;
int sum=0;
int like[5][5]=
{
    {0,0,1,1,0},
    {1,1,0,0,1},
    {0,1,1,0,1},
    {0,0,0,1,0},
    {0,1,0,0,1}
};
int book[5]= {0};		 //都没分出去初始化,有没有发出去·
int a[5];	 //a[n]=j表示第n个人分得第几本书
void ch(int n);

int main()
{
    for(int k =0;k < 5;k++)
    {
        a[k] = k;
    }
    int m,n;
    ch(0);
    return 0;
}
void ch(int n)
{
    if(n == 5)			//五本书都分完
    {
        sum++;		//第几种分法
        printf("num = %d:",sum);
        for(int i=0; i<5; i++)
        {
            printf(" %d",a[i]);
        }
        printf("\n");
    }
    int i;
    for(i=0; i<5; i++)
    {
        if(like[n][i]==1&&book[i]==0)
        {
            a[n]=i;
            book[i]=1;//分到书book【】==1
            ch(n+1);
            book[i]=0;//有编号分别为0,1,2,3,4的5本书，准备分给5个人A,B,C,D,E。假设5个人对5本书的阅读兴趣如下表所示;//回溯book选到书为0
        }
    }
}
