#include <fstream>
#include <iostream>
#include <cctype>
using namespace std;
int main()
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	if(!in)
	{
		cout<<"open input file failed"<<endl;
		return 0;
	}
	in>>noskipws;
	char c;
	char pre = 0;
	while(in)
	{
		in>>c;
		if(islower(c)&&(pre==' '||pre=='\t'||pre=='\n'||pre==','||pre=='.'||pre==0))
		{
			c = toupper(c);
		}
		out<<c;
		pre = c;
	}
	in.close();
	out.close();
	return 0;
} 
