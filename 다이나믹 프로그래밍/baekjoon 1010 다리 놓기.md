### 1010. 다리 놓기 ★★

- 점화식을 도출하기 어려웠던 문제. (~~dp인데 3중 for문이라니요 ㅠㅠ~~)

- 서로 다리를 겹치지 않게 놓아야하기 때문에 조건에 맞게 놓아야 한다. 점을 노드로, 다리를 간선으로 보면 마치 트리와 같다. 백트래킹이 연상된다. M개의 점에서 N개를 택하는데 순서의 차이를 따지기 때문에 조합의 경우이다. mCr로 구할 수 있지만 dp의 개념을 확실히 하기위해 dp로 접근해보자. 

- **식을 나열하며 규칙을 유추하기가 쉽지 않다**. **그림을 그려서 규칙을 유추하는것이 이해가 더 빠르다.** 참고 출처의 sho59님의 블로그에 그림을 통한 설명이 매우 잘 되어있다. 

- 점화식은 ` dp[N][M] = dp[N-1][M-1] + dp[N-1][M-2] + ... + dp[N-1][N-1]  `이다. 

- ```c++
  #include <iostream>
  
  using namespace std;
  int t,n,m,dp[31][31];
  int main(){
  	for(int i=1;i<=30;i++){
  		dp[1][i]=i;
  	}
  	for(int i=2;i<=30;i++){
  		for(int j=1;j<=30;j++){
  			for(int k=i-1;k<j;k++){
  				dp[i][j]+=dp[i-1][k];
  			}
  		}
  	}
  	cin>>t;
  	for(int i=0;i<t;i++){
  		cin>>n>>m;
  		cout<<dp[n][m]<<"\n";
  	}
  }
  ```

  

#### 참고 출처: [sho59님 블로그]( http://sioh59.blogspot.com/2017/01/baekjoon-1010-dynamic-programming.html )

