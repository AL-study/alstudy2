### 1717. 집합의 표현

- {0}부터 {n}까지 총 n+1개의 집합을 받아 합집합 연산을 하고 서로 집합에 속해 있는지(부모노드가 같은지) 확인하는 문제

- 유니온 파인드의 개념을 다질 수 있는 문제. 유니온 파인드 함수 구현을 연습하기에 좋은 문제였다.

- ```c++
  #include <iostream>
  using namespace std;
  int parent[1000001],n,m;
  int getparent(int x){
  	if(parent[x]==x){
  		return x;
  	}else{
  		return parent[x]=getparent(parent[x]);
  	}
  }
  void unionparent(int x,int y){
  	x=getparent(x);
  	y=getparent(y);
  	if(x<y){
  		parent[y]=x;
  	}else{
  		parent[x]=y;
  	}
  }
  void findunion(int x,int y){
  	x=getparent(x);
  	y=getparent(y);
  	if(x==y){
  		cout<<"YES\n";
  	}else{
  		cout<<"NO\n";
  	}
  	return;
  }
  int main(){
  	std::ios_base::sync_with_stdio(false); 
  	std::cin.tie(NULL); 
  	std::cout.tie(NULL);
  
  	cin>>n>>m;
  	for(int i=0;i<=n;i++){
  		parent[i]=i;
  	}
  	for(int i=0;i<m;i++){
  		int num,x,y;
  		cin>>num>>x>>y;
  		if(num==0){
  			unionparent(x,y);
  		}else{
  			findunion(x,y);
  		}
  		
  	}
  	
  }
  ```

  