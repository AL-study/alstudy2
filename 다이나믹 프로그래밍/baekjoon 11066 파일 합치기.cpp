#include <iostream>
#include <climits>
using namespace std;
int t,n,dp[501][501],arr[501],sum[501];
int main(){
	cin>>t;
	for(int l=0;l<t;l++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			sum[i]=sum[i-1]+arr[i];
		}
		for(int k=1;k<n;k++){
			for(int i=1;i+k<=n;i++){
				int j=i+k;
				dp[i][j]=INT_MAX;
				for(int mid=i;mid<j;mid++){
					dp[i][j]=min(dp[i][j],dp[i][mid]+dp[mid+1][j]+sum[j]-sum[i-1]);
				}
			}
		}
		cout<<dp[1][n]<<"\n";
	}
} 
