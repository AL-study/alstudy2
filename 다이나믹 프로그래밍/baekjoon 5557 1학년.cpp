#include <iostream>
using namespace std;
int n,arr[101];
long long dp[101][21];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dp[1][arr[1]]++;
	for(int i=2;i<n;i++){
		for(int j=0;j<=20;j++){
			if(dp[i-1][j]){
				if(j+arr[i]<=20&&0<=j+arr[i]){
					dp[i][j+arr[i]]+=dp[i-1][j];
				}
				if(j-arr[i]<=20&&0<=j-arr[i]){
					dp[i][j-arr[i]]+=dp[i-1][j];
				}
			}
		}
	}
	cout<<dp[n-1][arr[n]];
}
