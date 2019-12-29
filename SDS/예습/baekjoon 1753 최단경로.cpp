#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000
using namespace std;

int d[20001],n,e,target,ans;
vector<pair<int, int> > v[20001];

void dijkstra(int start){
	d[start]=0;
	priority_queue<pair <int, int> > pq;
	// 시작 정점은 거리가 0이기 때문이다. 
	pq.push({0,start});
	while(!pq.empty()){
		int current =pq.top().second;
		int distance= -pq.top().first;
		pq.pop();
		
		if(d[current]<distance)continue;
		for(int i=0;i<v[current].size();i++){
			//선택된 노드의 인접 노드
			int next=v[current][i].second;
			//선택된 노드를 인접 노드로 거쳐서 가는 비용
			int next_d=distance+v[current][i].first; 
			//기존 최소 비용보다 더 저렴하다면 교체한다.
			if(next_d<d[next]){
				d[next]=next_d;
				pq.push({-next_d,next});
			} 
		}
	}
}

int main(){
	cin>>n>>e>>target;
	for(int i=0;i<e;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back({c,b});
	}
	for(int i=1;i<=n;i++){
		d[i]=INF;
	}
	dijkstra(target);
	for(int i=1;i<=n;i++){
		if(d[i]==INF){
			cout<<"INF\n";
		}else{
			cout<<d[i]<<"\n";
		}
	}
}
