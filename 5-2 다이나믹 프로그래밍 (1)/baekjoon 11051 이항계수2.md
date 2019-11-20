### 11051. 이항계수

- 이항 계수의 규칙을 알면 쉽게 풀리는 문제. **이미지 출처: https://samtoring.com/qstn/QST0026495.png **

![이항계수의 규칙](http://melonicedlatte.com/system/uploads/images/000/001/468/original/image.png?1537897825 )

- 따라서 점화식은 `dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%10007`

- ```c++
  #include <iostream>
  using namespace std; 
  int n,k,dp[1001][1001];
  int main() {
  	cin>>n>>k;
      for(int i=1;i<=n;i++){
          for(int j=0;j<=n;j++){
              if(i==j||j==0){
                  dp[i][j]=1; 
  				continue;
              }
              dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%10007;
          }
      }
      cout<<dp[n][k];
  }
  
  ```

  