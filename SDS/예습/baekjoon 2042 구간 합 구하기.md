### 2042. 구간 합 구하기



#### 문제

어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다. 만약에 1,2,3,4,5 라는 수가 있고, 3번째 수를 6으로 바꾸고 2번째부터 5번째까지 합을 구하라고 한다면 17을 출력하면 되는 것이다. 그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 3번째부터 5번째까지 합을 구하라고 한다면 12가 될 것이다.

#### 입력

첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000) 가 주어진다. M은 수의 변경이 일어나는 회수이고, K는 구간의 합을 구하는 회수이다. 그리고 둘째 줄부터 N+1번째 줄까지 N개의 수가 주어진다. 그리고 N+2번째 줄부터 N+M+K+1번째 줄까지 세 개의 정수 a, b, c가 주어지는데, a가 1인 경우 b번째 수를 c로 바꾸고 a가 2인 경우에는 b번째 수부터 c번째 수까지의 합을 구하여 출력하면 된다.

a가 1인 경우 c는 long long 범위를 넘지 않는다.



- 세그먼트 트리를 이용하여 배열을 변경 및 구간 합을 구하는 문제. 세그먼트 트리의 hello world격 문제로 개념을 잡기에 매우 좋은 문제이다.

- 세그먼트 트리 사용에 필요한 init, sum, update 함수를 직접 구현해보며 연습해보자.

- 주의 사항으로는 int형을 초과하기 때문에 long long을 사용해야 한다는 점이다.

- ```c++
  #include <iostream>
  #include <vector>
  #include <cmath>
  using namespace std;
  int n,m,k;
  long long init(vector <long long> &arr, vector<long long> &tree, int node, int start, int end){
  	if(start==end){
  		return tree[node]=arr[start];
  	}else{
  		return tree[node]=init(arr, tree, node*2,start,(start+end)/2)+init(arr, tree, node*2+1,(start+end)/2+1,end);
  	}
  }
  void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
      if (index < start || index > end) return;
      tree[node] = tree[node] + diff;
      if (start != end) {
          update(tree,node*2, start, (start+end)/2, index, diff);
          update(tree,node*2+1, (start+end)/2+1, end, index, diff);
      }
  }
  long long sum(vector<long long> &tree, int node, int start, int end, int left, int right){
  	if(left>end||right<start){
  		return 0;
  	}
  	if(left<=start&& end<=right){
  		return tree[node];
  	}
  	return sum(tree, node*2,start,(start+end)/2,left,right)+sum(tree, node*2+1,(start+end)/2+1,end,left,right);
  }
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	cin>>n>>m>>k;
  	vector<long long> v(n);
  	int h=(int)ceil(log2(n));
  	int tree_size=pow(2,h+1)-1;
  	//int tree_size=(1<<(h+1));
  	vector<long long> tree(tree_size);
  	for(int i=0;i<n;i++){
  		cin>>v[i];
  	}
  	int mk=m+k;
  	init(v, tree, 1, 0, n-1);
  	for(int i=0;i<mk;i++){
  		long long a,b,c;
  		cin>>a>>b>>c;
  		if(a==1){
  			b-=1;
  			long long diff=c-v[b];
  			v[b]=c;
  			update(tree,1,0,n-1,b,diff);
  		}else if(a==2){
  			cout<<sum(tree,1,0,n-1,b-1,c-1)<<"\n";
  		}
  	}
  	return 0;	
  }
  ```

  