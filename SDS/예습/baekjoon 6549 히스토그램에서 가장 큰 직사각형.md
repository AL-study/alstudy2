### 6549. 히스토그램에서 가장 큰 직사각형



#### 문제

히스토그램은 직사각형 여러 개가 아래쪽으로 정렬되어 있는 도형이다. 각 직사각형은 같은 너비를 가지고 있지만, 높이는 서로 다를 수도 있다. 예를 들어, 왼쪽 그림은 높이가 2, 1, 4, 5, 1, 3, 3이고 너비가 1인 직사각형으로 이루어진 히스토그램이다.

![img](https://www.acmicpc.net/upload/images/histogram.png)

히스토그램에서 가장 넓이가 큰 직사각형을 구하는 프로그램을 작성하시오.

#### 입력

입력은 테스트 케이스 여러 개로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, 직사각형의 수 n이 가장 처음으로 주어진다. (1 ≤ n ≤ 100,000) 그 다음 n개의 정수 h1, ..., hn (0 ≤ hi ≤ 1,000,000,000)가 주어진다. 이 숫자들은 히스토그램에 있는 직사각형의 높이이며, 왼쪽부터 오른쪽까지 순서대로 주어진다. 모든 직사각형의 너비는 1이고, 입력의 마지막 줄에는 0이 하나 주어진다.



- 알고리즘 분류에는 세그먼트 트리 이외에도 스택, 분할 정복이 있었지만, 세그먼트 트리를 공부하는 입장에서 세그먼트 트리를 이용하여 문제를 풀었다. (~~그렇다고 스택, 분할 정복으로 풀 수 있다는 건 아닙니다...~~)

- 하지만 세그트리 개념을 적용하여 풀기가 굉장히 어려웠다. 최솟값, 최댓값을 저장하는 세그먼트 트리를 이용한 문제는 구현만으로도 간단히 풀렸지만, 이 문제는 접근이 쉽지 않았다. 결국 https://www.crocus.co.kr/707를 참고하여 문제를 풀었다.

- 생각하지 못한 흥미로운점은 트리에 최솟값을 저장하는게 아닌, **최솟값을 가지고 있는 인덱스 번호를 저장**한다는 것이었다. 이러한 접근방법이 이 문제를 푸는 핵심이었다. 

- 이후엔 구간에서 가장 최소인 높이의 막대를 구하는 함수를 정의하고 그 함수를 이용해 가장 큰 넓이를 가지는 직사각형의 넓이를 구해나간다. 예를 들어 0에서 n번째 길이를 탐색한다고 하면, 0~n번째의 가장 큰 넓이를 가지는 직사각형 넓이를 구하고, 0~n/2 구간에서, n/2+1~n구간에서 가장 큰 넓이의 직사각형 값과 비교해 답을 찾는다. 즉, **구간을 반으로 나눠가면서 정답을 갱신하는 방식**이다. 코드를 보는게 이해가 더 쉬울 것이다.

- ```c++
  #include <iostream>
  #include <vector>
  #include <cmath>
  using namespace std;
  int n;
  
  void init(vector<long long> &v, vector<long long> &tree, int node, int start, int end){
  	if(start==end){
          // 값의 최솟값이 아닌 최솟값을 갖는 인덱스를 저장한다.
  		tree[node]=start;
  	}else{
  		init(v,tree,node*2,start,(start+end)/2);
  		init(v,tree,node*2+1,(start+end)/2+1,end);
  		if(v[tree[node*2]]<=v[tree[node*2+1]]){
  			tree[node]=tree[node*2];
  		}else{
  			tree[node]=tree[node*2+1];
  		}
  	}
  }
  //구간에서 가장 최소인 높이의 막대를 구한다.
  long long segfind(vector<long long> &v, vector<long long> &tree, int node, int start, int end, int left, int right){
  	if(right<start||end<left){
  		return -1;
  	}
  	if(left<=start&&end<=right){
  		return tree[node];
  	}
  	long long m1=segfind(v,tree,node*2,start,(start+end)/2,left,right);
  	long long m2=segfind(v,tree,node*2+1,(start+end)/2+1,end,left,right);
  	if(m1==-1){
  		return m2;
  	}else if(m2==-1){
  		return m1;
  	}else{
  		if(v[m1]<=v[m2]){
  			return m1;
  		}else{
  			return m2;
  		}
  	}	
  }
  //segfind함수를 이용하여 최종적으로 가장 넓은 직사각형의 넓이를 찾는다.
  long long getmax(vector<long long> &v,vector<long long> &tree, int start, int end){
  	int num=v.size();
  	int m=segfind(v,tree,1,0,num-1,start,end);
  	
  	long long area=(long long)(end-start+1)*v[m];
  	// 구간을 반으로 나눠 정답을 갱신해 나간다.
  	if(start<=m-1){
  		long long temp=getmax(v,tree,start,m-1);
  		area=max(area,temp);
  	}
  	if(m+1<=end){
  		long long temp=getmax(v,tree,m+1,end);
  		area=max(temp,area);
  	}
  	return area;
  }
  
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	while(1){
  		cin>>n;
  		if(n==0)return 0;
  		vector<long long> v(n);
  		int h=(int)ceil(log2(n));
  		int tree_s=(1<<(h+1));
  		vector<long long> tree(tree_s);
  		for(int i=0;i<n;i++){
  			cin>>v[i];
  		}
  		init(v,tree,1,0,n-1);
  		cout<<getmax(v,tree,0,n-1)<<"\n";
  	}
  }
  ```

  