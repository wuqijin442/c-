#include <stdio.h>

void ta(int n,char A,char B,char C);
int n;
int main()
{

    char A = 'A',B = 'B',C = 'C';
    scanf("%d",&n);
    ta(n,A,B,C);
    return 0;
}
void ta(int n,char A,char B,char C)
{
    if(n != 1){
        ta(n-1,A,C,B);
        printf("Move disk %d from %c to %c\n",n,A,C);
        ta(n-1,B,A,C);
    }
    else{

        printf("Move disk %d from %c to %c\n",n,A,C);

    }
}

