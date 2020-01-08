# 2042. 구간 합 구하기

## 문제

어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다. 만약에 1,2,3,4,5 라는 수가 있고, 3번째 수를 6으로 바꾸고 2번째부터 5번째까지 합을 구하라고 한다면 17을 출력하면 되는 것이다. 그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 3번째부터 5번째까지 합을 구하라고 한다면 12가 될 것이다.

## 입력

첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000) 가 주어진다. M은 수의 변경이 일어나는 회수이고, K는 구간의 합을 구하는 회수이다. 그리고 둘째 줄부터 N+1번째 줄까지 N개의 수가 주어진다. 그리고 N+2번째 줄부터 N+M+K+1번째 줄까지 세 개의 정수 a, b, c가 주어지는데, a가 1인 경우 b번째 수를 c로 바꾸고 a가 2인 경우에는 b번째 수부터 c번째 수까지의 합을 구하여 출력하면 된다.

a가 1인 경우 c는 long long 범위를 넘지 않는다.

## 출력

첫째 줄부터 K줄에 걸쳐 구한 구간의 합을 출력한다. 단, 정답은 long long 범위를 넘지 않는다.



- 세그먼트 트리의 기본 문제. 초기화 함수, 쿼리 (구간 합을 구하는 함수), 갱신 함수를 연습해보자.

- ```c++
  #include <iostream>
  #include <cmath>
  #include <vector>
  using namespace std;
  
  int n,m,k;
  
  long long init(vector<long long> &v, vector<long long> &tree, int node, int start, int end){
  	if(end==start) return tree[node]=v[start];
  	return tree[node]=init(v,tree,node*2,start,(start+end)/2)+init(v,tree,node*2+1,(start+end)/2+1,end);
  } 
  
  long long sum(vector<long long> &tree, int node, int start, int end, int left, int right){
  	if(right<start||end<left) return 0;
  	if(start>=left&&right>=end) return tree[node];
  	return sum(tree,node*2,start,(start+end)/2,left,right)+sum(tree,node*2+1,(start+end)/2+1,end,left,right);
  }
  void update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
  	if(index<start || index>end){
  		return;
  	}
  	tree[node]+=diff;
  	if(start!=end){
  		update(tree,node*2,start,(start+end)/2,index,diff);
  		update(tree,node*2+1,(start+end)/2+1,end,index,diff);
  	}
  }
  
  int main(){
  	cin>>n>>m>>k;
  	vector<long long> v(n);
  	int h=(int)ceil(log2(n));
  	int tree_s=(1<<(h+1));
  	vector<long long> tree(tree_s);
  	for(int i=0;i<n;i++){
  		cin>>v[i];
  	}
  	init(v,tree,1,0,n-1);
  	for(int i=0;i<m+k;i++){
  		long long a,b,c;
  		cin>>a>>b>>c;
  		if(a==1){
  			long long diff=c-v[b-1];
  			v[b-1]=c;
  			update(tree,1,0,n-1,b-1,diff);
  		}else if(a==2){
  			cout<<sum(tree,1,0,n-1,b-1,c-1)<<"\n";
  		}
  	}
  	return 0;
  }
  ```

  