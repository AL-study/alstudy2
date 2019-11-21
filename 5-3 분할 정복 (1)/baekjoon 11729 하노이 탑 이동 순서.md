### 11729. 하노이 탑 이동 순서 ★★

- 총 3개의 장대가 있고 1번 장대에 쌓인 K개의 원판을 3번장대로 모두 옮길때의 횟수와, 순서를 구하는문제.

- 20줄의 코드가 이렇게 해석하기 어려운줄 몰랐다. 재귀함수는 항상 어려운 것 같다. 분할과 정복의 대표 문제.

- 먼저 하노이 탑의 최소 이동횟수는 K^2-1이기 때문에 어렵지 않게 구할 수 있다.

- 1번 장대에 쌓여있는 모든 원판을 3번 장대롤 이동시키기 위해서 3가지 순서로 쪼갠다.

  1. 마지막 K개를 제외한 K-1번째부터 1번째까지의 원판들을 2번장대로 옮긴다.
  2. 마지막남은 K번째의 막대를 3번장대로 옮긴다.
  3. 2번장대에 있는 K-1번째부터 1번째까지의 원판들을 3번장대로 옮긴다.

- 분할과 정복은 개념은 쉬워도 막상 문제를 풀어보면 전혀 쉽지않다. 많은 연습이 필요할 것 같다.

- ```C++
  #include <iostream>
  #include <math.h>
  using namespace std;
  int n;
  // 1번째부터 target번째까지 원판들을 from번 장대에서 to번 장대로 옮긴다. none는 목표가 아닌
  // 장대이다. 문제에선 none이 2번장대이다. (3번장대로 옮겨야하므로)
  void dc(int target,int from,int to,int none){
  	if(target==1){
  		cout<<from<<" "<<to<<"\n";
  	}
  	else{
  		dc(target-1,from,none,to);  //1.과정
  		dc(1,from,to,none);			//2.과정
  		dc(target-1,none,to,from);	//3.과정
  	}
  }
  int main(){
  	cin>>n;
  	int cnt=pow(2,n)-1;
  	cout<<cnt<<"\n";
  	dc(n,1,3,2);
  }
  ```

  #### 참고 출처 :   https://junho0956.tistory.com/33 

