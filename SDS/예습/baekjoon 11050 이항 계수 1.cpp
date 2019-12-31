#include <iostream>
using namespace std;

int n,k;
int main() {
	cin>>n>>k;
	int num1=1;
	int num2=1;
	for(int i=n;i>0;i--){
		num1*=i;
	}
	for(int i=k;i>0;i--){
		num2*=i;
	}
	for(int i=n-k;i>0;i--){
		num2*=i;
	}
	cout<<num1/num2;
}

