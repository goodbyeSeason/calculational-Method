#include <stdio.h>
#include <stdlib.h>
float f(float x);
int main()
{
    float a,b,h,M1,M2,M=0;
    int i,n;
    scanf("a=%f,b=%f,n=%d",&a,&b,&n);
    h=(b-a)/n;
    for(i=1; i<n; i++)
        M+=f(a+i*h);
    M1=f(a)+f(b)+2*M;
    h=h/2;
    M2=h*M1;
    printf("T=%f\n",M2);
    return 0;
}
float f(float x)
{
    float f;
    f=x*x*x;
    return f;
}
