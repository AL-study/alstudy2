#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m,indegree[32001],ans[32001];
vector<int> v[32001];


void topology(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(q.empty()){
			cout<<"사이클 발생";
			return;
		}
		int x=q.front();
		q.pop();
		ans[i]=x;
		for(int j=0;j<v[x].size();j++){
			int y=v[x][j];
			if(--indegree[y]==0){
				q.push(y);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return;
	
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		indegree[b]++;
	}
	topology();
}
