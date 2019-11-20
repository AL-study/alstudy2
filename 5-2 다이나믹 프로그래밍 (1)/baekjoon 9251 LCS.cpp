#include <iostream>
using namespace std;
string a,b;
int arr1[1001],arr2[1001],ans;
int dp[1001][1001];
int main(){
	cin>>a>>b;
	for(int i=0;i<a.length();i++){
		for(int j=0;j<b.length();j++){
			if(a[i]==b[j]){
				dp[i+1][j+1]=dp[i][j]+1;
			}else{
				dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
			}
		}
	}

//CAPCAK
//ACAYKP
//	cout<<"\n";
//	for(int i=0;i<=a.length();i++){
//		for(int j=0;j<=b.length();j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	cout<<dp[a.length()][b.length()];
}
