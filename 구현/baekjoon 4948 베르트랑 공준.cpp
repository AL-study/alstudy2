#include <iostream>
#include <math.h>
using namespace std;
int n;
bool num[300000];
int main(){
	for(int i=2;i<=sqrt(300000);i++){
		if(num[i]) continue;
		for(int j=i+i;j<=300000;j+=i){
			num[j]=true;
		}
	}
	while(true){
		cin>>n;
		if(!n) return 0;
		int cnt=0;
		for(int i=n+1;i<=n*2;i++){
			if(!num[i]) cnt++;
		}
		cout<<cnt<<"\n";
	}
}
