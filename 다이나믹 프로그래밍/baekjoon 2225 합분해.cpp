#include <iostream>
using namespace std;
int n,k,dp[201][201];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		dp[1][i]=1;
		dp[2][i]=i+1;
	}
	for(int i=0;i<=k;i++){
		dp[i][0]=1;
	}
	for(int i=3;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int l=0;l<=j;l++){
				dp[i][j]=(dp[i][j]+dp[i-1][l])%1000000000;
			}
		}
	}
	cout<<dp[k][n];
} 
