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
int book[5]= {0};		 //��û�ֳ�ȥ��ʼ��,��û�з���ȥ��
int a[5];	 //a[n]=j��ʾ��n���˷ֵõڼ�����
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
    if(n == 5)			//�屾�鶼����
    {
        sum++;		//�ڼ��ַַ�
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
            book[i]=1;//�ֵ���book����==1
            ch(n+1);
            book[i]=0;//�б�ŷֱ�Ϊ0,1,2,3,4��5���飬׼���ָ�5����A,B,C,D,E������5���˶�5������Ķ���Ȥ���±���ʾ;//����bookѡ����Ϊ0
        }
    }
}
