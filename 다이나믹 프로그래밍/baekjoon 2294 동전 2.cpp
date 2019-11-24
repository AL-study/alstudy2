#include <iostream>
using namespace std;
int n,k,dp[100001],arr[101];
int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		dp[i]=1000000;
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		dp[arr[i]]=1;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(i-arr[j]>=1){
				dp[i]=min(dp[i],dp[i-arr[j]]+1);
			}	
		}
	}
	if(dp[k]==1000000){
		cout<<-1;
	}else{
		cout<<dp[k];
	}
}
