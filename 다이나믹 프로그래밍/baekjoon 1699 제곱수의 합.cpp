#include <iostream>
using namespace std;
int n,dp[100001];

int main(){
	cin>>n;
	for(int i=0;i<=100000;i++){
		dp[i]=100000;
	}
	for(int i=1;i<=100000;i++){
		if(i*i<=100000){
			dp[i*i]=1;
		}else{
			break;
		}
	}
	for(int i=1;i<=100000;i++){
		for(int j=1;j<=10000;j++){
			if(i-j*j>=1){
				dp[i]=min(dp[i],dp[i-j*j]+1);
			}else{
				break;
			}
		}
	}
	cout<<dp[n];
}

