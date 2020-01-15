#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <limits.h>
using namespace std;


vector<pair<int, int> > v[501];
bool check[501][501];


vector<int> dijkstra(vector<int> trace[501], int start, int n, int m){
	
	vector<int> d(n,INT_MAX);
	d[start]=0;
	priority_queue<pair <int, int > > pq;
	pq.push({0,start});
	
	while(!pq.empty()){
		
		int cur=pq.top().second;
		int dist=-pq.top().first;
		pq.pop();
		
		if(d[cur]<dist){
			continue;
		}
		
		for(int i=0;i<v[cur].size();i++){
			int next=v[cur][i].first;
			int nextdist=v[cur][i].second+dist;
			
			if(v[cur][i].second==-1){
				continue;
			}
			
			if(d[next]>nextdist){
				d[next]=nextdist;
				pq.push({-nextdist,next});
				
				trace[next].clear();
				trace[next].push_back(cur);
			}else if(d[next]==nextdist){
				trace[next].push_back(cur);
			}
		}
	}
	return d;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,s,e;
	while(1){
		cin>>n>>m;
		if(!n&&!m){
			break;
		}else{
			cin>>s>>e;
			//include memory.h
			memset(v,0,sizeof(v));
			memset(check,false,sizeof(check));
			for(int i=0;i<m;i++){
				int a,b,c;
				cin>>a>>b>>c;
				v[a].push_back({b,c});
			}
			vector<int > trace[501];
			memset(trace,0,sizeof(trace));
			dijkstra(trace,s,n,m);
			queue<int> q;
			q.push(e);
			
			while(!q.empty()){
				int cur=q.front();
				q.pop();
				for(int i=0;i<trace[cur].size();i++){
					
					int next=trace[cur][i];
					
					if(check[cur][next]){
						continue;
					}
					
					for(int i=0;i<v[next].size();i++){
						if(v[next][i].first==cur){
							v[next][i].second=-1;
						}
					}
					q.push(next);
					
					
				}
				
			}
			vector<int> ans=dijkstra(trace,s,n,m);
			if(ans[e]==INT_MAX){
				cout<<"-1\n";
			}else{
				cout<<ans[e]<<"\n";
			}
		}
	}
} 
