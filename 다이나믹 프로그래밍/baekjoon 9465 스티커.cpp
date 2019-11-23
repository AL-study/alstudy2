#include <iostream>
using namespace std;
int t,n,dp[3][100001],arr[3][100001];

int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			dp[1][j]=0;
			dp[2][j]=0;
		}
		for(int j=1;j<=n;j++){
			cin>>arr[1][j];
		}
		for(int j=1;j<=n;j++){
			cin>>arr[2][j];
		}
		dp[1][1]=arr[1][1];
		dp[2][1]=arr[2][1];
		dp[1][2]=dp[2][1]+arr[1][2];
		dp[2][2]=dp[1][1]+arr[2][2];
		for(int j=3;j<=n;j++){
			dp[1][j]=max(dp[2][j-2]+arr[1][j],dp[2][j-1]+arr[1][j]);
			dp[2][j]=max(dp[1][j-2]+arr[2][j],dp[1][j-1]+arr[2][j]);
		}
		cout<<max(dp[1][n],dp[2][n])<<"\n";
	}
}
