#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,num,dis[100001];
vector<int> v[100001];
vector<pair<int, int > > cut;


int dfs(int here, int parent){
	dis[here]=++num;
	int ret=dis[here];
	
	for(int i=0;i<v[here].size();i++){
		int next=v[here][i];
		
		if(next==parent){
			continue;
		}
		if(dis[next]){
			ret=min(ret,dis[next]);
			continue;
		}
		
		int prev=dfs(next,here);
		
		if(prev>dis[here]){
			cut.push_back({min(here,next),max(here,next)});
		}
		ret=min(ret,prev);
		
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
		if(dis[i])continue;
		dfs(i,0);
	}
	sort(cut.begin(),cut.end());
	
	cout<<cut.size()<<"\n";
	
	for(int i=0;i<cut.size();i++){
		cout<<cut[i].first<<" "<<cut[i].second<<"\n";
	}
	
}
