### 1890. 점프

- (1,1)부터 (n,n)까지의 경우의 수를 구하는 문제.

- 오른쪽이나 아래로만 움직일 수 있기때문에 **항상 증가**한다. 따라서 **움직였을때의 인덱스는 n보다 작아야한다.**

- 조건에 따라 dp배열의 범위가 int를 초과할 수 있으므로 `long long`으로 선언한다.

- ```c++
  #include <iostream>
  using namespace std;
  int n,arr[100][100];
  long long dp[100][100];
  int main(){
  	cin>>n;
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			cin>>arr[i][j];
  		}
  	}
  	dp[0][0]=1;
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			if(dp[i][j]==0||(arr[i][j]==0)){
  				continue;
  			}
  			int cnt=arr[i][j];
  			if(i+cnt<n){
  				dp[i+cnt][j]+=dp[i][j];
  			}
  			if(j+cnt<n){
  				dp[i][j+cnt]+=dp[i][j];
  			}
  		}
  	}
  	cout<<dp[n-1][n-1];
  }
  ```

  