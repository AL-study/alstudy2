### 11722. 가장 긴 감소하는 부분 수열 ★

- 가장 긴 증가하는 부분 수열과 같은 문제. 어떻게보면 좀 더 어려운문제라고 할 수 있다.

- 배열의 수가 1000이하이기 때문에 dp를 이용해 O(n^2)에 해결할 수 있다.

  1. 갯수는 항상  1이상(자기자신)이기 때문에 처음 dp배열을 1로 초기화한다.

  2. 해당인덱스보다 작은 인덱스를 탐색하면서 값이 크거나 같다면 dp값을 비교해 저장한다.
  3. 저장된 dp값중 최대값을 출력한다.

- ```c++
  #include <iostream>
  using namespace std;
  int n,arr[1001],dp[1001],ans;
  int main(){
  	cin>>n;
  	for(int i=1;i<=n;i++){
  		cin>>arr[i];
  	}
  	for(int i=1;i<=n;i++){
  		dp[i]=1;
  		for(int j=1;j<i;j++){
  			if(arr[i]<arr[j]){
  				dp[i]=max(dp[i],dp[j]+1);
  			}
  		}
  		ans=max(ans,dp[i]);
  	}
  	cout<<ans;
  }
  ```

- 그러나 배열의 수가 1000보다 크다면(ex.100만) 어떻게 해결해야할까?
  항상 해당 배열보다 작은 값을 탐색할 필요없이 배열에 값을 저장해두고 배열값만 참조하면서 배열만 갱신해주면 된다. 가장 긴 증가하는 부분 수열2문제와 같다. 그러나 감소하는 배열이기 때문에 lower_bound를 쓰지 못한다.

- 따라서 배열을 거꾸로 탐색해 해결한다. (reverse로 반전시켜서 해결할 수도 있다. reverse의 시간복잡도는 O(n))

- ```c++
  #include <iostream>
  #include <algorithm>
  #include <vector>
  using namespace std;
  int n,arr[1001];
  vector<int> v;
  vector<int>::iterator it;
  int main(){
  	cin>>n;
  	for(int i=0;i<n;i++){
  		cin>>arr[i];
  	}
  	reverse(arr,arr+n);
  	for(int i=0;i<n;i++){
  		if(v.empty()||v.back()<arr[i]){
  			v.push_back(arr[i]);
  		}else{
  			it=lower_bound(v.begin(),v.end(),arr[i]);
  			*it=arr[i];
  		}
  	}
  	cout<<v.size();
  }
  ```

  