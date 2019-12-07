### 5557. 1학년

- 주어진 배열 사이에 -, + 기호를 붙이며 마지막 = 기호를 붙였을 때 등식이 성립하는 경우의 수를 구하는 문제.

- dp를 정의하는 것이 어려웠던 문제. 항상 0이상, 20이하의 조건을 만족해야 하기때문에 이전의 수를 저장하고 있어야한다. 따라서 dp의 정의는 다음과 같다

   `dp[i][j]= 1번째부터 i번째까지 부호를 넣어 계산했을 때 j값이 나온 경우의 수이다. `

- 또한 범위는 2^63-1 이하의 값이기 때문에 int형을 초과하기 때문에 `long long` 으로 정의해야 한다.

- ```c++
  #include <iostream>
  using namespace std;
  int n,arr[101];
  long long dp[101][21];
  int main(){
  	cin>>n;
  	for(int i=1;i<=n;i++){
  		cin>>arr[i];
  	}
  	dp[1][arr[1]]++;
  	for(int i=2;i<n;i++){
  		for(int j=0;j<=20;j++){
  			if(dp[i-1][j]){
  				if(j+arr[i]<=20&&0<=j+arr[i]){
  					dp[i][j+arr[i]]+=dp[i-1][j];
  				}
  				if(j-arr[i]<=20&&0<=j-arr[i]){
  					dp[i][j-arr[i]]+=dp[i-1][j];
  				}
  			}
  		}
  	}
  	cout<<dp[n-1][arr[n]];
  }
  ```

  