### 11055. 가장 큰 증가 부분 수열

- 가장 큰 증가 부분 수열합의 최대값을 구하는 문제.
- dp[i]=arr[i]로 초기화 이후, 해당 인덱스의 이전 인덱스를 탐색하면서 arr값이 작을 경우 `dp[i]=max(dp[i],dp[j]+arr[i])`로 판별한다.

- ```c++
  #include <iostream>
  using namespace std;
  int n,arr[1001],dp[1001],ans;
  int main(){
  	cin>>n;
  	for(int i=0;i<n;i++){
  		cin>>arr[i];
  	}
  	dp[0]=arr[0];
  	for(int i=1;i<n;i++){
  		dp[i]=arr[i];
  		for(int j=0;j<i;j++){
  			if(arr[i]>arr[j]){
  				dp[i]=max(dp[i],dp[j]+arr[i]);
  			}
  		}
  	}
  	for(int i=0;i<n;i++){
  		ans=max(ans,dp[i]);
  	}
  	cout<<ans;
  }
  ```

  