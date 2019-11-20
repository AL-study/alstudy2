#include <iostream>

using namespace std;
int n,m,arr[500][500],dp[500][500];
typedef struct DIR{
	int r,c;
}DIR;
DIR dir[4]={{1,0},{0,-1},{-1,0},{0,1}};
int dfs(int r,int c){
	if(r==0&&c==0){
		return 1;
	}
	if(dp[r][c]==-1){
		dp[r][c]=0;
		for(int i=0;i<4;i++){
			int mr=dir[i].r+r;
			int mc=dir[i].c+c;
			if(0<=mr&&mr<n&&0<=mc&&mc<m){
				if(arr[r][c]<arr[mr][mc]){
					dp[r][c]+=dfs(mr,mc);
				}	
			}
		}
	}
	return dp[r][c];
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			dp[i][j]=-1;
		}
	}
	cout<<dfs(n-1,m-1);
}

