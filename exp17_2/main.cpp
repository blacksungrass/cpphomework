#include <iostream>
#include <cmath>
using namespace std;
class Root
{
protected:
	double a,b;
public:
	void FindRoot();
	virtual double f(double) = 0;	
	Root(double x=0,double y=0):a(x),b(y){}
		
} ;
void Root::FindRoot()
{
	double c=a,d=b;
	double x;
	do
	{
		x = (c*f(d)-d*f(c))/(f(d)-f(c));
		if(f(x)*f(c)>0)
		{
			c = x;
		}
		else
		{
			d = x;
		}
	}while(abs(f(x))>=1e-6);
	cout<<"root at "<<fixed<<x<<endl;
}
class A:public Root
{
private:
	virtual double f(double x)
	{
		return x*x*x-5*x*x+16*x-80;
	}
public:
	A(double x=0,double y=0):Root(x,y){};
};
int main()
{
	A a(4.5,5.5);
	a.FindRoot();
	return 0;
}

