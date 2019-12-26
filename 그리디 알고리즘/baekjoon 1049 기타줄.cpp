#include <iostream>
using namespace std;
int n,m,minpack=10000,minpiece=10000,num;

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int pack,piece;
		cin>>pack>>piece;
		minpack=min(minpack,pack);
		minpiece=min(minpiece,piece);
	}
	if(minpack>6*minpiece){
		cout<<n*minpiece;
	}else{
		if(n/6){
			num=(n/6)*minpack;
			n%=6;
		}
		if(minpack>n*minpiece){
			num+=n*minpiece;
		}else{
			num+=minpack;
		}
		cout<<num;
	}
}
