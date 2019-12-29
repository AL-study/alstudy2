#include <iostream>
#include <vector>
#define MAX 100001
#define LOG 21
using namespace std;

int n, m, parent[MAX][LOG],d[MAX];
bool c[MAX];
vector<int> v[MAX];

void dfs(int x, int depth){
	c[x]=true;
	d[x]=depth;
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(c[y])continue;
		parent[y][0]=x;
		dfs(y, depth+1);
	}
}

void setparent(){
	//dfs(0, 0)은 루트 0부터 시작 
	dfs(1, 0);
	for(int j=1;j<LOG;j++){
		//for(int i=0;i<n;i++)은 루트 0부터시작 
		for(int i=1;i<=n;i++){
			parent[i][j]=parent[parent[i][j-1]][j-1];
		}
	}
}

int lca(int x, int y){
	if(d[x]>d[y]){
		swap(x,y);
	}
	for(int i=LOG-1;i>=0;i--){
		//시프트 연산자로 2^i 표현
		if(d[y]-d[x]>=(1<<i)){
			y=parent[y][i];
		}
	}
	//부모가 같은 경우 반환.
	if(x==y) return x;
	for(int i=LOG-1;i>=0;i--){
		//조상을 향해 거슬러 올라간다.
		if(parent[x][i]!=parent[y][i]){
			x=parent[x][i];
			y=parent[y][i];
		} 
	} 
	return parent[x][0];
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	setparent();
	cin>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		cout<<lca(a,b)<<"\n";
	}
}



