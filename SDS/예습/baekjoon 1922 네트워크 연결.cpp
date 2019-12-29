#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,set[100001],sum;

class Edge{
	public:
		int node[2];
		int distance;
		Edge(int a, int b, int distance){
			this->node[0]=a;
			this->node[1]=b;
			this->distance=distance;
		}
		bool operator <(Edge &edge){
			return this->distance < edge.distance;
		}
};

int getparent(int a){
	if(set[a]==a){
		return a;
	}else{
		return set[a]=getparent(set[a]);
	}
}

void unionparent(int a, int b){
	int x=getparent(a);
	int y=getparent(b);
	if(x>y){
		set[x]=y;
	}else{
		set[y]=x;
	}
}

bool find(int a, int b){
	if(getparent(a)==getparent(b)){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	cin>>n>>m;
	vector<Edge> v;
	for(int i=1;i<=n;i++){
		set[i]=i;
	}
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v.push_back(Edge(a,b,c));
	}
	sort(v.begin(),v.end());
	
	for(int i=0;i<v.size();i++){
		if(!find(v[i].node[0], v[i].node[1])){
			unionparent(v[i].node[0], v[i].node[1]);
			sum+=v[i].distance;
		}
	}
	cout<<sum;
}
