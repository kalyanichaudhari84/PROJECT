#include <iostream>
using namespace std;
struct Point
{
	double x;
	double y;
};

float position(Point **building,float *w,float *h,Point p,int n) //position of source p
{
	float len,w1,h1;
	for(int i=0;i<n;i++)
	{
		for(int  j=0;j<4;j++)
		{
			if(p.x <building[i][j].x && p.y<building[i][j].y)
			{
				w1=w[i];
				h1=h[i];
				len=w1+h1;
			}
			else if( p.x <building[i][j].x && p.y<building[i][j].y&&p.y>building[i][1].y )
			{
				h1=h[i];
				len=h1;
			}
			else if(p.x <building[i][j].x && p.y>building[i][j].y)
			{
				w1=w[i];
				h1=h[i];
				len=w1+h1;
			}
			else if( p.x >building[i][1].x && p.y>building[i][1].y&&p.y>building[i][2].y )
			{
				len=w[i];
			}
			else if(p.x >building[i][2].x && p.y>building[i][3].y)
			{
				len=w[i]+h[i];
			}
			else if( p.x >building[i][4].x && p.y>building[i][3].y&&p.y<building[i][2].y )
			{
				len=h[1];
			}
			else if(p.x >building[i][3].x && p.y<building[i][3].y)
			{
				len=w[i]+h[i];
			}
			else if( p.x >building[i][0].x && p.x>building[i][3].x&&p.y<building[i][0].y )
			{
				len=w[1];
			}
		}
	}
	return len;
}
float countLen(Point **building,Point p,int n)
{
	float w[n],h[n],temp,len; //store height and weight of building.
	w[0]=0.0;
	h[0]=0.0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
		{ temp=0.0;
		 temp=building[i][j].x-building[i][j+1].x;
		 w[i]= max(w[i],temp); //maximum weigh value of building
		 temp=0.0;
		 temp=building[i][j].y-building[i][j+1].y;
		 h[i]=max(h[i],temp); //maximum height value of building
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<w[i]<<"\t";
		cout<<h[i]<<"\t";
	}
	len=position(building,w,h,p,n);
	return len;
}
int main()
{
	int n;
	struct Point p;
	cout<<"Enter the number of buildings"<<endl;
	cin>>n;
	struct Point **building1=new struct Point *[n];
	for(int i=0;i<n;i++)
	{
		building1[i]= new struct Point [n];
	}
	for(int i=0;i<n;i++)
	{
		cout<<"Enter "<<i+1<<"th building coordinates"<<endl;
		for(int j=0;j<4;j++)
		{
			cout<<"Enter X coordinate of "<<j+1<<"point of building"<<endl;
			cin>>building1[i][j].x;
			cout<<"Enter Y coordinate of "<<j+1<<"point of building"<<endl;
			cin>>building1[i][j].y;
		}
	}
	cout<<"Enter the source point"<<endl;
	cout<<"Enter the X coordinate of source"<<endl;
	cin>>p.x;
	cout<<"Enter the Y coordinate of source"<<endl;
	cin>>p.y;
	float length=countLen(building1,p,n);
	cout<<"Length= "<<length<<endl;
	return 0;
}
