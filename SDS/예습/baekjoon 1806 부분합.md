### 1806. 부분합



#### 문제

10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다. 이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.

#### 입력

첫째 줄에 N (10 ≤ N < 100,000)과 S (0 < S ≤ 100,000,000)가 주어진다. 둘째 줄에는 수열이 주어진다. 수열의 각 원소는 공백으로 구분되어져 있으며, 10,000이하의 자연수이다.



- 단순하게 접근하면 for문을 2개이용하여 풀 수 있지만 n이 10만개이기 때문에 시간초과가 발생한다. 따라서 투 포인터로 접근해야 한다.

- 똑같이 접근하되, 종료조건은 `e==n`일 경우 `break`하고 갯수를 셀 때 e-s로 인덱스간 거리를 구해준다.

- ```c++
  #include <iostream>
  using namespace std;
  int n,arr[100000],m,ans=1000000;
  int main(){
  	cin>>n>>m;
  	for(int i=0;i<n;i++) cin>>arr[i];
  	int s=0,e=0,sum=0;
  	while(1){
  		if(sum>=m)sum-=arr[s++];
  		else if(e==n)break;
  		else sum+=arr[e++];
  		if(sum>=m) ans=min(ans,e-s);
  	}
  	if(ans==1000000){
  		cout<<0;
  	}else{
  		cout<<ans;
  	}
  }
  ```

  