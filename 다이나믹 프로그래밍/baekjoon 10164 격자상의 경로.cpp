#include <iostream>
using namespace std;
int n,m,k,dp[16][16],r=1,c=1;
int main(){
	cin>>n>>m>>k;
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cnt++;
			if(cnt==k){
				r=i;
				c=j;
			}
		}
	}
	dp[1][1]=1;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(i==1&&j==1) continue;
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	for(int i=r;i<=n;i++){
		for(int j=c;j<=m;j++){
			if(i==r&&j==c) continue;
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	cout<<dp[n][m];
}
