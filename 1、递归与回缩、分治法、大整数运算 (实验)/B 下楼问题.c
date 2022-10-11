#include <stdio.h>
#include <stdlib.h>
int step(int n);
int main(){
    int h;
    while((scanf("%d",&h))!=EOF){
        int c;
        if(h<0 || h>30)
            return;
        else
        {
            c = step(h);
            printf("%d\n",c);
        }
    }
    return 0;
}
int step(int n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(n==3)
        return 4;
    else
    {
        return step(n-1)+step(n-2)+step(n-3);
    }
}
