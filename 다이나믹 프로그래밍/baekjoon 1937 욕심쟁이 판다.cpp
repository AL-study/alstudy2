#include <iostream>
using namespace std;
int n,dp[501][501],arr[501][501],ans;
typedef struct DIR{
	int r,c;
}DIR;
DIR dir[4]={{1,0},{-1,0},{0,1},{0,-1}};
int dfs(int r,int c){
	if(dp[r][c]){
		return dp[r][c];
	}
	dp[r][c]=1;
	for(int i=0;i<4;i++){
		int mr=r+dir[i].r;
		int mc=c+dir[i].c;
		if(0<=mr&&mr<n&&0<=mc&&mc<n){
			if(arr[r][c]<arr[mr][mc]){
				dp[r][c]=max(dp[r][c],dfs(mr,mc)+1);
			}		
		}
	}
	return dp[r][c];
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans=max(ans,dfs(i,j));
		}
	}
	cout<<ans;
} 
