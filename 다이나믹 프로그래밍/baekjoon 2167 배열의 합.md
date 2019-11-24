### 2167. 배열의 합

- (i,j)부터 (x,y)위치까지 배열에 저장되어 있는 수들의 합을 구하는 문제
- 완전탐색으로 접근하면 3중포문이 나온다. 시간복잡도를 줄이기 위해 다이나믹 프로그래밍으로 접근한다.
- DP의 정의에 따라 답이 다를수 있다는 생각이든다. 여기선 DP를 **(1,1)부터 (i,j)까지의 배열의 합**이라고 정의했다. 문제에선 1,1을 첫 인덱스로 보고있기 떄문에 인덱스를 (1,1)부터 시작했다. (실제로는 0인덱스도 참조하기 떄문에 이렇게 설정하는 것이 좋다.)
- 점화식은 `dp[i][j]=dp[i][j-1]+dp[i-1][j]+arr[i][j]-dp[i-1][j-1]`이다.
- 그럼 (i,j)부터 (x,y)까지의 합은 어떻게 구할 수 있을까? 아래의 그림을 보자.

![](https://t1.daumcdn.net/cfile/tistory/99311E335A68D88424)

#### 그림 출처:  https://lmcoa15.tistory.com/14 

- 회색과 빨간색을 합친 전체영역에서 회색구간을 빼면된다. 가로행을 빼고, 세로열을 빼고, 가로행과 세로열의 겹친부분을 2번 뺏기때문에 1번 더해주면된다.

- 따라서 답은 `dp[end_x][end_y]-dp[end_x][start_y-1]-dp[start_x-1][end_y]+dp[start_x-1][start_y-1]`

- ```c++
  #include <iostream>
  using namespace std;
  int n,m,dp[301][301],k,arr[301][301];
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	cin>>n>>m;
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=m;j++){
  			cin>>arr[i][j];
  		}
  	}
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=m;j++){
  			dp[i][j]=dp[i][j-1]+dp[i-1][j]+arr[i][j]-dp[i-1][j-1];
  		}
  	}
  	cin>>k;
  	for(int i=0;i<k;i++){
  		int start_x,start_y,end_x,end_y;
  		cin>>start_x>>start_y>>end_x>>end_y;
  		cout<<dp[end_x][end_y]-dp[end_x][start_y-1]-dp[start_x-1][end_y]+dp[start_x-1][start_y-1]<<"\n";
  	}
  }
  ```

  