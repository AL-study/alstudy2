#include <iostream>
using namespace std;

int n,arr[101];
long long dp[101][21];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dp[1][arr[1]]=1;
	for(int i=2;i<=n;i++){
		int temp=arr[i];
		for(int j=0;j<=20;j++){
			if(0<=j-temp&&j-temp<=20){
				dp[i][j-temp]+=dp[i-1][j];
			}
			if(j+temp<=20&&j+temp>=0){
				dp[i][j+temp]+=dp[i-1][j];
			}
		}
	}
	cout<<dp[n-1][arr[n]];
}
