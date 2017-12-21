#include<stdlib.h>
#include<stdio.h>
/*n表示几等分，n+1表示他输出的个数*/
void RungeKutta(double y0,double a,double b,int n,double *x,double *y,double (*function)(double,double))
{
    double h=(b-a)/n,k1,k2,k3,k4;
    int i;
    x[0]=a;
    y[0]=y0;
        for(i=0;i<n;i++)
        {
            x[i+1]=x[i]+h;
            k1=function(x[i],y[i]);
            k2=function(x[i]+h/2,y[i]+h*k1/2);
            k3=function(x[i]+h/2,y[i]+h*k2/2);
            k4=function(x[i]+h,y[i]+h*k3);
            y[i+1]=y[i]+h*(k1+2*k2+2*k3+k4)/6;
        }
}
double function(double x,double y)
{
    return -x*x*y*y*y;
}
//例子求y'=-x*x*y*y*y(0<x<5);y0=1;

int main()
{
    double x[21],y[21];
    int i;
    printf("用四阶龙格-库塔方法\n");
    RungeKutta(1,0,5,20,x,y,function);
    for(i=0;i<21;i++)
        printf("x[%d]=%f,y[%d]=%f\n",i,x[i],i,y[i]);
    return 0;
}
