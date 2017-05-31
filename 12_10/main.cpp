#include <iostream>
#include <cstring>
using namespace std;
class Dog{
	protected:
		char breed[80];
		int height,weight;
		char color[80];
	public:
		Dog(char *s1=NULL,int a=0,int b=0,char *s2=NULL)
		{
			if(s1)
			{
				strcpy(breed,s1);
			}
			height = a;
			weight = b;
			if(s2)
			{
				strcpy(color,s2);
			}
		}
		void show_breed()
		{
			cout<<breed<<endl;
		}
};
class spotted_dog:public Dog{
	protected:
		char spot[80];
	public:
		spotted_dog(char *s1=NULL,int a=0,int b=0,char *s2=NULL,char *s3=NULL):Dog(s1,a,b,s2)
		{
			if(s3)
				strcpy(spot,s3);
		}
		void spot_info()
		{
			cout<<spot<<endl;
		}	
};
class unspotted_dog:public Dog{
	public:
		unspotted_dog(char *s1=NULL,int a=0,int b=0,char *s2=NULL):Dog(s1,a,b,s2){}
};
int main()
{
	spotted_dog redSpot("Dalmatian",24,60,"white","red");
	unspotted_dog rover("Labrador Retriever",30,40,"yellow");
	redSpot.show_breed();
	redSpot.spot_info();
	rover.show_breed();
	return 0;
}
