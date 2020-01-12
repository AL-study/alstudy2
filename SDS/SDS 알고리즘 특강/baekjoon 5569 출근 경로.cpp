#include <iostream>
using namespace std;
int dp[101][101][2][2],x,y;
int main(){
	cin>>x>>y;
	for(int i=2;i<=x;i++){
		dp[i][1][0][0] = 1;
	} 
	for(int i=2;i<=y;i++){
		dp[1][i][1][0] = 1;
	} 
	for(int i=2;i<=x;i++){
		for(int j=2;j<=y;j++){
			dp[i][j][0][0]=(dp[i-1][j][0][1]+dp[i-1][j][0][0])%100000;
			dp[i][j][0][1]=dp[i-1][j][1][0];
			dp[i][j][1][0]=(dp[i][j-1][1][0]+dp[i][j-1][1][1])%100000;
			dp[i][j][1][1]=dp[i][j-1][0][0];
		}
	}
	int ans=0;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			ans+=dp[x][y][i][j];
		}
	}
	cout<<ans%100000;
}
