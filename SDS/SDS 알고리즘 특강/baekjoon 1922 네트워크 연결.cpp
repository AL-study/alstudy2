#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,parent[1001],ans;

int getparent(int x){
	if(x==parent[x])return x;
	return parent[x]=getparent(parent[x]);
}
void unionparent(int x,int y){
	x=getparent(x);
	y=getparent(y);
	if(x<y)parent[y]=x;
	else parent[x]=y;
}
bool findparent(int x, int y){
	return getparent(x)==getparent(y);
}

class Edge{
	public:
		int node[2],distance;
		Edge(int a,int b,int distance){
			this->node[0]=a;
			this->node[1]=b;
			this->distance=distance;
		}
		bool operator <(Edge &edge){
			return this->distance < edge.distance;
		}
		
};

int main(){
	cin>>n>>m;
	vector<Edge> v;
	for(int i=1;i<=n;i++){
		parent[i]=i;
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v.push_back({a,b,c});
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		if(!findparent(v[i].node[0],v[i].node[1])){
			ans+=v[i].distance;
			unionparent(v[i].node[0],v[i].node[1]);
		}
	}
	cout<<ans;
	
}
