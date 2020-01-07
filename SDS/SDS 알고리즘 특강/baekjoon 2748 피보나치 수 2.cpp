#include <iostream>
using namespace std;

long long dp[91],n;
int main(){
	cin >>n;
	dp[1]=1;
	for(int i=2;i<=90;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	cout<<dp[n];
}
