#include <iostream>
using namespace std;
int t,n,arr[21],money;
int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>arr[j];
		}
		cin>>money;
		int dp[10001]={0};
		dp[0]=1;
		for(int j=1;j<=n;j++){
			for(int k=arr[j];k<=money;k++){
				dp[k]+=dp[k-arr[j]];
			}
		}
		cout<<dp[money]<<"\n";
	}
}

