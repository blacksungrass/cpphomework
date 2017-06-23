#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	ofstream out("prime.dat",ios::binary|ios::out);
	if(!out)
	{
		cout<<"create file failed"<<endl;
		return 0;
	}
	int i;
	for(i=2;i<=100;i++)
	{
		int j;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
				break;
		}
		if(i==j)
			out.write((char*)&i,sizeof(int));
	}
	out.close();
	ifstream in("prime.dat",ios::in|ios::binary);
	for(i=10;i<25;i++)
	{
		in.seekg(i*sizeof(int),ios::beg);
		int t;
		in.read((char*)&t,sizeof(t));
		cout<<t<<' ';
	}
	cout<<endl;
	in.close();
	return 0;
}
