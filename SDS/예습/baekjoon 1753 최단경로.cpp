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
	// ���� ������ �Ÿ��� 0�̱� �����̴�. 
	pq.push({0,start});
	while(!pq.empty()){
		int current =pq.top().second;
		int distance= -pq.top().first;
		pq.pop();
		
		if(d[current]<distance)continue;
		for(int i=0;i<v[current].size();i++){
			//���õ� ����� ���� ���
			int next=v[current][i].second;
			//���õ� ��带 ���� ���� ���ļ� ���� ���
			int next_d=distance+v[current][i].first; 
			//���� �ּ� ��뺸�� �� �����ϴٸ� ��ü�Ѵ�.
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
