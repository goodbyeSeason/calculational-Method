#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#define LEN sizeof(double)
double *head,*headl,*y,*x,*t,e;
int m,n;
void input()
{
    int k,b;
    double d;
    printf("�����뷽�����з��̵ĸ��� m:\n");
    scanf("%d",&m);
    printf("\n�����뷽�����б����ĸ��� n:\n");
    scanf("%d",&n);
    b=m*(n+1);
    head=(double*)calloc(b,LEN);
    x = (double*)calloc(n,LEN);
    headl=(double*)calloc(n,LEN);
    printf("\n�����뷽������������ n:\n");
    for(k=1; k<=m*(n+1); k++)
        scanf("%lf",&head[k-1]);
    printf("\n�������ʼ����ֵ:\n");
    for(k=0; k<=n-1; k++)
        scanf("%lf",&x[k]);
    printf("\n��������⾫��:\n");
    scanf("%lf",&e);
    for(k=0; k<=n-1; k++)
    {
        d=0.0;
        for(b=0; b<=m-1; b++)
            d=d+head[b*(n+1)+k]*head[b*(n+1)+k];
        headl[k]=d;
    }
}
void didai()
{
    int i,k,j;
    double *pl,s;
    y=(double*)calloc(m,LEN);
    t=(double*)calloc(n,LEN);
    for(i=0; i<=m-1; i++)
    {
        s=0.0;
        for(j=0; j<=n-1; j++)
            s=s+head[i*(n+1)+j]*x[j];
        y[i]=s;
        for(;;)
        {
            for(j=0; j<=n-1; j++)
            {
                t[j]=0.0;
                for(k=0; k<=m-1; k++)
                    t[j]=t[j]+head[j+k*(n+1)]*(head[(k+1)*(n+1)-1]-y[k])/headl[j];
                for(k=0; k<=m-1; k++)
                    y[k]=y[k]+t[j]*head[j+k*(n+1)];
                x[j]=x[j]+t[j];
            }
            for(j=0; j<=n-1; j++)
                if(t[j]>e)break;
                if(j==n)break;
        }
    }
}
int main()
{
    int i;
    input();
    didai();
    printf("\n���������С���˽�Ϊ:\n");
    for(i=0; i<=n-1; i++)
        printf("%lf\t",x[i]);
        printf("\n");
    return 0;
}
