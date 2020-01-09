#include <iostream>
using namespace std;

int ans;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(){
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int ans1,ans2;
	ans2=y1*y2;
	ans1=y2*x1+y1*x2;
	int gcdnum=gcd(ans1,ans2);
	cout<<ans1/gcdnum<<" "<<ans2/gcdnum;
}
