### 9084. 동전

- 동전의 개수와 단위, 금액이 주어졌을때 만들수 있는 경우의 수를 구하는 문제.

- bottom-up 방식으로 dp배열을 이용하여 구하려는 금액까지 구한다. 해당 금액이 동전의 단위보다 커야하므로 점화식이 간단하게 나오진 않는다. 이 부분을 2중 for문을 이용해서 구해주자.

- ```c++
  #include <iostream>
  using namespace std;
  int t,n,arr[21],money;
  int main(){
  	cin>>t;
  	for(int i=0;i<t;i++){
  		cin>>n;
  		for(int j=1;j<=n;j++){
  			cin>>arr[j];
  		}
  		cin>>money;
  		int dp[10001]={0};
  		dp[0]=1;
  		for(int j=1;j<=n;j++){
  			for(int k=arr[j];k<=money;k++){
  				dp[k]+=dp[k-arr[j]];
  			}
  		}
  		cout<<dp[money]<<"\n";
  	}
  }
  ```

  