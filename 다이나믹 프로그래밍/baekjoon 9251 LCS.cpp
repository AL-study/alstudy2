#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001][1001];
string a,b;
int main(){
	cin>>a>>b;
	if(a[0]==b[0]) dp[0][0]=1;
	for(int i=1;i<a.length();i++){
		if(a[i]==b[0]||dp[0][i-1]==1) dp[0][i]=1;
	}
	for(int i=1;i<b.length();i++){
		if(b[i]==a[0]||dp[i-1][0]==1) dp[i][0]=1;
	}
	for(int i=1;i<b.length();i++){
		for(int j=1;j<a.length();j++){
			if(b[i]==a[j]){
				dp[i][j]=dp[i-1][j-1]+1;
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[b.length()-1][a.length()-1];
}
