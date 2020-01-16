#include <iostream>
using namespace std;

int n,arr[501][2],dp[501][501];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i][0]>>arr[i][1];
	}
	for(int i=1;i<=n-1;i++){
		dp[i][i+1]=arr[i][0]*arr[i][1]*arr[i+1][1];
	}
	for(int l=2;l<=n;l++){
		for(int i=1;i<=n-l;i++){
			int j=i+l;
			for(int k=i;k<j;k++){
				int num=dp[i][k]+dp[k+1][j]+arr[i][0]*arr[k][1]*arr[j][1];
				if(dp[i][j]==0||num<dp[i][j]){
					dp[i][j]=num;
				}
			}
		}
	}
	cout<<dp[1][n];
}
