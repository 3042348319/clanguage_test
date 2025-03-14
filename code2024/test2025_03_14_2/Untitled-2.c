#include<stdio.h>

float f_of_xandn(int x,int n);

int main()
{
    int x,n;
    scanf("%d%d",&x,&n);
    float num=f_of_xandn(x,n);
    printf("%.2f",num);
    return 0;
}

float f_of_xandn(int x,int n)
{
    if(n==1)
    {
        return x*1.0 / (x + 1);
    }
    float num;
    num=x/(n+f_of_xandn(x,n-1));
    return num;
}
