# 최소공통조상 LCA(Lowest Common Ancestor)

#### 참고 출처: [안경잡이 개발자 네이버 블로그 (나동빈님)](https://blog.naver.com/ndb796/221282478466)

최소 공통 조상은 **트리 구조에서 특정한 두 노드의 공통된 조상 중에서 가장 가까운 조상을 의미**한다. 이때 트리는 반드시 이진트리가 아닌, 일반적인 형태의 트리라면 적용할 수 있다는 특징이 있다. 

최소 공통 조상 알고리즘은 다음과 같은 방법으로 구현할 수 있다.

1. 모든 노드에 대한 깊이를 구한다.
2. 모든 노드에 대한 2^i번째 부모 노드를 구한다.
3. 최소 공통 조상을 찾을 두 노드를 설정한다.
4. 두 노드의 깊이가 동일하도록 거슬러 올라간다.
5. 최상단 노드부터 내려오는 방식으로 두 노드의 공통 부모를 찾아낸다.



최소 공통 조상은 세그먼트 트리와 마찬가지로 정형화(?)된 함수가 있다. 여기서 크게 바뀌지 않는 것 같아서 최소 공통 조상의 개념을 연습할 수 있는 좋은 개념문제인 [BOJ 11438 LCA 2](https://www.acmicpc.net/problem/11438)의 코드를 주석과 함께 정리한다.



```c++
루트의 번호에 따라 함수가 조금씩 달라질 수 있다. 그러나 루트 번호가 0에서 시작하는지 1에서 시작하는지의 차이일 뿐이다.
#include <iostream>
#include <vector>
#define MAX 100001
#define LOG 21
using namespace std;

int n, m, parent[MAX][LOG],d[MAX];
bool c[MAX];
vector<int> v[MAX];
// 1. 모든 노드에 대한 깊이(depth)를 구한다.
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
// 2. 모든 노드에 대한 2^i번째 노드를 구한다.
void setparent(){
	//dfs(0, 0)은 루트 0부터 시작 
	dfs(1, 0); // 루트 번호가 1부터 시작할 때
	for(int j=1;j<LOG;j++){
		//for(int i=0;i<n;i++)은 루트 0부터시작 
		for(int i=1;i<=n;i++){ //루트 번호가 1번부터 시작할 때
            // 2^j 번째 부모를 계산하는 방법이다.
            // 이 부분은 쉽게 생각하기 어려운 부분이다. 
            //이해하는게 좋지만 이해가 안된다면 외우자.
			parent[i][j]=parent[parent[i][j-1]][j-1];
		}
	}
}
// 최상단 노드부터 내려오는 방식으로 두 노드의 공통 부모를 찾아낸다.
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
```



## 문제 리스트

- ### [BOJ 11438 LCA2](https://github.com/jungtaeyong/alstudy2/blob/ty/SDS/예습/baekjoon%2011438%20LCA%202.cpp)