#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;

int n,m,k;
priority_queue<int> kpq[1001];
vector<pair<int, int> > v[1001];

void dijkstra(){
	priority_queue<pair<int, int > > pq;
	pq.push({0,1});
	kpq[1].push(0);
	while(pq.size()){
		int cur=pq.top().second;
		int dist=-pq.top().first;
		pq.pop();
		for(int i=0;i<v[cur].size();i++){
			int next=v[cur][i].first;
			int nextdist=v[cur][i].second+dist;
			
			if(kpq[next].size()<k){
				kpq[next].push(nextdist);
				pq.push({-nextdist,next});
			}else if(kpq[next].top()>nextdist){
				kpq[next].pop();
				kpq[next].push(nextdist);
				pq.push({-nextdist,next});
			}
			
		}
		
		
	}
	
}



int main(){
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back({b,c});
	}
	dijkstra();
	for(int i=1;i<=n;i++){
		if(kpq[i].size()!= k) cout<<"-1\n";
		else cout<<kpq[i].top()<<"\n";
	}
}
