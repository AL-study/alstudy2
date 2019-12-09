#include <iostream>
using namespace std;
int n,s,m,arr[101],ans=-1;
bool dp[101][1001];
int main(){
	cin>>n>>s>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dp[0][s]=true;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=1000;j++){
			if(dp[i-1][j]){
				if(j+arr[i]<=m)dp[i][j+arr[i]]=true;
				if(j-arr[i]>=0)dp[i][j-arr[i]]=true;
			}
		}
	}
	for(int j=1000;j>=0;j--){
		if(dp[n][j]){
			ans=j;
			break;
		}
	}
	cout<<ans;
}
