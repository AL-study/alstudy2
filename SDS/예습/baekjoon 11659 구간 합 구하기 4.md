### 11659. 구간 합 구하기 4



#### 문제

수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.

#### 입력

첫째 줄에 수의 개수 N (1 ≤ N ≤ 100,000), 합을 구해야 하는 횟수 M (1 ≤ M ≤ 100,000)이 주어진다. 둘째 줄에는 N개의 수가 주어진다. 수는 1,000보다 작거나 같은 자연수이다. 셋째 줄부터 M개의 줄에는 합을 구해야 하는 구간 i와 j가 주어진다.



- i부터 j까지의 구간 합을 구하는 문제.

- 구간 합을 구하기 위해 다이나믹 프로그래밍 기법을 이용하여 첫번째부터 i번째까지의 합을 저장할 배열 sum을 정의해 값을 메모이제이션하여 저장한다.

- 이후 i부터 j까지의 구간 합은 `sum[j]-sum[i-1]`로 구할 수 있다.

- ```c++
  #include <iostream>
  using namespace std;
  int n,m,arr[100001],sum[100001];
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	cin>>n>>m;
  	for(int i=1;i<=n;i++){
  		cin>>arr[i];
  	}
  	for(int i=1;i<=n;i++){
  		sum[i]=sum[i-1]+arr[i];
  	}
  	for(int i=0;i<m;i++){
  		int a,b;
  		cin>>a>>b;
  		cout<<sum[b]-sum[a-1]<<"\n";
  	}
  }
  ```

  