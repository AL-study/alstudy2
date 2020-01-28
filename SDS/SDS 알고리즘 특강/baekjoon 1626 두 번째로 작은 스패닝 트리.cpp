#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#define LOG 21
#define MAX 50001
using namespace std;

typedef struct EDGE{
	int from,to,dist;
};

bool ismst[200020];
vector<EDGE> v;
vector<pair<int, int > > mstv[200020];
int n,m,result,mstcost,d[MAX],parent[MAX],cost[MAX][LOG],par[MAX][LOG];
long long ans=INT_MAX;


bool compare(EDGE a, EDGE b){
	return a.dist<b.dist;
}

int getparent(int x){
	if(parent[x]==x)return x;
	return parent[x]=getparent(parent[x]);
}

void unionparent(int x,int y){
	x=getparent(x);
	y=getparent(y);
	if(x<y){
		parent[y]=x;
	}else{
		parent[x]=y;
	}
}
bool findunion(int x,int y){
	x=getparent(x);
	y=getparent(y);
	if(x==y){
		return true;
	}else{
		return false;
	}
}

int mst(){
	int cnt=0;
	int ret=0;
	for(int i=0;i<m;i++){
		if(!findunion(v[i].from,v[i].to)){
			unionparent(v[i].from,v[i].to);
			mstv[v[i].from].push_back({v[i].dist,v[i].to});
			mstv[v[i].to].push_back({v[i].dist,v[i].from});
			ismst[i]=true;
			ret+=v[i].dist;
			cnt++;	 
		}
		if(cnt==n-1) return ret; //종료 조건  
	}
	return -1;
}

void dfs(int here){
	for(int i=0;i<mstv[here].size();i++){
		int next=mstv[here][i].second;
		if(d[next]!=-1)continue;
		d[next]=d[here]+1;
		par[next][0]=here;
		cost[next][0]=mstv[here][i].first;
		dfs(next);
	}
}

void setparent(){
	dfs(1);
	for(int j=1;j<LOG;j++){
		for(int i=1;i<=n;i++){
			par[i][j]=par[par[i][j-1]][j-1];
			cost[i][j]=max(cost[par[i][j-1]][j-1],cost[i][j-1]);
		}
	}
}


int second_max(int x,int y, int dist){
	int ret=0;
	if(y==0)return 0;
	if(cost[x][y-1]==dist) ret=max(ret,second_max(x,y-1,dist));
	else ret=max(ret,cost[x][y-1]);
	if(cost[par[x][y-1]][y-1]==dist) ret=max(ret,second_max(par[x][y-1],y-1,dist));
	else ret=max(ret,cost[par[x][y-1]][y-1]);
	return ret;
}

int lca_max(int x, int y, int dist){
	if(d[x]>d[y]) swap(x,y);
	int maxnum=0;
	if(d[x]!=d[y]){
		for(int i=LOG-1;i>=0;i--){
			if(d[y]-d[x]>=(1<<i)){
				if(cost[y][i]==dist)maxnum=max(maxnum,second_max(y,i,dist));
				else maxnum=max(maxnum,cost[y][i]);
				y=par[y][i];
			}
		}
	}
	if(x==y)return maxnum;
	for(int i=LOG-1;i>=0;i--){
		if(par[x][i]!=-1&&par[x][i]!=par[y][i]){
			if(cost[y][i]==dist) maxnum=max(maxnum,second_max(y,i,dist));
			else maxnum=max(maxnum,cost[y][i]);
			if(cost[x][i]==dist) maxnum=max(maxnum,second_max(x,i,dist));
			else maxnum=max(maxnum,cost[x][i]);
			x=par[x][i];
			y=par[y][i];
		}
	}
	if(cost[x][0]<dist)maxnum=max(maxnum,cost[x][0]);
	if(cost[y][0]<dist)maxnum=max(maxnum,cost[y][0]);
	return maxnum;
}



int main(){
	cin>>n>>m;
	memset(d,-1,sizeof(d));
	
	for(int i=1;i<=n;i++){
		parent[i]=i;
		for(int j=0;j<LOG;j++){
			par[i][j]=-1;
		}
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v.push_back({a,b,c});
	}
	sort(v.begin(),v.end(),compare);
	
	mstcost=mst();
	if(mstcost==-1||m<=n-1){
		cout<<-1;
		return 0;
	}
	d[1]=0;
	par[1][0]=0;
	cost[1][0]=0;
	setparent();
	
	for(int i=0;i<m;i++){
		if(ismst[i])continue;
		
		int dist=v[i].dist, from=v[i].from, to=v[i].to;
		int getmax=lca_max(from,to,dist);
		ans=min(ans,(long long)(mstcost+dist-getmax));
		
	}
	if(ans==mstcost||ans==INT_MAX){
		cout<<-1;
	}else{
		cout<<ans;
	}
	
}
