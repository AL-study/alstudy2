### 2252. 줄 세우기



#### 문제

N명의 학생들을 키 순서대로 줄을 세우려고 한다. 각 학생의 키를 직접 재서 정렬하면 간단하겠지만, 마땅한 방법이 없어서 두 학생의 키를 비교하는 방법을 사용하기로 하였다. 그나마도 모든 학생들을 다 비교해 본 것이 아니고, 일부 학생들의 키만을 비교해 보았다.

일부 학생들의 키를 비교한 결과가 주어졌을 때, 줄을 세우는 프로그램을 작성하시오.

#### 입력

첫째 줄에 N(1≤N≤32,000), M(1≤M≤100,000)이 주어진다. M은 키를 비교한 회수이다. 다음 M개의 줄에는 키를 비교한 두 학생의 번호 A, B가 주어진다. 이는 학생 A가 학생 B의 앞에 서야 한다는 의미이다.

학생들의 번호는 1번부터 N번이다.



- 위상정렬의 기본개념을 연습하기 좋은 문제. 위상 정렬을 구현할 수 있다면 바로 풀 수 있다.

- 각 노드(학생의 번호)를 입력 받아 노드와 노드 사이를 연결하고 해당 노드의 진입 차수를 증가시키고, 위상 정렬을 수행하여 순서를 출력한다.

- ```c++
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
  			cout<<"싸이클 발생\n";
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
  ```

  