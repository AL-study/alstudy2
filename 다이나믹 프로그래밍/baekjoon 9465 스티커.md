### 9465. 스티커

- 2개의 행으로 나뉘어있기 때문에 각 행별 DP값을 구한다.

- 예제를 보면 알겠지만 **항상 왼쪽 대각선을 선택한다고 (무조건 많은 수의 스티커를 뽑는다고) 최고점을 뽑는 것은 아니다.** n-1열과 n-2열까지 비교해서 DP배열을 채워넣어주고 마지막에 `DP[1][N]`과 `DP[2][N]`의 최대값을 출력해준다.

- ```C++
  #include <iostream>
  using namespace std;
  int t,n,dp[3][100001],arr[3][100001];
  int main(){
  	cin>>t;
  	for(int i=0;i<t;i++){
  		cin>>n;
  		for(int j=1;j<=n;j++){
  			dp[1][j]=0;
  			dp[2][j]=0;
  		}
  		for(int j=1;j<=n;j++){
  			cin>>arr[1][j];
  		}
  		for(int j=1;j<=n;j++){
  			cin>>arr[2][j];
  		}
  		dp[1][1]=arr[1][1];
  		dp[2][1]=arr[2][1];
  		dp[1][2]=dp[2][1]+arr[1][2];
  		dp[2][2]=dp[1][1]+arr[2][2];
  		for(int j=3;j<=n;j++){
  			dp[1][j]=max(dp[2][j-2]+arr[1][j],dp[2][j-1]+arr[1][j]);
  			dp[2][j]=max(dp[1][j-2]+arr[2][j],dp[1][j-1]+arr[2][j]);
  		}
  		cout<<max(dp[1][n],dp[2][n])<<"\n";
  	}
  }
  ```