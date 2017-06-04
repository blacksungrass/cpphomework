#include <iostream>
using namespace std;
class Point{
	friend class Rectangle;
	private:
		double x,y;
	public:
		Point(double a,double b):x(a),y(b){};
};
class Rectangle{
	private:
		Point left,right;
	public:
		Rectangle(double a,double b,double c,double d):left(a,b),right(c,d){};
		double GetArea() const
		{
			return (right.x-left.x)*(left.y-right.y);
		}
		bool operator < (const Rectangle &b)const
		{
			double sa = this->GetArea();
			double sb = b.GetArea();
			return sa<sb;
		}
		bool operator > (const Rectangle &b)const
		{
			return b<*this;
		}
};
int main()
{
	double t[8];
	cout<<"please input 4 points"<<endl;
	for(int i=0;i<8;i++)
		cin>>t[i];
	Rectangle a(t[0],t[1],t[2],t[3]);
	Rectangle b(t[4],t[5],t[6],t[7]);
	if(a>b)
	{
		cout<<"a is bigger than b"<<endl;
	}
	else if(a<b)
	{
		cout<<"a is smaller than b"<<endl;
	}
	else
	{
		cout<<"a is equal to b"<<endl;
	}
	return 0;
}

