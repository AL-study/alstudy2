### 10164. 격자상의 경로

- k번째 칸을 반드시 지나는 격자상의 경로를 구하는 문제.

- 먼저 격자상의 경로를 구하는 점화식을 구해본다. 어렵지 않게 유추할 수 있다. 위, 왼쪽의 경우의 수의 합이다.

- 따라서 `dp[i][j]=dp[i-1][j]+dp[i][j-1]`이다.

- 여기서 k번째는 반드시 지나가야한다.경우의 수를 구해나가면서 k번째칸을 만나면 k번째에서 부터 다시 경우의 수를 구해나간다.

- ```c++
  #include <iostream>
  using namespace std;
  int n,m,k,dp[16][16],r=1,c=1;
  int main(){
  	cin>>n>>m>>k;
  	int cnt=0;
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=m;j++){
  			cnt++;
  			if(cnt==k){
  				r=i;
  				c=j;
  			}
  		}
  	}
  	dp[1][1]=1;
  	for(int i=1;i<=r;i++){
  		for(int j=1;j<=c;j++){
  			if(i==1&&j==1) continue;
  			dp[i][j]=dp[i-1][j]+dp[i][j-1];
  		}
  	}
  	for(int i=r;i<=n;i++){
  		for(int j=c;j<=m;j++){
  			if(i==r&&j==c) continue;
  			dp[i][j]=dp[i-1][j]+dp[i][j-1];
  		}
  	}
  	cout<<dp[n][m];
  }
  ```

  