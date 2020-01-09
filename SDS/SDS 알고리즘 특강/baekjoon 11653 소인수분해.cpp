#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int n;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	while(1){
		for(int i=2;i<=10000000;i++){
			if(n<i)return 0;
			if(n%i==0){
				n/=i;
				cout<<i<<"\n";
				break;
			}
		}
	}
	
}
