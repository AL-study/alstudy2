#include <iostream>
using namespace std;
int n,dp[21],t[21],p[21];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>p[i];
		dp[i]=p[i];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(t[j]+j<=i){
				dp[i]=max(dp[i],p[i]+dp[j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(t[i]+i<=n+1){
			ans=max(ans,dp[i]);
		}
	}
	cout<<ans;
} 
