# 5-4. 유니온 파인드 트리 (1)

## 개념 & 예시코드

유니온 파인드는 합집합을 찾는 알고리즘이다. 서로소 집합 알고리즘이라고도 부르는데 여러개의 노드가 존재할 때 두 개의 노드를 선택해서, 현재 이 두 노드가 서로 같은 그래프에 속하는지 판별하는 알고리즘이다.

- 예시코드

  ```c++
  #include <iostream>
  using namespace std;
  int parent[9];
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
  int compare(int x,int y){
  	x=getparent(x);
  	y=getparent(y);
  	if(x==y){
  		return 1;
  	}else{
  		return 0;
  	}
  }
  //1-2, 2-3, 3-4, 5-6, 6-7, 7-8 연 결 
  int main(){
  	for(int i=1;i<=8;i++){
  		parent[i]=i;
  	}
  	unionparent(1,2);
  	unionparent(2,3);
  	unionparent(3,4);
  	unionparent(5,6);
  	unionparent(6,7);
  	unionparent(7,8);
  	cout<<"1과 5는 연결되었나?"<<compare(1,5)<<"\n";
  	unionparent(1,5);
  	cout<<"1과 5는 연결되었나?"<<compare(1,5)<<"\n";
  }
  ```

#### 참고출처 [안경잡이 개발자(나동빈님)]( https://blog.naver.com/ndb796/221230967614 )



## 문제

- ### [BOJ 1717 집합의 표현](https://github.com/jungtaeyong/alstudy2/blob/ty/5-4%20유니온%20파인드%20트리%20(1)/baekjoon%201717%20집합의%20표현.md)

- ### [BOJ 4195 친구 네트워크](https://github.com/jungtaeyong/alstudy2/blob/ty/5-4%20유니온%20파인드%20트리%20(1)/baekjoon%204195%20친구%20네트워크.md)


