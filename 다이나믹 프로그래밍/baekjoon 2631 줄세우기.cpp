#include <iostream>

using namespace std;
int n,arr[201],dp[201],cnt;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		cnt=max(cnt,dp[i]);
	}
	cout<<n-cnt;
}
