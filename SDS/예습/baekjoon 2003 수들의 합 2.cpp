#include <iostream>
using namespace std;
int n,arr[100000],m,ans;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int s=0,e=0,sum=0;;
	while(1){
		if(sum>=m){
			sum-=arr[s++];
		}else if(e==n){
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
