#include <iostream>
using namespace std;
int n,arr[100][100];
long long dp[100][100];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dp[i][j]==0||(arr[i][j]==0)){
				continue;
			}
			int cnt=arr[i][j];
			if(i+cnt<n){
				dp[i+cnt][j]+=dp[i][j];
			}
			if(j+cnt<n){
				dp[i][j+cnt]+=dp[i][j];
			}
		}
	}
	cout<<dp[n-1][n-1];
}
