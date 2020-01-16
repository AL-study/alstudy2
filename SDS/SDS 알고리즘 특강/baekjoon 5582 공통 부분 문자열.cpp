#include <iostream>
using namespace std;

string a,b;
int dp[4001][4001],ans;
int main(){
	cin>>a>>b;
	for(int i=0;i<a.length();i++){
		for(int j=0;j<b.length();j++){
			if(a[i]==b[j]){
				dp[i+1][j+1]=dp[i][j]+1;
				ans=max(ans,dp[i+1][j+1]);
			}
		}
	}
	cout<<ans;
}
