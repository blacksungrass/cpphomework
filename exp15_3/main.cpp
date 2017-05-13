#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class String{
	friend ostream& operator << (ostream &out,const String &s);
	private:
		char *p;
		int len;
	public:
		String(char c=0,int l = 0)
		{
			if(l==0)
			{
				len = 0;
				p = NULL;
				return;
			}
			p = new char [l];
			if(p==NULL)
			{
				cout<<"allocating memory failed"<<endl;
				len = 0;
				return;
			}
			len = l;
			for(int i=0;i<l;i++)
				p[i] = c;
		}
		~String()
		{
			if(p!=NULL)
				delete []p;
			p = NULL;
		}
		String(String &b)
		{
			*this = b;
		}
		String& operator = (const char *d)
		{
			len = strlen(d);
			p = new char [len];
			if(p==NULL)
			{
				cout<<"allocating memory failed"<<endl;
				len = 0;
				return *this;
			}
			memcpy(p,d,sizeof(char)*len);
		}
		operator const char *() const
		{
			return p;
		}
		int operator ~ ()
		{
			return len;
		}
		String operator + (const String &b) const
		{
			String t;
			t.p = new char[this->len+b.len];
			if(p==NULL)
			{
				cout<<"allocating memory failed"<<endl;
				t.len = 0;
				return t;
			}
			t.len = this->len+b.len;
			memcpy(t.p,this->p,sizeof(char)*this->len);
			memcpy(t.p+this->len,b.p,sizeof(char)*b.len);
			return t;
		}
};
ostream& operator << (ostream &out,const String &s)
{
	for(int i=0;i<s.len;i++)
	{
		out<<s.p[i];
	}
	out<<endl;
	return out;
}
istream& operator >> (istream &in,String &s)
{
	string str;
	in>>str;
	s = str.c_str();
	return in;
}
int main()
{
	String s1,s2,s3;
	cin>>s1>>s2;
	cout<<s1<<s2;
	cout<<(~s1)<<' '<<(~s2)<<endl;
	cout<<(s1+s2)<<~(s1+s2)<<endl;
	char buf[200];
	cin>>buf;
	s3 = buf;
	cout<<s3<<(~s3)<<endl;
	return 0;
}
