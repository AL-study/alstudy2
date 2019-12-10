### 2302. 극장좌석 ★

- 한 줄로 되어있는 극장좌석이 있을 때, 바꿀수 없는 VIP석을 고려하여 앉을 수 있는 경우의 수를 구하는 문제.

- 수를 나열해보면 어렵지 않게 점화식을 유추할 수 있다. 점화식은 다음과 같다.
   `dp[i]=dp[i-1]+dp[i-2]`

- 그러나 vip석이 있을 경우 바꿀수 없기 때문에 이 경우를 처리하는 것이 핵심이었다.  VIP석을 입력받는다면 시작 ~ VIP-1 사이의 경우의 수 + VIP-2~ VIP-3 사이의 경우의 수 +...+ VIP-M~마지막 좌석까지의 경우의 수로 구할 수 있다. 이 부분을 생각하는 것이 어려웠던 문제.

- ```c++
  #include<iostream>
  using namespace std;
  
  int n,m,dp[41],s,e,ans=1;
  
  int solve(int N){
      if (N <=2) return 1;
      if (dp[N] > 0) return dp[N];
      return dp[N] = solve(N - 1) + solve(N - 2);
  }
  int main()
  {
      cin>>n>>m;
      for (int i=1;i<=m;i++)
      {
          cin>>s;
          ans*=solve(s-e);
          e=s;
      }
      ans=ans*solve(n+1-e);
      cout<<ans;
  }
  
  ```

  