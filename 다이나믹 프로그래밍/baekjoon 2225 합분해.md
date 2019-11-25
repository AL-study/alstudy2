### 2225. 합분해

- 0부터 n까지의 정수 k개를 더해서 그 합이 n이 되는 경우의 수를 구하는 문제.

- 규칙을 찾는 것이 쉽지 않았다. 이렇게 바로 규칙이 나오지 않는 경우는 가지수를 그려보거나 그림을 그리며 유추하는 것이 도움이 된다.

- 점화식은 다음과 같다. `dp[k][n]=dp[k-1][n]+dp[k-1][n-1]+...+dp[k-1][1]+dp[k-1][0]`

- 이러한 경우 `dp[k][n]`값을 구하기위해서는 `dp[k][0]`부터 값을 차례로 구해야하기 때문에 3중 for문을 써야한다.  

- ```c++
  #include <iostream>
  using namespace std;
  int n,k,dp[201][201];
  int main(){
  	cin>>n>>k;
  	for(int i=1;i<=n;i++){
  		dp[1][i]=1;
  		dp[2][i]=i+1;
  	}
  	for(int i=0;i<=k;i++){
  		dp[i][0]=1;
  	}
  	for(int i=3;i<=k;i++){
  		for(int j=1;j<=n;j++){
  			for(int l=0;l<=j;l++){
  				dp[i][j]=(dp[i][j]+dp[i-1][l])%1000000000;
  			}
  		}
  	}
  	cout<<dp[k][n];
  } 
  ```

  