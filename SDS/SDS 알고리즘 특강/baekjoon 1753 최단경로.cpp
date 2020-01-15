#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int n,m,k,d[20001];
vector<pair<int, int > > v[20001];

void dijkstra(int start){
	priority_queue<pair<int, int> > pq;
	pq.push({0,start});
	while(!pq.empty()){
		int cur=pq.top().second;
		int dist=-pq.top().first;
		pq.pop();
		if(d[cur]<dist)continue;
		for(int i=0;i<v[cur].size();i++){
			int next=v[cur][i].first;
			int nextdist=v[cur][i].second+dist;
			if(d[next]>nextdist){
				d[next]=nextdist;
				pq.push({-nextdist,next});
			}
		}
	}
}

int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		d[i]=INF;
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back({b,c});
	}
	d[k]=0;
	dijkstra(k);
	for(int i=1;i<=n;i++){
		if(d[i]==INF)cout<<"INF\n";
		else cout<<d[i]<<"\n";
	}
}
