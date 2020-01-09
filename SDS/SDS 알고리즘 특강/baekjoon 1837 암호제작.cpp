#include <iostream>
#include <cmath>
using namespace std;

string pq;
int p,k;
bool c[1000001];

int main(){
	for(int i=2;i<=sqrt(1000000);i++){
		if(c[i])continue;
		for(int j=i*2;j<=1000000;j+=i){
			c[j]=true;
		}
	}
	cin>>pq>>k;
	for(int i=2;i<=1000000;i++){
		if(i>=k)break;
		if(c[i])continue;
		int num=0;
		for(int j=0;j<pq.length();j++){
			num*=10;
			num+=(int)pq[j]-'0';
			num%=i;	
		}
		if(num==0){
			p=i;
			cout<<"BAD "<<p;
			return 0;
		}
	}
	cout<<"GOOD";
	
	
}
