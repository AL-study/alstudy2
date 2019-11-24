#include <iostream>
using namespace std;
int n,m,dp[1001][1001],arr[1001][1001];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		dp[i][1]=arr[i][1];
	}
	for(int i=1;i<=m;i++){
		dp[1][i]=arr[1][i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=max(dp[i][j-1]+arr[i][j],dp[i-1][j]+arr[i][j]);
		}
	}
	cout<<dp[n][m];
}
