#include <iostream>
#include <vector>
using namespace std;


int n,m,dis[10001],num,ans;
vector<int> v[10001];
bool cut[10001];


int dfs(int start,bool isroot){
	
	dis[start]=++num;
	int ret=dis[start];
	int child=0;
	for(int i=0;i<v[start].size();i++){
		
		int next=v[start][i];
		
		if(dis[next]){
			ret=min(ret,dis[next]);
			continue;
		}
		child++;
		int prev=dfs(next,false);
		
		if(!isroot&&prev>=dis[start]){
			cut[start]=true;
		}
		ret=min(ret,prev);
	}
	
	if(isroot){
		cut[start]=(child>=2);
	}
	return ret;
	
	
	
}

int main(){
	
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(dis[i]){
			continue;
		}
		dfs(i,true);
	}
	for(int i=1;i<=n;i++){
		if(cut[i])ans++;
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++){
		if(cut[i])cout<<i<<" ";
	}
	
}
