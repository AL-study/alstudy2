### 11653. 소인수분해



#### 문제

정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.

#### 입력

첫째 줄에 정수 N (1 ≤ N ≤ 10,000,000)이 주어진다.



- 현실에서 소인수분해를 하려면 여러 가지 방법들이 존재하지만, 알고리즘에선 그럴 필요가 없다. 2부터 시작하여 하나씩 증가시키면서 값을 나눠주면 되기 때문이다.

- ```c++
  #include <iostream>
  #include <vector>
  using namespace std;
  int n;
  vector<int> v;
  int main(){
  	cin>>n;
  	while(n!=1){
  		for(int i=2;i<=n;i++){
  			if(n%i==0){
  				v.push_back(i);
  				n/=i;
  				break;
  			}
  		}
  	}
  	for(int i=0;i<v.size();i++){
  		cout<<v[i]<<"\n";
  	}
  }
  ```

  