### 2631. 줄세우기

- 아이들을 번호순으로 줄세우기 위해 옮겨야하는 최소 횟수를 구하는 문제.
- 무작위 수를 정렬하기 위해서 옮겨야하는 최소의 횟수를 어떻게 구해야 할까. 답은 LIS(Longest Increasing Subsequence) 최장 증가 부분 수열이다. 다시말해 이전에 풀었던 가장 긴 증가하는 부분수열 문제와 같다는 뜻이다. 문제의 테스트케이스를 보자. 3 7 5 2 6 1 4 중 LIS는 **3** 7 **5** 2 **6 **1 4 (3, 5, 6)으로 총 3개이다. 이제 이 수를 기준으로 나머지수를 한번씩 옮기면 정렬되게 된다. 줄세우는 과정이 LIS와 연관이 있다는 사실을 유추하는 과정이 어려웠던 문제.

- ```C++
  #include <iostream>
  using namespace std;
  int n,arr[201],dp[201],cnt;
  int main(){
  	cin>>n;
  	for(int i=0;i<n;i++){
  		cin>>arr[i];
  	}
  	for(int i=0;i<n;i++){
  		dp[i]=1;
  		for(int j=0;j<i;j++){
  			if(arr[i]>arr[j]){
  				dp[i]=max(dp[i],dp[j]+1);
  			}
  		}
  		cnt=max(cnt,dp[i]);
  	}
  	cout<<n-cnt;
  }
  ```

  