#include<stdlib.h>
#include<stdio.h>
void ModEuler(double x0,double y0,double xn,int n,double (*function)(double,double))
{
    double h=(xn-x0)/n,yp,yc,x=x0,y=y0;
    int i;
        for(i=0;i<=n;i++)
        {
            yp=y+h*function(x,y);
            x=x0+i*h;
            yc=y+h*function(x,yp);
            y=(yp+yc)/2;
            printf("x[%d]=%f,y[%d]=%f\n",i,x,i,y);
        }
}
double function(double x,double y)
{
    return -x*x*y*y*y;
}
//例子求y'=-x*x*y*y*y(0<x<5);y0=1;

int main()
{
    printf("改进的欧拉公式：\n");
    ModEuler(0,1,5,20,function);
    return 0;
}
