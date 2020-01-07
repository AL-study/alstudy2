#include <iostream>
using namespace std;

int s,e,n,arr[100000],m,sum,ans=987654321;

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	while(1){
		if(sum>=m){
			sum-=arr[s++];
		}else if(n==e){
			break;
		}else{
			sum+=arr[e++];
		}
		if(sum>=m){
			ans=min(ans,e-s);
		}
	}
	
	if(ans==987654321){
		cout<<0;
	}else{
		cout<<ans;
	}
	
	
}
