### 11050. 이항 계수 1



#### 문제

자연수 N과 정수 K가 주어졌을 때 이항 계수 (N K)를 구하는 프로그램을 작성하시오.

#### 입력

첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 0 ≤ K ≤ N)



- 이항계수 n, k 를 구하는 문제. 

- 이항계수 (n, k) = n! / (k!*(n-k)!) 으로 풀 수 있다. 조합과 같다.

- ```c++
  #include <iostream>
  using namespace std;
  
  int n,k;
  int main() {
  	cin>>n>>k;
  	int num1=1;
  	int num2=1;
  	for(int i=n;i>0;i--){
  		num1*=i;
  	}
  	for(int i=k;i>0;i--){
  		num2*=i;
  	}
  	for(int i=n-k;i>0;i--){
  		num2*=i;
  	}
  	cout<<num1/num2;
  }
  
  ```

  