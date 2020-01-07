#include <iostream>
using namespace std;
int n,m,arr[10000],s,e,sum,ans;
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
		if(sum==m){
			ans++;
		}
		
	}
	cout<<ans;
}
