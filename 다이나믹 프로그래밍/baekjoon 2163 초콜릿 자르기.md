### 2163. 초콜릿 자르기

- 수학문제.

- n x m 크기의 초콜릿이 있을 경우

  - 세로로 가로가 1크기의 초콜릿으로 자르면 m-1번만에 나눌수 있다.
  - n x 1 크기의 조각을 1x1크기로 자를려면 n-1번만에 나눌수 있다.
  - m개있기 떄문에 m(n-1)번이고 m-1을 더해주면 결과값이다. 그러므로 mn-1이 답이된다.

- ```c++
  #include <iostream>
  using namespace std;
  int main(){
  	int n,m;
  	cin>>n>>m;
  	cout<<m*n-1;
  }
  ```

  

