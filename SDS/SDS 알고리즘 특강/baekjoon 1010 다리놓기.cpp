#include <iostream>
using namespace std;

int dp[31][31],n,m,t;

int main(){
	for(int i=1;i<=30;i++){
		dp[1][i]=i;
	}
	for(int i=2;i<=30;i++){
		for(int j=i;j<=30;j++){
			for(int k=i-1;k<=j-1;k++){
				dp[i][j]+=dp[i-1][k];
			}
		}
	}
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m;
		cout<<dp[n][m]<<"\n";
	}
}
