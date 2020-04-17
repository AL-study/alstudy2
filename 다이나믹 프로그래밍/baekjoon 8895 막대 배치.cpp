#include <iostream>
using namespace std;
int N,R,L,T;
long long dp[21][21][21];
int main(){
	dp[1][1][1]=1;
	for(int n=2;n<=20;n++)
		for(int l=1;l<=20;l++)		
			for(int r=1;r<=20;r++)
				dp[n][l][r]=dp[n-1][l-1][r]+dp[n-1][l][r-1]+(n-2)*dp[n-1][l][r];
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>N>>L>>R;
		cout<<dp[N][L][R]<<"\n";
	}
}
