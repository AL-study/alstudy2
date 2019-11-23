### 4195. 친구 네트워크

- 유니온 파인드를 응용하여 문자열을 통한 합집합 관계를 찾는 문제.

- string으로 되어 있기떄문에 map을 통해 구현했다.

- 처음 접근은 단순히 유니온 파인드를 구현하고 map<string, string>으로 받은 사람들을 친구관계로(unionparent)로 설정하고 for문을 통해 하나씩 찾아 갯수를 세어주는 방법이었다.

- 당연하게(?) 시간초과가 났다.  시간복잡도를 줄일 필요가 있었다. for문을 쓰지않고 상수 시간만큼만 써서 구현해야했다.

  - map하나만 쓰지말고 친구의 수를 저장할 배열(fnum), 해당 사람의 친구관계(부모)를 저장할 배열(set)을 이용한다. map은 <sring, string>이 아닌 <string, int> 로 저장하여 <이름, 해당 이름의 부모의 번호(set참조)>
  - set을 각각을 번호를 붙여 초기화한다. (최대 10만개의 케이스가 있고, **케이스당 2명이 주어지기 떄문에 총 20만개로 선언**해야한다. `int set[200001]`) 이는 처음은 자기자신을 부모로 설정하는 과정을 의미한다.
  - fnum또한 20만개를 선언해야한다. fnum의 의미는 **fnum[a]=b일때, a번 사람은 b명의 친구를 갖고있다.** 라는 의미이다.
  - 이제 어떤 사람이 어떤 번호를 갖고있는지 알아야한다. 1번(또는 0번)부터 시작하여 20만번(또는 20만-1번)까지 입력받은 순으로 변수(cnt)를 하나씩 증가시키며 저장한다.
  - 이제 유니온 파인드를 구현하기만 하면된다. 해당 사람을 번호로 map에 저장했고, 해당 번호에 따른 부모의 번호를 배열로 저장했으며, 해당 번호에 따른 친구수를 배열로 저장했기 떄문에 약간의 변형이 필요하다. 코드를 보는게 이해가 더 쉬울것이다.

- ```c++
  #include <iostream>
  #include <map>
  using namespace std;
  int n,f,set[200002],fnum[200002];
  int getparent(int x){
  	if(x==set[x]){
  		return x;
  	}else{
  		return set[x]=getparent(set[x]);
  	}
  }
  int unionparent(int x,int y){
  	x=getparent(x);
  	y=getparent(y);
  	if(x!=y){
  		set[x]=y;
  		fnum[y]+=fnum[x];
  		fnum[x]=1;
  	}
  	return fnum[y];
  }
  int main(){
  	std::ios_base::sync_with_stdio(false); 
  	std::cin.tie(NULL); 
  	std::cout.tie(NULL);
  	cin>>n;
  	for(int i=0;i<n;i++){
  		cin>>f;
  		int cnt=1;
  		for(int j=1;j<=f*2;j++){
  			set[j]=j;
  			fnum[j]=1;
  		}
  		map<string,int> parent;
  		for(int j=0;j<f;j++){
  			string a,b;
  			cin>>a>>b;
  			if(parent.count(a)==0){
  				parent[a]=cnt++;
  			}
  			if(parent.count(b)==0){
  				parent[b]=cnt++;
  			}
  			cout<<unionparent(parent[a],parent[b])<<"\n";
  		}
  	}
  }
  ```

  