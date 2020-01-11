#include <iostream>
using namespace std;

int dp[11][11],n,k;

int main(){
	cin>>n>>k;
	for(int i=0;i<=n;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
		}
	}
	cout<<dp[n][k];
}
