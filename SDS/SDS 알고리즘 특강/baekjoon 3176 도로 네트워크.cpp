#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
#define LOG 21
using namespace std;

int n,m,parent[MAX][LOG],d[MAX],maxdp[MAX][LOG],mindp[MAX][LOG];
bool c[MAX];
vector<pair<int,int> > v[MAX];

void dfs(int x, int depth){
	c[x]=true;
	d[x]=depth;
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i].first;
		if(c[y])continue;
		parent[y][0]=x;
		maxdp[y][0]=v[x][i].second;
		mindp[y][0]=v[x][i].second;
		dfs(y,depth+1);
	}
}

void setparent(){
	dfs(1,0);
	for(int j=1;j<LOG;j++){
		for(int i=1;i<=n;i++){
			parent[i][j]=parent[parent[i][j-1]][j-1];
			maxdp[i][j]=max(maxdp[i][j-1],maxdp[parent[i][j-1]][j-1]);
			mindp[i][j]=min(mindp[i][j-1],mindp[parent[i][j-1]][j-1]);
		}
	}
}

void lca(int x,int y){
	int minnum=9876543221, maxnum=-1; 
	if(d[x]>d[y]){
		swap(x,y);
	}
	// 두 노드의 깊이를 동일하게 맞춘다
	for(int i=LOG-1;i>=0;i--){
		if(d[y]-d[x]>=(1<<i)){
			maxnum=max(maxnum,maxdp[y][i]);
			minnum=min(minnum,mindp[y][i]);
			y=parent[y][i];
		}
	} 
	if(x==y){
		cout<<minnum<<" "<<maxnum<<"\n";
		return;
	}
	for(int i=LOG-1;i>=0;i--){
		if(parent[x][i]!=parent[y][i]){
			maxnum=max(maxnum,max(maxdp[x][i],maxdp[y][i]));
			minnum=min(minnum,min(mindp[x][i],mindp[y][i]));
			x=parent[x][i];
			y=parent[y][i];
		}
	}
	maxnum=max(maxnum,max(maxdp[x][0],maxdp[y][0]));
	minnum=min(minnum,min(mindp[x][0],mindp[y][0]));
	cout<<minnum<<" "<<maxnum<<"\n";
	return;
	
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	setparent();
	cin>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		lca(a,b);
	}
	
}
