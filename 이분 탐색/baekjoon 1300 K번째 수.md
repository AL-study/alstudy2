# 1300. K번째 수

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| :-------- | :---------- | :--- | :--- | :-------- | :-------- |
| 2 초      | 128 MB      | 7218 | 2451 | 1820      | 38.267%   |

## 문제

세준이는 크기가 N×N인 배열 A를 만들었다. 배열에 들어있는 수 A[i][j] = i×j 이다. 이 수를 일차원 배열 B에 넣으면 B의 크기는 N×N이 된다. B를 오름차순 정렬했을 때, B[k]를 구해보자.

배열 A와 B의 인덱스는 1부터 시작한다.

## 입력

첫째 줄에 배열의 크기 N이 주어진다. N은 105보다 작거나 같은 자연수이다. 둘째 줄에 k가 주어진다. k는 min(109, N2)보다 작거나 같은 자연수이다.

## 출력

B[k]를 출력한다.



-  k번째 수는 1열에 대해 나눈 수(k/1)+ 2열에 대해 나눈 수(k/2) +... i열에
  대해 나눈 수+(k/i)로 구할 수 있다. 단, 몫이 n보다 큰 경우는 그 개수가
  N개인 것과 동일하다.

- ```c++
  #include <iostream>
  #include <algorithm>
  using namespace std;
  int n,k,ans;
  
  int main(){
  	cin>>n>>k;
  	int low=1;
  	int high=k;
  	while(low<=high){
  		int mid=(low+high)/2;
  		int cnt=0;
  		for(int i=1;i<=n;i++){
  			cnt+=min(mid/i,n);
  		}
  		if(cnt<k) low=mid+1;
  		else{
  			ans=mid;
  			high=mid-1;
  		}
  	}
  	cout<<ans;
  }
  ```

  