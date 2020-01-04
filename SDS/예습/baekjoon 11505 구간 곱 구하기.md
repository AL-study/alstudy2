### 11505. 구간 곱 구하기



#### 문제

어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 곱을 구하려 한다. 만약에 1, 2, 3, 4, 5 라는 수가 있고, 3번째 수를 6으로 바꾸고 2번째부터 5번째까지 곱을 구하라고 한다면 240을 출력하면 되는 것이다. 그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 3번째부터 5번째까지 곱을 구하라고 한다면 48이 될 것이다.

#### 입력

첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000) 가 주어진다. M은 수의 변경이 일어나는 회수이고, K는 구간의 곱을 구하는 회수이다. 그리고 둘째 줄부터 N+1번째 줄까지 N개의 수가 주어진다. 그리고 N+2번째 줄부터 N+M+K+2번째 줄까지 세 개의 정수 a,b,c가 주어지는데, a가 1인 경우 b번째 수를 c (0 ≤ c ≤ 1,000,000)로 바꾸고 a가 2인 경우에는 b부터 c까지의 곱을 구하여 출력하면 된다.



- 구간 합 구하기의 응용 버전.  합이 곱으로 바뀌었을 뿐이지만 생각보다 구현이 쉽지 않았다. 사소한(?) 문제로 인해 많은 틀렸습니다를 만났다. 그럼 주의 사항을 살펴보자.

  - 구간의 곱을 구할 때, 범위를 벗어난다고 0을 `return` 하면 안된다. 곱이기 때문에 1을 리턴해주자.
  - 초기화 함수(init), 구간 곱을 구하는 함수(query), 구간 곱을 갱신하는 함수(update)모두 MOD(10억7로 나누는 과정)연산을 마지막에 반드시 해주어야한다.
  - 곱이기 때문에 값이 작아도 `int`값을 훌쩍 넘어버린다. `long long`으로 선언해주자. 
  - 당연한 말이지만 구간합의 update함수와 곱의 update함수의 로직은 달라져야 한다. 이 부분이 시간이 제일 많이 걸렸다. 잘 생각해보고 구현해보자.

- ```c++
  #include <iostream>
  #include <cmath>
  #include <vector>
  using namespace std;
  int n,m,k;
  long long init(vector<long long> &v, vector<long long> &tree, int node, int start, int end){
  	if(start==end){
  		return tree[node]*=v[start];
  	}else{
  		return tree[node]=(init(v,tree,node*2,start,(start+end)/2)*init(v,tree,node*2+1,(start+end)/2+1,end))%1000000007;
  	}
  }
  
  long long query(vector<long long> &tree, int node, int start, int end, int left, int right){
  	if(right<start||end<left){
  		return 1;
  	}
  	if(left<=start&&end<=right){
  		return tree[node];
  	}
  	return (query(tree,node*2,start,(start+end)/2,left,right)*query(tree,node*2+1,(start+end)/2+1,end,left,right))%1000000007;
  }
  
  long long update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
  	if(index<start || index>end){
  		return tree[node];
  	}
  	if(start==end){
  		return tree[node]=diff;
  	}
  	if(start!=end){
  		return tree[node]=(update(tree,node*2,start,(start+end)/2,index,diff)*update(tree,node*2+1,(start+end)/2+1,end,index,diff))%1000000007;
  	}
  }
  
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	cin>>n>>m>>k;
  	vector<long long> v(n);
  	int h=(int)ceil(log2(n));
  	int tree_s=(1<<(h+1));
  	vector<long long>tree(tree_s);
  	for(int i=0;i<tree_s;i++){
  		tree[i]=1;
  	}
  	for(int i=0;i<n;i++){
  		cin>>v[i];
  	}
  	init(v,tree,1,0,n-1);
  
  	for(int i=0;i<m+k;i++){
  		long long a,b,c;
  		cin>>a>>b>>c;
  		if(a==1){
  			//v[b-1]=c;
  			update(tree,1,0,n-1,b-1,c);
  
  		}else{
  			cout<<query(tree,1,0,n-1,b-1,c-1)<<"\n";
  		}
  	}
  }
  ```

  