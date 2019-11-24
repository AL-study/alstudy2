### 2294. 동전 2

- [1로 만들기]( https://www.acmicpc.net/problem/1463 )문제의 상위 호환 버전. 3가지가 아닌 입력받은 배열만큼을 비교해준다.

- 주의 사항으로는 동전의 가치는 10만이기 때문에 dp[100001]로 선언해야 하고 n역시 1~100이기때문에 arr[101]로 선언해야한다. 또한 **i-arr[j]>=1일 경우에만 비교**해야 한다. (인덱스는 -가 될 수 없기 때문)
  마지막으로 dp는 최대값으로 초기화 시켜야한다. (최소값을 원하기 때문)

- ```c++
  #include <iostream>
  using namespace std;
  int n,k,dp[100001],arr[101];
  int main(){
  	cin>>n>>k;
  	for(int i=1;i<=k;i++){
  		dp[i]=1000000;
  	}
  	for(int i=1;i<=n;i++){
  		cin>>arr[i];
  		dp[arr[i]]=1;
  	}
  	for(int i=1;i<=k;i++){
  		for(int j=1;j<=n;j++){
  			if(i-arr[j]>=1){
  				dp[i]=min(dp[i],dp[i-arr[j]]+1);
  			}	
  		}
  	}
  	if(dp[k]==1000000){
  		cout<<-1;
  	}else{
  		cout<<dp[k];
  	}
  }
  ```

  