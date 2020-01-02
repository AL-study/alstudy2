### 2357. 최솟값과 최댓값



#### 문제

N(1 ≤ N ≤ 100,000)개의 정수들이 있을 때, a번째 정수부터 b번째 정수까지 중에서 제일 작은 정수, 또는 제일 큰 정수를 찾는 것은 어려운 일이 아니다. 하지만 이와 같은 a, b의 쌍이 M(1 ≤ M ≤ 100,000)개 주어졌을 때는 어려운 문제가 된다. 이 문제를 해결해 보자.

여기서 a번째라는 것은 입력되는 순서로 a번째라는 이야기이다. 예를 들어 a=1, b=3이라면 입력된 순서대로 1번, 2번, 3번 정수 중에서 최소, 최댓값을 찾아야 한다. 각각의 정수들은 1이상 1,000,000,000이하의 값을 갖는다.

#### 입력

첫째 줄에 N, M이 주어진다. 다음 N개의 줄에는 N개의 정수가 주어진다. 다음 M개의 줄에는 a, b의 쌍이 주어진다.



- [BOJ 2042 구간 합 구하기](https://www.acmicpc.net/problem/2042) 와 마찬가지로 세그먼트 트리의 개념을 연습할 수 있는 좋은 문제.
- 최솟값, 최댓값을 한 번에 만들어도 되고, 따로 나누어서 각각 구현해 적용해도 된다. 주의사항으로는 int형을 초과하기 때문에 `long long`형으로 선언해야 하고, 최솟값을 구하는 세그먼트 트리는 범위를 벗어날시, `retrun INF`값을 해야 한다. (최솟값을 비교해야 하기 때문에)

- ```C++
  #include <iostream>
  #include <vector>
  #include <cmath>
  #define INF 1500000000
  using namespace std;
  
  int n,m,k;
  
  
  long long initmin(vector<long long> &v, vector<long long> &tree, int node, int start, int end){
  	if(start==end){
  		return tree[node]=v[start];
  	}else{
  		return tree[node]=min(initmin(v,tree,node*2,start,(start+end)/2),initmin(v,tree,node*2+1,(start+end)/2+1,end));
  	}
  }
  
  long long segmin(vector<long long> &tree, int node, int start, int end, int left, int right){
  	if(right<start||end<left){
  		return INF;
  	}
  	if(left<=start&&end<=right){
  		return tree[node];
  	}
  	return min(segmin(tree,node*2,start,(start+end)/2,left,right),segmin(tree,node*2+1,(start+end)/2+1,end,left,right));
  }
  
  long long initmax(vector<long long> &v, vector<long long> &tree, int node, int start, int end){
  	if(start==end){
  		return tree[node]=v[start];
  	}else{
  		return tree[node]=max(initmax(v,tree,node*2,start,(start+end)/2),initmax(v,tree,node*2+1,(start+end)/2+1,end));
  	}
  }
  
  long long segmax(vector<long long> &tree, int node, int start, int end, int left, int right){
  	if(right<start||end<left){
  		return 0;
  	}
  	if(left<=start&&end<=right){
  		return tree[node];
  	}
  	return max(segmax(tree,node*2,start,(start+end)/2,left,right),segmax(tree,node*2+1,(start+end)/2+1,end,left,right));
  }
  
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	cin>>n>>m;
  	vector<long long> v(n);
  	int h=(int)ceil(log2(n));
  	int tree_s=(1<<(h+1));
  	vector<long long> treemin(tree_s);
  	vector<long long> treemax(tree_s);
  	for(int i=0;i<n;i++){
  		cin>>v[i];
  	}
  	initmin(v,treemin,1,0,n-1);
  	initmax(v,treemax,1,0,n-1);
  	for(int i=0;i<m;i++){
  		long long a,b;
  		cin>>a>>b;
  		cout<<segmin(treemin,1,0,n-1,a-1,b-1)<<" ";
  		cout<<segmax(treemax,1,0,n-1,a-1,b-1)<<"\n";
  	}	
  }
  ```

  