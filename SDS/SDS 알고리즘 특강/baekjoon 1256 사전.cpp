#include <iostream>
using namespace std;

double dp[202][202];

void solve(long long n,long long m,long long k){
	if(!n&&!m){
		return;
	}
	double num=dp[n+m-1][m];
	if(k>num){
		cout<<"z";
		solve(n,m-1,k-num);
	}else{
		cout<<"a";
		solve(n-1,m,k);
	}
}

int main(){
	long long n,m,k;
	cin>>n>>m>>k;
	long long nm=n+m;
	for(int i=0;i<=nm;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<=nm;i++){
		for(int j=1;j<=nm;j++){
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
		}
	}

	if(k>dp[n+m][n]){
		cout<<-1;
		return 0;
	}

	solve(n,m,k);
}
