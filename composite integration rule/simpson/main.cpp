#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double f(double x)
{

    return sqrt(1-x*x);
}//�Զ�����ֺ���

double s(double a,double b,int n)//��������ɭ��ʽ

{
    double h,x[n];

    double w=0,v=0;

    h=(b-a)/n*1.0;

    for(int i=1; i<=n/2; i++)

    {
        x[2*i-1]=a+(2*i-1)*h;

        w+=f(x[2*i-1]);
    }

    for(int i=1; i<=n/2-1; i++)

    {
        x[2*i]=a+2*i*h;

        v+=f(x[2*i]);
    }

    return h*(f(a)+4*w+2*v+f(b))/3.0;

}

int main()

{
    double a,b;

    int n;

    cout<<"�������������a,b��������n:"<<endl;

    cin>>a>>b>>n;

    cout<<endl;

    cout<<"����ֵΪ��"<<setprecision(30)<<2*s(a,b,n)<<endl;

    return 0;
}
