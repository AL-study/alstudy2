#include <iostream>
using namespace std;
int arr1[2],arr2[2],ans[2];

int gcd(int a, int b){
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
	cin>>arr1[0]>>arr1[1];
	cin>>arr2[0]>>arr2[1];
	ans[0]=arr1[0]*arr2[1]+arr2[0]*arr1[1];
	ans[1]=arr1[1]*arr2[1];
	int gcdnum=gcd(ans[0],ans[1]);
	cout<<ans[0]/gcdnum<<" "<<ans[1]/gcdnum;
	return 0;
}
