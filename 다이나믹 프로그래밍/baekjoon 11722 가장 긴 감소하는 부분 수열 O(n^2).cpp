#include <iostream>
using namespace std;
int n,arr[1001],dp[1001],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(arr[i]<arr[j]){
				if(dp[i]<dp[j]+1){
					dp[i]=dp[j]+1;
				}
			}
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
}
