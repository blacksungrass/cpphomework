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
	Rectangle a(1,2,3,-4),b(-3,5,6,-2);
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
