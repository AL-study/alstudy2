#include <iostream>
#include <cmath>
using namespace std;

int n;

int main(){
	while(1){
		cin>>n;
		if(cin.eof()){
			break;
		}
		int num=11;
		int cnt=1;
		while(1){
			if(n==1){
				cout<<1<<"\n";
				break;
			}
			cnt++;
			if(num%n==0){
				cout<<cnt<<"\n";
				break;
			}else{
				num=(num%n)*10+1;
			}	
		}
	}
}
