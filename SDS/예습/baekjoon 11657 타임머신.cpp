#include <iostream>
#include <vector>
#define INF 10000000
using namespace std;
int n,m,d[501];
vector<pair <int, int> > v[501];
bool cycle;
void bellman(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<v[j].size();k++){
				if(d[j]!=INF&&d[v[j][k].first]>v[j][k].second+d[j]){
					d[v[j][k].first]=v[j][k].second+d[j];
					if(i==n)cycle=true;
				}
			}
		}
	}
	if(cycle)
		cout<<"-1\n";
	else{
		for(int i=2;i<=n;i++){
			if(d[i]==INF)cout<<"-1\n";
			else cout<<d[i]<<"\n";
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back({b,c});
	}
	for(int i=2;i<=n;i++){
		d[i]=INF;
	}
	bellman();
}
