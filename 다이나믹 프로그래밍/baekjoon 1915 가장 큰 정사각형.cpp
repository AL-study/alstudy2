#include <iostream>
using namespace std;
int n,m,dp[1001][1001],arr[1001][1001],ans;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string temp="";
		cin>>temp;
		for(int j=1;j<=m;j++){
			arr[i][j]=temp[j-1]-48;
			dp[i][j]=arr[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dp[i][j]==0)continue;
			int num=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
			dp[i][j]=max(num+1,dp[i][j]);
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans*ans;
}
