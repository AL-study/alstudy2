### 9461. 파도반 수열

- 나선 모양을 유지하며 증가하는 n번째 정삼각형의 한변의 길이를 구하는 문제.

- 그림만 보면 어려워보이지만 (~~시공으로 빨려 들어갑니다~~) 삼각형이 생성되는 규칙을 보면 n번째 삼각형은 n-1번째 삼각형과 n-5번째 삼각형의 변을 합쳐서 만들어진다는 것을 알 수 있다.

- 따라서 점화식은 dp[n]=dp[n-1]+dp[n-5]

- 그러나 이렇게만 설정하면 틀리게된다. 생각보다 범위가 크기 때문에 int형을 초과하기 때문이다. 따라서 long long으로 설정하자.

- ```c++
  #include <iostream>
  using namespace std;
  int t,n;
  long long dp[101];
  int main(){
  	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	cin>>t;
  	dp[1]=1;
  	dp[2]=1;
  	dp[3]=1;
  	dp[4]=2;
  	dp[5]=2;
  	for(int i=6;i<=100;i++){
  		dp[i]=dp[i-1]+dp[i-5];
  	}
  	for(int i=0;i<t;i++){
  		cin>>n;
  		cout<<dp[n]<<"\n";
  	}
  } 
  ```

  