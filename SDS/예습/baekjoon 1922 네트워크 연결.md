### 1922. 네트워크 연결



#### 문제

도현이는 컴퓨터와 컴퓨터를 모두 연결하는 네트워크를 구축하려 한다. 하지만 아쉽게도 허브가 있지 않아 컴퓨터와 컴퓨터를 직접 연결하여야 한다. 그런데 모두가 자료를 공유하기 위해서는 모든 컴퓨터가 연결이 되어 있어야 한다. (a와 b가 연결이 되어 있다는 말은 a에서 b로의 경로가 존재한다는 것을 의미한다. a에서 b를 연결하는 선이 있고, b와 c를 연결하는 선이 있으면 a와 c는 연결이 되어 있다.)

그런데 이왕이면 컴퓨터를 연결하는 비용을 최소로 하여야 컴퓨터를 연결하는 비용 외에 다른 곳에 돈을 더 쓸 수 있을 것이다. 이제 각 컴퓨터를 연결하는데 필요한 비용이 주어졌을 때 모든 컴퓨터를 연결하는데 필요한 최소비용을 출력하라. 모든 컴퓨터를 연결할 수 없는 경우는 없다.

#### 입력

첫째 줄에 컴퓨터의 수 N (1 ≤ N ≤ 1000)가 주어진다.

둘째 줄에는 연결할 수 있는 선의 수 M (1 ≤ M ≤ 100,000)가 주어진다.

셋째 줄부터 M+2번째 줄까지 총 M개의 줄에 각 컴퓨터를 연결하는데 드는 비용이 주어진다. 이 비용의 정보는 세 개의 정수로 주어지는데, 만약에 a b c 가 주어져 있다고 하면 a컴퓨터와 b컴퓨터를 연결하는데 비용이 c (1 ≤ c ≤ 10,000) 만큼 든다는 것을 의미한다.



- 크루스칼 알고리즘을 연습하기 좋은 문제. 따라서 기본적으로 유니온 파인드 함수를 구현하고, 사이클을 발생시키지 않는 선에서 탐욕적으로 간선을 선택하여 최소 비용을 출력한다.

- 노드와 간선 정보를 정의할 때 클래스와 오퍼레이터를 이용하여 벡터에 저장하여 정렬한다.

- ```C++
  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;
  
  int n,m,set[100001],sum;
  
  class Edge{
  	public:
  		int node[2];
  		int distance;
  		Edge(int a, int b, int distance){
  			this->node[0]=a;
  			this->node[1]=b;
  			this->distance=distance;
  		}
  		bool operator <(Edge &edge){
  			return this->distance < edge.distance;
  		}
  };
  
  
  int getparent(int a){
  	if(set[a]==a){
  		return a;
  	}else{
  		return set[a]=getparent(set[a]);
  	}
  }
  
  void unionparent(int a, int b){
  	int x=getparent(a);
  	int y=getparent(b);
  	if(x>y){
  		set[x]=y;
  	}else{
  		set[y]=x;
  	}
  }
  
  bool find(int a, int b){
  	if(getparent(a)==getparent(b)){
  		return 1;
  	}else{
  		return 0;
  	}
  }
  
  int main(){
  	cin>>n>>m;
  	vector<Edge> v;
  	for(int i=1;i<=n;i++){
  		set[i]=i;
  	}
  	for(int i=1;i<=m;i++){
  		int a,b,c;
  		cin>>a>>b>>c;
  		v.push_back(Edge(a,b,c));
  	}
  	sort(v.begin(),v.end());
  	
  	for(int i=0;i<v.size();i++){
  		if(!find(v[i].node[0], v[i].node[1])){
  			unionparent(v[i].node[0], v[i].node[1]);
  			sum+=v[i].distance;
  		}
  	}
  	cout<<sum;
  }
  ```

  