#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,indegree[501],d[501],arr[501];
vector<int> v[501];

void topology(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(indegree[i]==0){
			q.push(i);
			d[i]=arr[i];
		}
	}
	for(int i=1;i<=n;i++){
		int x=q.front();
		q.pop();
		for(int j=0;j<v[x].size();j++){
			int y=v[x][j];
			d[y]=max(d[y],d[x]+arr[y]);
			if(--indegree[y]==0){
				q.push(y);
			}
		}
	}
	
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		while(1){
			int a;
			cin>>a;
			if(a==-1){
				break;
			}
			else{
				v[a].push_back(i);
				indegree[i]++;
			}
		}
	}

	topology();
	for(int i=1;i<=n;i++){
		cout<<d[i]<<"\n";
	}
}
