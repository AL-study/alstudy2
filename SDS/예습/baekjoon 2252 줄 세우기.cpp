#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m,result[32001],indegree[32001];
vector<int> v[32001];

void topologysort(vector<int> v[],int result[], int indegree[]){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(q.empty()){
			cout<<"½ÎÀÌÅ¬ ¹ß»ý\n";
			return;
		}
		int x=q.front();
		q.pop();
		result[i]=x;
		for(int j=0;j<v[x].size();j++){
			int y=v[x][j];
			if(--indegree[y]==0){
				q.push(y);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<result[i]<<" ";
	}
}

int main(){
	cin>>n>>m;
	
	for(int i=1;i<=m;i++){
		int temp1,temp2;
		cin>>temp1>>temp2;
		v[temp1].push_back(temp2);
		indegree[temp2]++;
	}
	topologysort(v,result,indegree);
}
