# 3085. 사탕 게임

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| :-------- | :---------- | :--- | :--- | :-------- | :-------- |
| 1 초      | 128 MB      | 8815 | 2767 | 2077      | 31.290%   |

## 문제

상근이는 어렸을 적에 "봄보니 (Bomboni)" 게임을 즐겨했다.

가장 처음에 N×N크기에 사탕을 채워 놓는다. 사탕의 색은 모두 같지 않을 수도 있다. 상근이는 사탕의 색이 다른 인접한 두 칸을 고른다. 그 다음 고른 칸에 들어있는 사탕을 서로 교환한다. 이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.

사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 보드의 크기 N이 주어진다. (3 ≤ N ≤ 50)

다음 N개 줄에는 보드에 채워져 있는 사탕의 색상이 주어진다. 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y로 주어진다.

사탕의 색이 다른 인접한 두 칸이 존재하는 입력만 주어진다.

## 출력

첫째 줄에 상근이가 먹을 수 있는 사탕의 최대 개수를 출력한다.



- 브루트 포스의 가장 큰 장점은 생각나는 대로(?) 짜도 된다는 것이다. 

- 테스트 케이스는 맞지만 틀렸습니다가 나올 경우,
  6
  CCYYCC
  YYCCYY
  CCYYCC
  YYCCYY
  CCYYCC
  YYCCYY

  를 해결해보기 바란다. 답은 3이다. 

- ```c++
  #include <iostream>
  using namespace std;
  
  string str[50];
  int n,ans;
  
  void check(){
  	for(int i=0;i<n;i++){
  		int num=1;
  		char temp=str[i][0];
  		for(int j=1;j<n;j++){
  			if(temp==str[i][j]){
  				num++;
  			}else{
  				ans=max(ans,num);
  				temp=str[i][j];	
  				num=1;
  			}
  		}
  		ans=max(ans,num);
  	}
  	for(int i=0;i<n;i++){
  		int num=1;
  		char temp=str[0][i];
  		for(int j=1;j<n;j++){
  			if(temp==str[j][i]){
  				num++;
  			}else{
  				temp=str[j][i];
  				ans=max(ans,num);
  				num=1;
  			}
  		}
  		ans=max(ans,num);
  	}
  }
  
  int main(){
  	cin>>n;
  	for(int i=0;i<n;i++){
  		cin>>str[i];
  	}
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			if(j!=n-1){
  				if(str[i][j]!=str[i][j+1]){
  					char temp=str[i][j];
  					str[i][j]=str[i][j+1];
  					str[i][j+1]=temp;
  					check();	
  					temp=str[i][j];
  					str[i][j]=str[i][j+1];
  					str[i][j+1]=temp;
  				}
  			}
  			if(i!=n-1){
  				if(str[i][j]!=str[i+1][j]){
  					char temp=str[i][j];
  					str[i][j]=str[i+1][j];
  					str[i+1][j]=temp;
  					check();	
  					temp=str[i][j];
  					str[i][j]=str[i+1][j];
  					str[i+1][j]=temp;
  				}
  			}
  		}
  	}
  	cout<<ans;
  }
  ```

  