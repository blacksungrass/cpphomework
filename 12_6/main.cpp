#include <iostream>
#include <cmath>
using namespace std;
class Point{
	friend class Line;
	protected:
		double x,y;
	public:
		Point(double a=0,double b=0)
		{
			x = a;
			y = b;
		}
}; 
class Line:public Point{
	private:
		Point p;
	public:
		Line(double a=0,double b=0,double c=0,double d=0):Point(a,b),p(c,d){}
		Line(Point &a,Point &b):Point(a),p(b){}
		double GetLength()
		{
			double dx,dy;
			dx = p.x-x;
			dy = p.y-y;
			cout<<dx<<' '<<dy<<endl;
			return sqrt(dx*dx+dy*dy);
		}
};
int main()
{
	double t1,t2;
	cout<<"please input the first point: "<<endl;
	cin>>t1>>t2;
	Point p1(t1,t2);
	cout<<"please input the second point "<<endl;
	cin>>t1>>t2;
	Point p2(t1,t2);
	Line l(p1,p2);
	cout<<"the length of the line is: "<<l.GetLength()<<endl;
	return 0;
}
