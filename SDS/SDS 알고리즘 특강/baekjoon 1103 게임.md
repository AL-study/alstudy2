### 1103. 게임



#### 문제

형택이는 1부터 9까지의 숫자와, 구멍이 있는 직사각형 보드에서 재밌는 게임을 한다.

일단 보드의 가장 왼쪽 위에 동전을 하나 올려놓는다. 그다음에 다음과 같이 동전을 움직인다.

1. 동전이 있는 곳에 쓰여 있는 숫자 X를 본다.
2. 위, 아래, 왼쪽, 오른쪽 방향 중에 한가지를 고른다.
3. 동전을 위에서 고른 방향으로 X만큼 움직인다. 이때, 중간에 있는 구멍은 무시한다.

만약 동전이 구멍에 빠지거나, 보드의 바깥으로 나간다면 게임은 종료된다. 형택이는 이 재밌는 게임을 되도록이면 오래 하고 싶다.

보드의 상태가 주어졌을 때, 형택이가 최대 몇 번 동전을 움직일 수 있는지 구하는 프로그램을 작성하시오.

#### 입력

줄에 보드의 세로 크기 N과 가로 크기 M이 주어진다. 이 값은 모두 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 보드의 상태가 주어진다. 쓰여 있는 숫자는 1부터 9까지의 자연수 또는 H이다. 가장 왼쪽 위칸은 H가 아니다. H는 구멍이다.

- DFS+DP를 이용한 응용 문제. 하나가 아닌 2개의 알고리즘의 개념이 응용되어 쉽지 않았던 문제.

- DFS의 기본적인 조건에 DP의 개념이 추가된 것이라고 생각하면 된다.

  ```C++
  int dfs(){
      if(탈출 조건){
          return 0;
      }
      if(dp 조건){
          return dp값;
      }
      for(int i=0;i<n;i++){
          dp값 갱신
          dfs();
      }
   	return 값;
  }
  ```

  의 형태로 기본적인 dfs에서 dp조건을 이용해 탈출하고, dp값을 갱신시켜 나간다.

- ```c++
  #include <iostream>
  #include <cstring>
  using namespace std;
  
  int n,m,dp[51][51],ans;
  string str[51];
  bool flag;
  bool check[51][51];
  typedef struct DIR{
  	int r,c;
  };
  DIR dir[4]={{1,0},{-1,0},{0,1},{0,-1}};
  int dfs(int r,int c){
  	if(r<0||n<=r||c<0||m<=c){
  		return 0;
  	}
  	if(str[r][c]=='H'){
  		return 0;
  	}
  	if(check[r][c]){
  		cout<<-1;
  		exit(0);
  	}
  	int& ret=dp[r][c];
  	if(ret!=-1){
  		return ret;
  	}
  	check[r][c]=true;
  	int num=(int)str[r][c]-(int)'0';
  	for(int i=0;i<4;i++){
  		int rr=r+num*dir[i].r;
  		int cc=c+num*dir[i].c;
  		ret=max(ret,dfs(rr,cc)+1);
  	}
  	check[r][c]=false;
  	return ret;
  }
  
  int main(){
  	cin>>n>>m;
  	memset(dp,-1,sizeof(dp));
  	for(int i=0;i<n;i++){
  		cin>>str[i];
  	}
  	cout<<dfs(0,0);
  }
  ```

  