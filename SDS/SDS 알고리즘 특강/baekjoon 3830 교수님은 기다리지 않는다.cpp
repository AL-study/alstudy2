#include <iostream>
#include <vector>
using namespace std;

int n,m,parent[1000001],impossible[1000001],check[1000001];
long long dist[1000001];
vector<pair<long long, long long> > v[1000001],q;


void dfs(int num, long long d){
	//?
	check[num]=true;
	dist[num]=d;
	for(int i=0;i<v[num].size();i++){
		int next=v[num][i].first;
		if(!check[next]){
			check[next]=1;
			dfs(next,d+v[num][i].second);
		}
	}
	
}

int getparent(int x){
	if(parent[x]==x)return x;
	return parent[x]=getparent(parent[x]);
}
void unionparent(int x, int y){
	x=getparent(x);
	y=getparent(y);
	if(x<y)parent[y]=x;
	else parent[x]=y;
}
bool unionfind(int x,int y){
	return getparent(x)==getparent(y);
}


int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(1){
		cin>>n>>m;
		if(!n&&!m){
			break;
		}
		for(int i=0;i<=n;i++){
			parent[i]=i;
			dist[i]=0;
			check[i]=0;
			impossible[i]=0;
			v[i].clear();
			q.clear();
		}
		for(int i=0;i<m;i++){
			char a;
			cin>>a;
			if(a=='!'){
				int b,c,d;
				cin>>b>>c>>d;
				if(!unionfind(b,c)){
					unionparent(b,c);
					v[b].push_back({c,d});
					v[c].push_back({b,-d});
				}
			}else{
				int b,c;
				cin>>b>>c;
				q.push_back({b,c});
				if(!unionfind(b,c)){
					impossible[q.size()-1]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(!check[i])dfs(i,0);
		}
		for(int i=0;i<q.size();i++){
			int start=q[i].first;
			int end=q[i].second;
			if(impossible[i]){
				cout<<"UNKNOWN\n";
				continue;
			}
			cout<<dist[end]-dist[start]<<"\n";
		}
		
	}
}
