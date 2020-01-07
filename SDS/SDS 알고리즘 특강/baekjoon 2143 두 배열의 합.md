### 2143. 두 배열의 합



#### 문제

한 배열 A[1], A[2], …, A[n]에 대해서, 부 배열은 A[i], A[i+1], …, A[j-1], A[j] (단, 1 ≤ i ≤ j ≤ n)을 말한다. 이러한 부 배열의 합은 A[i]+…+A[j]를 의미한다. 각 원소가 정수인 두 배열 A[1], …, A[n]과 B[1], …, B[m]이 주어졌을 때, A의 부 배열의 합에 B의 부 배열의 합을 더해서 T가 되는 모든 부 배열 쌍의 개수를 구하는 프로그램을 작성하시오.

예를 들어 A = {1, 3, 1, 2}, B = {1, 3, 2}, T=5인 경우, 부 배열 쌍의 개수는 다음의 7가지 경우가 있다.

```
T(=5) = A[1] + B[1] + B[2]
      = A[1] + A[2] + B[1]
      = A[2] + B[3]
      = A[2] + A[3] + B[1]
      = A[3] + B[1] + B[2]
      = A[3] + A[4] + B[3]
      = A[4] + B[2] 
```

#### 입력

첫째 줄에 T(-1,000,000,000 ≤ T ≤ 1,000,000,000)가 주어진다. 다음 줄에는 n(1 ≤ n ≤ 1,000)이 주어지고, 그 다음 줄에 n개의 정수로 A[1], …, A[n]이 주어진다. 다음 줄에는 m(1≤m≤1,000)이 주어지고, 그 다음 줄에 m개의 정수로 B[1], …, B[m]이 주어진다. 각각의 배열 원소는 절댓값이 1,000,000을 넘지 않는 정수이다.



- 투 포인터 개념을 응용한 문제. 하나의 배열에 대해 포인터를 이용하여 원하는 값을 구했던 기본 문제와는 달리 2개의 배열에 대한 합을 구해야 한다.

- 부분 합을 모두 구해 벡터에 넣고, 벡터를 정렬 시킨 후 각 벡터의 끝과 시작인덱스부터 투 포인터 개념을 적용하여 해결한다.

- 투 포인터 문제는 이분 탐색으로 풀 수 있는데, 이분 탐색으로 접근할 경우, 똑같이 부분 합을 구하고, 하나의 벡터만 정렬 시킨후, 정렬하지 않은 벡터에 대해 해당 값과 정렬한 벡터와 이분탐색을 통해 값을 비교한다.

- ```c++
  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;
  
  int t,n,m,arr[1000],arr2[1000];
  long long ans;
  vector<int> v1,v2;
  int main(){
  	cin>>t>>n;
  	for(int i=0;i<n;i++){
  		cin>>arr[i];
  	}
  	cin>>m;
  	for(int i=0;i<m;i++){
  		cin>>arr2[i];
  	}
  	for(int i=0;i<n;i++){
  		int sum=0;
  		for(int j=i;j<n;j++){
  			sum+=arr[j];
  			v1.push_back(sum);
  		}
  	}
  	for(int i=0;i<m;i++){
  		int sum=0;
  		for(int j=i;j<m;j++){
  			sum+=arr2[j];
  			v2.push_back(sum);
  		}
  	}
  	sort(v1.begin(),v1.end());
  	sort(v2.begin(),v2.end());
  	int p1=0,p2=v2.size()-1;
  	while(1){
  		if(v1[p1]+v2[p2]==t){
  			long long cnt1=1;
  			long long cnt2=1;
  			while(p1+1<=v1.size()-1&&v1[p1]==v1[p1+1]){
  				p1++;
  				cnt1++;
  			}
  			while(p2-1>=0&&v2[p2]==v2[p2-1]){
  				p2--;
  				cnt2++;
  			}
  			ans+=cnt1*cnt2;
  			p1++;
  		}
  		if(p2>=0&&p1<=v1.size()-1&&v1[p1]+v2[p2]<t){
  			p1++;	
  		}
  		if(p2>=0&&p1<=v1.size()-1&&v1[p1]+v2[p2]>t){
  			p2--;
  		}
  		if(p1>v1.size()-1||p2<0){
  			break;
  		}
  	}
  	cout<<ans;
  }
  ```

  

