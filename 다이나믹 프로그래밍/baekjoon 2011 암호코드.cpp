#include <iostream>
using namespace std;
string str;
int dp[5010];
int main(){
	cin>>str;
	dp[0]=1;
	for(int i=1;i<=str.length();i++){
		int x=str[i-1]-'0';
		if(1<=x && x<=9){
			dp[i]=dp[i-1]%1000000;
		}
		if(i==1)continue;
		int y=(str[i-2]-'0')*10+(str[i-1]-'0');
		if(10<=y && y<=26){
			dp[i]=(dp[i]+dp[i-2])%1000000;
		}
	}
	cout<<dp[str.length()];	
}
