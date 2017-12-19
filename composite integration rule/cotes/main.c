#include<stdio.h>
#include<math.h>
#define n 10
/*这里定义的n为复化求积公式中,积分区间的等分数*/
//先给出被积分函数的定义
double f(double x)
{
	return ( sin(x)*sin(x)+cos(x) );
}
double cotes(double a,double b)
{
	return( (b-a)*(7*f(a)+32*f(3*a/4+b/4)+12*f((a+b)/2)+32*f(a/4+3*b/4)+7*f(b))/90 );
}
int main()
{

	double a=0,b=1;

	printf("结果:\n");
	printf("在区间[%f,%f]上,科特斯积分= %f \n",a,b,cotes(a,b));
	return 0;
}
