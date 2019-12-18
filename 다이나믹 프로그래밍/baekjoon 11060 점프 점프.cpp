#include <iostream>
using namespace std;
int n,arr[1001],dp[1001];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		dp[i]=1000000;
	}
	dp[0]=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<=arr[i];j++){
			dp[i+j]=min(dp[i+j],dp[i]+1);
		}
	}
	if(dp[n-1]==1000000){
		cout<<-1;
	}else{
		cout<<dp[n-1];
	}
}
