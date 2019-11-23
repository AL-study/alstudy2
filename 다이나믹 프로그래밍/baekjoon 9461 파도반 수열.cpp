#include <iostream>
using namespace std;
int t,n;
long long dp[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	dp[4]=2;
	dp[5]=2;
	for(int i=6;i<=100;i++){
		dp[i]=dp[i-1]+dp[i-5];
	}
	for(int i=0;i<t;i++){
		cin>>n;
		cout<<dp[n]<<"\n";
	}
} 
