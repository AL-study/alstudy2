# 1038. 감소하는 수

## 문제

음이 아닌 정수 X의 자릿수가 가장 큰 자릿수부터 작은 자릿수까지 감소한다면, 그 수를 감소하는 수라고 한다. 예를 들어, 321과 950은 감소하는 수지만, 322와 958은 아니다. N번째 감소하는 수를 출력하는 프로그램을 작성하시오. 0은 0번째 감소하는 수이고, 1은 1번째 감소하는 수이다. 만약 N번째 감소하는 수가 없다면 -1을 출력한다.

## 입력

첫째 줄에 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수 또는 0이다.

## 출력

첫째 줄에 N번째 감소하는 수를 출력한다.



- 감소하는 수의 최대 값은 9876543210으로 약 100억정도이다. 따라서 for문으로 완전 탐색을 하는 방식은 시간초과로 실패한다.

- 따라서 다른 방식을 생각해야하는데, 큐를 이용한 방식으로 문제를 풀었다. 초기값인 1~9를 큐에 푸쉬해주고, 차례로 꺼내면서 감소하는 모든 수를 만들어주고 push하는 방식이다.

- ```c++
  #include <iostream>
  #include <queue>
  using namespace std;
  int n,cnt=9;
  queue<long long> q;
  int main(){
  	cin>>n;
  	if(0<=n&&n<=9){
  		cout<<n;
  		return 0;
  	}
  	for(int i=1;i<=9;i++){
  		q.push(i);
  	}
  	while(cnt<n){
  		long long target=q.front();
  		q.pop();
  		int num=target%10;
  		for(int i=0;i<num;i++){
  			q.push(target*10+i);
  			cnt++;
  			if(cnt==n){
  				cout<<target*10+i;
  				return 0;
  			}else if(target*10+i==9876543210){
  				cout<<-1;
  				return 0;
  			}
  		}	
  	}
  }
  ```

  