#include<stdio.h>
#include<math.h>
#define n 10
/*���ﶨ���nΪ���������ʽ��,��������ĵȷ���*/
//�ȸ��������ֺ����Ķ���
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

	printf("���:\n");
	printf("������[%f,%f]��,����˹����= %f \n",a,b,cotes(a,b));
	return 0;
}
