#include <iostream>
using namespace std;

int n,dp[501][501],arr[501][501];

int main(){
	
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>arr[i][j];
		}
	}
	dp[1][1]=arr[1][1];
	dp[2][1]=arr[2][1]+arr[1][1];
	dp[2][2]=arr[2][2]+arr[1][1];

	for(int i=3;i<=n;i++){
		dp[i][1]=dp[i-1][1]+arr[i][1];
		dp[i][i]=dp[i-1][i-1]+arr[i][i];
		for(int j=2;j<i;j++){
			dp[i][j]=max(dp[i-1][j-1]+arr[i][j],dp[i-1][j]+arr[i][j]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[n][i]);
	}
	cout<<ans;
	
}
