#include<iostream>
using namespace std;
struct ExtEuc
{
	int d;
	int s;
	int t;
};
ExtEuc ExtEuclid(int,int);
int modinverse(int,int);
int main()
{
	ExtEuc eu;
	int a,b;
	cout<<"Please input two integers:";
	cin>>a>>b;
	eu = ExtEuclid(a,b);
	cout<<"d="<<eu.d<<" "<<"s="<<eu.s<<" "<<"t="<<eu.t<<endl;
	modinverse(a,b);
	return 0;
}
ExtEuc ExtEuclid(int a,int b)
{
	ExtEuc eu,eu1;
	if(b==0)
	{
		eu1.d = a;
		eu1.s = 1;
		eu1.t = 0;
		return eu1;
	}
	eu1=ExtEuclid(b,a%b);
	eu.d=eu1.d;
	eu.s=eu1.t;
	eu.t=eu1.s-(a/b)*eu1.t;
	cout<<"a="<<a<<" "<<"b="<<b<<" "<<"a/b="<<a/b<<" "<<"d="<<eu.d<<" "<<"s="<<eu.s<<" "<<"t="<<eu.t<<endl;
	return eu;
}
int modinverse(int a, int b)
{
	int temp,q,t1,t2,t3;
	int swap=0;
	int x1,x2,x3,y1,y2,y3;
	if(a<b)
	{
		swap=1;
		temp=a;
		a=b;
		b=temp;
	}
	x1=1;x2=0;x3=a;
	y1=0;y2=1;y3=b;
	while(y3!=0)
	{
		q=x3/y3;
		t1=x1-q*y1;t2=x2-q*y2;t3=x3-q*y3;
		x1=y1;x2=y2;x3=y3;
		y1=t1;y2=t2;y3=t3;
		cout<<"t1="<<t1<<" "<<"t2="<<t2<<" "<<"t3="<<t3<<endl;
	}
	if(x3==1)
	{
		if(swap==1)
		{
			cout<<"inverse of "<<b<<" "<<"mod "<<a<<" "<<"is:"<<x2<<endl;
			cout<<"inverse of "<<a<<" "<<"mod "<<b<<" "<<"is:"<<x1<<endl;
		}
	else
		{
		cout<<"inverse of "<<a<<" "<<"mod "<<b<<" "<<"is:"<<x2<<endl;
		cout<<"inverse of "<<b<<" "<<"mod "<<a<<" "<<"is:"<<x1<<endl;
		}
    }
	else
	{
		cout<<"no inverse"<<endl;
		return 0;
	}
}

