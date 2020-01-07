#include <iostream>
#include <cstring>
using namespace std;

int n,m,dp[51][51],ans;
string str[51];
bool flag;
bool check[51][51];
typedef struct DIR{
	int r,c;
};
DIR dir[4]={{1,0},{-1,0},{0,1},{0,-1}};
int dfs(int r,int c){
	if(r<0||n<=r||c<0||m<=c){
		return 0;
	}
	if(str[r][c]=='H'){
		return 0;
	}
	if(check[r][c]){
		cout<<-1;
		exit(0);
	}
	int& ret=dp[r][c];
	if(ret!=-1){
		return ret;
	}
	check[r][c]=true;
	int num=(int)str[r][c]-(int)'0';
	for(int i=0;i<4;i++){
		int rr=r+num*dir[i].r;
		int cc=c+num*dir[i].c;
		ret=max(ret,dfs(rr,cc)+1);
	}
	check[r][c]=false;
	return ret;
}

int main(){
	cin>>n>>m;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	cout<<dfs(0,0);
}
