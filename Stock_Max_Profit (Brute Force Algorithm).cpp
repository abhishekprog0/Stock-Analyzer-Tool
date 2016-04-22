#include<iostream>
#include<algorithm>
using namespace std;
int RatingCalculator(long int [],int,long int);
int main()
{
	long int n, bigall=-100000000,big1=-100000000,db1=-1,ds1=-1,dball=-1,dsall=-1,b,s,k,i,j,flag=0;
	cout<<"Enter the no. of Stock Buying/Selling days starting from September 1st: ";
	cin>>n;
	cout<<endl;
	long int a[n];
	cout<<"Enter the prices of Stock per share for "<<n<<" days: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"September "<<i+1<<" : $";
		cin>>a[i];
	}
	for(i=0;i<n-1;i++)
	{
		big1=-100000000;
		for(j=i+1;j<n;j++)
		{
			if(a[j]-a[i]>big1)
			{
				big1=a[j]-a[i];
				db1=i;
				ds1=j;
			}
			if(big1>bigall)
			{
				b=a[i];
				s=a[j];
				dball=db1+1;
				dsall=ds1+1;
				bigall=big1;
			}
		}
	}
	if(bigall>0)
		flag=1;
	else
		flag=0;
	if(flag==1)
	{
		cout<<endl<<endl<<"Loading Strategy for maximizing profit....."<<endl<<endl;
		cout<<"Buy shares of $"<<b<<" on "<<dball<<"/9/15 and sell for $"<<s<<" on "<<dsall<<"/9/15."<<endl;
		cout<<"Maxiumum Profit earned: "<<bigall<<endl<<endl;
	}
	else
	{
		cout<<endl<<endl<<"Sorry, I think maybe you should not invest your money on shares this month !!!"<<endl<<endl;
	}
	RatingCalculator(a,n,bigall);
}
int RatingCalculator(long int a[],int n,long int bigall)
{
	long int b[n],min=1000000000,pos=-1;
	for(int i=0;i<n;i++)
	{
		b[i]=a[i];
	}
	//Sort Array a[]
	sort(b,b+n);
	for(int i=0;i<n;i++)
	{
		if(abs(b[i]-bigall)<min)
		{
			min=abs(b[i]-bigall);
			pos=i;
		}
	}
	float g=float(pos*10)/(n);
	float Rating=float(1 + g);
	if(Rating>=10)
		Rating--;
	cout<<"Company Rating: "<<Rating<<endl;
	return 0;
}



