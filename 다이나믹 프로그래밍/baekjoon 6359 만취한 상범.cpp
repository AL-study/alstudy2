#include <iostream>
#include <cstring>
using namespace std;
int t,n;
bool dp[101];
int main(){
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		int ans=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j+=i){
				dp[j]=!dp[j];	
			}
		}
		for(int i=1;i<=n;i++){
			if(dp[i])ans++;
		}
		cout<<ans<<"\n";
	}
}
