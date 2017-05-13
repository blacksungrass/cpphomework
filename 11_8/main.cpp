#include <iostream>
using namespace std;
class Point{
	private:
		double x,y;
	public:
		Point(double a=0,double b=0):x(a),y(b){};
		Point operator ++ (int)
		{
			Point t = *this;
			this->x++;
			this->y++;
			return t;
		}
		Point& operator ++ ()
		{
			this->x++;
			this->y++;
			return *this;
		}
		Point operator -- (int)
		{
			Point t = *this;
			this->x--;
			this->y--;
			return t;
		}
		Point& operator -- ()
		{
			this->x--;
			this->y--;
			return *this;
		}
		void show()
		{
			cout<<"("<<x<<","<<y<<")"<<endl;
		}
};
int main()
{
	Point a;
	(a++).show();
	(++a).show();
	return 0;
}
