### 7578. 공장



#### 문제

어떤 공장에는 2N개의 기계가 2열에 걸쳐 N개씩 배치되어 있다. 이 2개의 열을 각각 A열과 B 열이라고 부른다. A열에 있는 N개의 기계는 각각이 B열에 있는 N개의 기계와 하나씩 짝을 이루어 케이블로 연결되어 있다. 즉, A열의 임의의 기계는 B열의 유일한 기계와 케이블로 연결되어 있고, B열의 임의의 기계는 A열의 유일한 기계와 케이블로 연결되어 있다

또한, 각 기계에는 식별번호가 붙어있으며, 짝이 맺어진 기계끼리는 같은 식별번호가 붙어있다. 즉, 각 열에 있는 N개의 기계끼리는 서로 다른 식별번호를 가지고 있으며, 반대쪽 열에 있는 같은 식별번호를 가진 기계와 케이블로 이어져 있다.

공장 작업의 효율성을 위해 기계들은 짝을 맺은 순서대로 배치되지 않으며, 필요에 따라 각 열의 기계들의 순서를 바꾼 바람에 케이블은 마구 엉켜있는 상태이다. 이렇게 엉켜버린 케이블은 잦은 고장의 원인이 되기 때문에, 기계의 위치를 바꾸지 않은 상태에서 케이블을 두 기계를 잇는 직선의 형태로 만들기로 했다.

![img](https://www.acmicpc.net/upload/images/gj.png)

예를 들어, 위의 그림과 같이 N = 5이고, A열에 위치한 기계의 식별번호가 순서대로 132, 392, 311, 351, 231이고 B열에 위치한 기계의 식별번호가 순서대로 392, 351, 132, 311, 231이라면 케이블들의 교차 횟수 혹은 서로 교차하는 케이블 쌍의 개수는 3이 된다.

정수 N과 A열에 위치한 기계, B열에 위치한 기계의 식별번호가 각각 순서대로 주어질 때에 서로 교차하는 케이블 쌍의 개수를 정확하게 세어 출력하는 프로그램을 작성하시오.

#### 입력

입력은 세 줄로 이루어져 있다. 첫 줄에는 정수 N이 주어지며, 두 번째 줄에는 A열에 위치한 N개 기계의 서로 다른 식별번호가 순서대로 공백문자로 구분되어 주어진다. 세 번째 줄에는 B열에 위치한 N개의 기계의 식별번호가 순서대로 공백문자로 구분되어 주어진다.

단, 1 ≤ N ≤ 500,000이며, 기계의 식별번호는 모두 0 이상 1,000,000 이하의 정수로 주어진다



- 교차점을 구하는 방법을 모른다면 세그먼트 트리를 알아도 풀 수 없으며, 왜 세그먼트 트리가 필요한지도 이해하지 못한다.

- 교차점을 구하는 방법은 https://www.crocus.co.kr/782을 참고했다. 글로 요약하자면, 각 A와 연결된 B의 인덱스를 방문처리 한 이후, 해당 인덱스 이후부터 끝까지 방문한 곳을 찾아 더해준다. 세그먼트 트리는 이 때의 해당 인덱스 이후 부터 끝까지의 누적합을 update하고, 더하는 과정에서 사용된다.

- map을 이용해 구할 수도 있지만 메모리를 초과하지 않으며, string이 아닌데 숫자이므로 int 배열을 사용해도 상관없다.

- ```c++
  #include <iostream>
  #include <vector>
  #include <cmath>
  using namespace std;
  int n,check[1000001];
  long long ans;
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
  	cin>>n;
  	vector<long long> v(n);
  	int h=(int)ceil(log2(n));
  	int tree_size=(1<<(h+1));
  	vector<long long> tree(tree_size);
  	for(int i=0;i<n;i++){
  		int a;
  		cin>>a;
          // A공장의 a번 기계는 i번째에 위치해 있다.
  		check[a]=i;
  	}
  	for(int i=0;i<n;i++){
  		int a;
  		cin>>a;
          // a번 기계는 B공장의 i번째에, A공장의 check[a]번째에 있고 서로 연결되어 있다.
  		v[i]=check[a];
  	}
  	for(int i=0;i<n;i++){
  		int temp=v[i];
          //해당 인덱스 이후의 인덱스부터 끝까지 부분합을 더한다.
  		ans+=sum(tree,1,0,n-1,temp+1,n-1);
          //부분 합을 갱신한다.
  		update(tree,1,0,n-1,temp,1);
  	}
  	cout<<ans;
  }
  ```

  