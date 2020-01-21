#include <iostream>
using namespace std;

typedef struct DIR{
	int r,c;
};
DIR dir[4]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,dp[21][21],ans;
string str[21];
bool check[26];

void dfs(int r,int c,int cnt){
	ans=max(ans,cnt);
	for(int i=0;i<4;i++){
		int nr=r+dir[i].r;
		int nc=c+dir[i].c;
		if(0<=nr&&nr<n&&0<=nc&&nc<m&&!check[(int)str[nr][nc]-'A']){
			check[(int)str[nr][nc]-'A']=true;
			dfs(nr,nc,cnt+1);
			check[(int)str[nr][nc]-'A']=false;
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	check[(int)str[0][0]-'A']=1;
	dfs(0,0,1);
	cout<<ans;
}
