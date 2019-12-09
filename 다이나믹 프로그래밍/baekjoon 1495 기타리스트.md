### 1495. 기타리스트

- 곡의 개수 N과 시작 볼륨 S, 최대값 M이 주어졌을 때, 마지막 곡 볼륨의 최댓값을 구하는 문제.

- 최대값 M의 범위가 0부터 1000으로 크지 않기 때문에 2차원 dp배열을 이용해 값을 구할 수 있다.
- `dp[i][j]= i번째 곡을 연주할 때 j크기의 볼륨으로 연주할 수 있는지 (true or false)저장한 배열`

- 점화식만 구한다면 어렵지 않게 구현할 수 있는 문제. 단, 마지막 곡을 연주할 수 없을 경우 -1을 출력해야 하기때문에, `ans=-1`부터 시작해야 한다.

- ```c++
  #include <iostream>
  using namespace std;
  int n,s,m,arr[101],ans=-1;
  bool dp[101][1001];
  int main(){
  	cin>>n>>s>>m;
  	for(int i=1;i<=n;i++){
  		cin>>arr[i];
  	}
  	dp[0][s]=true;
  	for(int i=1;i<=n;i++){
  		for(int j=0;j<=1000;j++){
  			if(dp[i-1][j]){
  				if(j+arr[i]<=m)dp[i][j+arr[i]]=true;
  				if(j-arr[i]>=0)dp[i][j-arr[i]]=true;
  			}
  		}
  	}
  	for(int j=1000;j>=0;j--){
  		if(dp[n][j]){
  			ans=j;
  			break;
  		}
  	}
  	cout<<ans;
  }
  ```

  