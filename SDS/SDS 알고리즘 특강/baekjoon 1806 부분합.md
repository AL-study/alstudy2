### 1806. 부분합



#### 문제

10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다. 이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.

#### 입력

첫째 줄에 N (10 ≤ N < 100,000)과 S (0 < S ≤ 100,000,000)가 주어진다. 둘째 줄에는 수열이 주어진다. 수열의 각 원소는 공백으로 구분되어져 있으며, 10,000이하의 자연수이다.



- 투 포인터의 개념을 연습할 수 있는 좋은 문제. 단순하게 접근하면 n^2만큼 걸리지만 투 포인터를 활용하여 시간복잡도를 n으로 줄일수가 있다.

- ```c++
  #include <iostream>
  using namespace std;
  
  int s,e,n,arr[100000],m,sum,ans=987654321;
  
  int main(){
  	cin>>n>>m;
  	for(int i=0;i<n;i++){
  		cin>>arr[i];
  	}
  	while(1){
  		if(sum>=m){
  			sum-=arr[s++];
  		}else if(n==e){
  			break;
  		}else{
  			sum+=arr[e++];
  		}
  		if(sum>=m){
  			ans=min(ans,e-s);
  		}
  	}
  	
  	if(ans==987654321){
  		cout<<0;
  	}else{
  		cout<<ans;
  	}
  	
  	
  }
  ```

  