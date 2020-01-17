#include <iostream>
using namespace std;

string a,b;
string dp[1001][1001];

int main(){
	cin>>a>>b;
	for(int i=0;i<a.length();i++){
		for(int j=0;j<b.length();j++){
			if(a[i]==b[j]){
				dp[i+1][j+1]=dp[i][j]+b[j];
			}else{
				if(dp[i+1][j].length()>dp[i][j+1].length()){
					dp[i+1][j+1]=dp[i+1][j];
				}else{
					dp[i+1][j+1]=dp[i][j+1];
				}
			}
		}
	}
	cout<<dp[a.length()][b.length()].length()<<"\n";
	cout<<dp[a.length()][b.length()];
}
