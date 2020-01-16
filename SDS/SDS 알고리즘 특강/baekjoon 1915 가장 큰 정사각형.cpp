#include <iostream>
#include <algorithm>
using namespace std;

int n,m,dp[1001][1001],ans;
string str[1001];

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dp[i][j]=(int)str[i][j]-'0';
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(dp[i][j]==0)continue;
			int num= min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1});
			dp[i][j]=max(num,dp[i][j]);
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans*ans;	
}
