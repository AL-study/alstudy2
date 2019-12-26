### 2003. 수들의 합2



#### 문제

N개의 수로 된 수열 A[1], A[2], …, A[N] 이 있다. 이 수열의 i번째 수부터 j번째 수까지의 합 A[i]+A[i+1]+…+A[j-1]+A[j]가 M이 되는 경우의 수를 구하는 프로그램을 작성하시오.

#### 입력

첫째 줄에 N(1≤N≤10,000), M(1≤M≤300,000,000)이 주어진다. 다음 줄에는 A[1], A[2], …, A[N]이 공백으로 분리되어 주어진다. 각각의 A[x]는 30,000을 넘지 않는 자연수이다.



- 투 포인터의 hello world격 문제.

- 사실 이 문제는 O(n^2)으로도 풀린다. 물론 완전탐색을 돌리듯이 n^2을 돌리는 것은 아니지만 엄밀히 따지면 O(n^2)이다. 투 포인터를 적용하지 않은 상태로 풀면 코드는 다음과 같다.

- ```c++
  #include <iostream>
  using namespace std;
  int n,arr[100000],m,ans;
  int main(){
  	cin>>n>>m;
  	for(int i=0;i<n;i++){
  		cin>>arr[i];
  	}
  	for(int i=0;i<n;i++){
  		int num=0;
  		for(int j=i;j<n;j++){
  			num+=arr[j];
  			if(num==m){
  				ans++;
  				break;
  			}
  			else if(num>m){
  				break;
  			}
  		}
  	}
  	cout<<ans;
  }
  ```

- 그러나 이러한 풀이는 n이 10,000이 아닌 100,000이라면 시간초과로 풀 수 없다. 10,000일때 걸리는 시간은 28ms.

- 투 포인터를 이용하여 접근하면 O(n)에 해결할 수 있다. 탈출조건은 e==n일때 break 즉, e가 마지막 인덱스를 넘어선 순간이다. 걸리는 시간 역시 4ms로 매우 짧다.

- ```c++
  #include <iostream>
  using namespace std;
  int n,arr[100000],m,ans;
  int main(){
  	cin>>n>>m;
  	for(int i=0;i<n;i++)cin>>arr[i];
  	int s=0,e=0,sum=0;;
  	while(1){
  		if(sum>=m)sum-=arr[s++];
  		else if(e==n)break;
  		else sum+=arr[e++];
  		if(sum==m)ans++;
  	}
  	cout<<ans;
  }
  ```

  

