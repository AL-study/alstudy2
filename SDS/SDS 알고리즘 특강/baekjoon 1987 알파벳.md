# 1987. 알파벳



## 문제

세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.

말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다. 즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.

좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다.

## 입력

첫째 줄에 R과 C가 빈칸을 사이에 두고 주어진다. (1<=R,C<=20) 둘째 줄부터 R개의 줄에 걸쳐서 보드에 적혀 있는 C개의 대문자 알파벳들이 빈칸 없이 주어진다.

## 출력

첫째 줄에 말이 지날 수 있는 최대의 칸 수를 출력한다.



- DFS를 이용한 4방향 탐색. 최근에 DFS+DP문제를 풀어서 DP를 적용하려다가 틀렸습니다를 맛보고 정직하게 4방향 탐색했다. 알파벳은 총 26개이기 때문에 방문을 체크하는 배열을 그만큼 선언해주고 체크해주면 된다.

- 주의할 만한 사항은 딱히 없었다. 4방향 탐색 조건문에 오타를 넣어 4번 틀린 것 말고는...

- ```C++
  #include <iostream>
  using namespace std;
  
  typedef struct DIR{
  	int r,c;
  };
  DIR dir[4]={{1,0},{-1,0},{0,1},{0,-1}};
  int n,m,dp[21][21],ans;
  string str[21];
  bool check[26];
  
  void dfs(int r,int c,int cnt){
  	ans=max(ans,cnt);
  	for(int i=0;i<4;i++){
  		int nr=r+dir[i].r;
  		int nc=c+dir[i].c;
  		if(0<=nr&&nr<n&&0<=nc&&nc<m&&!check[(int)str[nr][nc]-'A']){
  			check[(int)str[nr][nc]-'A']=true;
  			dfs(nr,nc,cnt+1);
  			check[(int)str[nr][nc]-'A']=false;
  		}
  	}
  }
  
  int main(){
  	cin>>n>>m;
  	for(int i=0;i<n;i++){
  		cin>>str[i];
  	}
  	check[(int)str[0][0]-'A']=1;
  	dfs(0,0,1);
  	cout<<ans;
  }
  ```

  