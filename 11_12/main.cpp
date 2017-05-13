#include <iostream>
#include <cstring>
using namespace std;
class Matrix{
	private:
		double *p;
		int m,n;
	public:
		Matrix(double init = 0,int mm = 0,int nn = 0)
		{
			if(mm*nn==0)
			{
				m = 0;
				n = 0;
				p = NULL;
			}
			else
			{
				m = mm;
				n = nn;
				p = new double [m*n];
				if(p==NULL)
				{
					cout<<"error\nallocatint memory failed\n";
					m = 0;
					n = 0;
					p = NULL;
					return;
				}
				for(int i=0;i<m*n;i++)
					p[i] = init;
			}
		}
		Matrix(double *d,int mm,int nn)
		{
			if(d==NULL)
			{
				Matrix t;
				*this = t;
				return;
			}
			p = new double[mm*nn];
			if(p==NULL)
			{
				cout<<"error\nallocatint memory failed\n";
				Matrix t;
				*this = t;
				return;
			}
			m = mm;
			n = nn;
			memcpy(p,d,sizeof(double)*m*n);
		}
		~Matrix()
		{
			if(p!=NULL)
				delete []p;
			p = NULL;
		}
		Matrix(Matrix &b)
		{
			*this = b;
		}
		Matrix& operator = (const Matrix &b)
		{
			if(b.p==NULL)
			{
				m = 0;
				n = 0;
				p = NULL;
			}
			else
			{
				p = new double[b.m*b.n];
				if(p==NULL)
				{
					cout<<"error\nallocatint memory failed\n";
					m = 0;
					n = 0;
					p = NULL;
					return *this;
				}
				memcpy(p,b.p,sizeof(double)*b.m*b.n);
				m = b.m;
				n = b.n;
				return *this;
			}
		}
		Matrix operator + (const Matrix &b) const
		{
			Matrix ret;
			if(this->m!=b.m||this->n!=b.n)
			{
				cout<<"add error\n";
				return ret;
			}
			ret = *this;
			for(int i=0;i<m*n;i++)
			{
				ret.p[i] += b.p[i];
			}
			return ret;
		}
		Matrix operator - (const Matrix &b) const
		{
			Matrix ret;
			if(this->m!=b.m||this->n!=b.n)
			{
				cout<<"sub error\n";
				return ret;
			}
			ret = *this;
			for(int i=0;i<m*n;i++)
			{
				ret.p[i] -= b.p[i];
			}
			return ret;
		}
		void show()
		{
			int i,j;
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					cout<<p[i*n+j]<<' ';
				}
				cout<<endl;
			}
			cout<<endl;
		}
};
int main()
{
	double t1[9] = {1,2,3,4,5,6,7,8,9};
	Matrix a(t1,2,3),b(t1+3,2,3),c(100,2,3);
	a.show();
	b.show();
	c.show();
	(a+b).show();
	(a-b).show();
	a = c;
	(a+b).show();
	return 0;
}
