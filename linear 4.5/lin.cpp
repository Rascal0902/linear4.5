#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
long long int  a[5][5][10],x[5][10];
int main()
{
    a[0][0][0]=9-17; a[0][1][0]=4; a[0][2][0]=8;
    a[1][0][0]=4; a[1][1][0]=15-17; a[1][2][0]=-4;
    a[2][0][0]=8; a[2][1][0]=-4; a[2][2][0]=9-17;
    a[0][0][1]=9-17; a[0][1][1]=4; a[0][2][1]=8;
    a[1][0][1]=4; a[1][1][1]=15-17; a[1][2][1]=-4;
    a[2][0][1]=8; a[2][1][1]=-4; a[2][2][1]=9-17;
    x[0][0]=1;x[1][0]=1;x[2][0]=1;
    for(int k=2;k<=5;k++)
    {
       a[0][0][k]=a[0][0][k-1]*a[0][0][0]+a[0][1][k-1]*a[1][0][0]+a[0][2][k-1]*a[2][0][0];
       a[0][1][k]=a[0][0][k-1]*a[0][1][0]+a[0][1][k-1]*a[1][1][0]+a[0][2][k-1]*a[2][1][0];
       a[0][2][k]=a[0][0][k-1]*a[0][2][0]+a[0][1][k-1]*a[1][2][0]+a[0][2][k-1]*a[2][2][0];
       a[1][0][k]=a[1][0][k-1]*a[0][0][0]+a[1][1][k-1]*a[1][0][0]+a[1][2][k-1]*a[2][0][0];
       a[1][1][k]=a[1][0][k-1]*a[0][1][0]+a[1][1][k-1]*a[1][1][0]+a[1][2][k-1]*a[2][1][0];
       a[1][2][k]=a[1][0][k-1]*a[0][2][0]+a[1][1][k-1]*a[1][2][0]+a[1][2][k-1]*a[2][2][0];
       a[2][0][k]=a[2][0][k-1]*a[0][0][0]+a[2][1][k-1]*a[1][0][0]+a[2][2][k-1]*a[2][0][0];
       a[2][1][k]=a[2][0][k-1]*a[0][1][0]+a[2][1][k-1]*a[1][1][0]+a[2][2][k-1]*a[2][1][0];
       a[2][2][k]=a[2][0][k-1]*a[0][2][0]+a[2][1][k-1]*a[1][2][0]+a[2][2][k-1]*a[2][2][0];
    }
    for(int k=1;k<=5;k++)
    {
        x[0][k]=a[0][0][k]*x[0][0]+a[0][1][k]*x[1][0]+a[0][2][k]*x[2][0];
        x[1][k]=a[1][0][k]*x[0][0]+a[1][1][k]*x[1][0]+a[1][2][k]*x[2][0];
        x[2][k]=a[2][0][k]*x[0][0]+a[2][1][k]*x[1][0]+a[2][2][k]*x[2][0];
    }
    for(int k=1;k<=5;k++)
    {
        printf("k=%d\n",k);
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                printf("%lld ",a[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
        printf("vector x    %lld   %lld   %lld \n\n",x[0][k],x[1][k],x[2][k]);
        printf("length  %f \n\n",sqrt(x[0][k]*x[0][k]+x[1][k]*x[1][k]+x[2][k]*x[2][k]));
        printf("multify %f \n\n",(float)(sqrt(x[0][k]*x[0][k]+x[1][k]*x[1][k]+x[2][k]*x[2][k])/sqrt(x[0][k-1]*x[0][k-1]+x[1][k-1]*x[1][k-1]+x[2][k-1]*x[2][k-1])));
        printf("unit vector of x %f %f %f\n\n",(float)(x[0][k]/sqrt(x[0][k]*x[0][k]+x[1][k]*x[1][k]+x[2][k]*x[2][k])),(float)(x[1][k]/sqrt(x[0][k]*x[0][k]+x[1][k]*x[1][k]+x[2][k]*x[2][k])),(float)(x[2][k]/sqrt(x[0][k]*x[0][k]+x[1][k]*x[1][k]+x[2][k]*x[2][k])));
    }
    return 0;
}
