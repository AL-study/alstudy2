### 11048. 이동하기

- (1,1)에서 (n,m)까지 이동하면서 가질 수 있는 사탕개수의 최대값을 구하는 문제.
- 미로라는 단어가 나오면 백트래킹(DFS,BFS)를 떠올리기 쉽다. 하지만 문제의 조건에는 4방향을 탐색하지 않는다. (R+1,C) (R,C+1),(R+1,C+1)로 오른쪽, 아래, 대각선 3가지 방향으로만 움직일수 있다. 즉, **전진만 가능하다.**

- 따라서 다이나믹 프로그래밍으로 접근할 수 있다. **첫번째 행과 첫번째 열은 경로가 하나뿐이다.** DP배열을 초기화할 때 저장해주자.

- ```C++
  #include <iostream>
  using namespace std;
  int n,m,dp[1001][1001],arr[1001][1001];
  int main(){
  	cin>>n>>m;
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=m;j++){
  			cin>>arr[i][j];
  		}
  	}
  	for(int i=1;i<=n;i++){
  		dp[i][1]=arr[i][1];
  	}
  	for(int i=1;i<=m;i++){
  		dp[1][i]=arr[1][i];
  	}
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=m;j++){
  			dp[i][j]=max(dp[i][j-1]+arr[i][j],dp[i-1][j]+arr[i][j]);
  		}
  	}
  	cout<<dp[n][m];
  }
  ```

  