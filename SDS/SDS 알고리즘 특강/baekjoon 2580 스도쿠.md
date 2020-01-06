### 2580. 스도쿠



#### 문제

스도쿠는 18세기 스위스 수학자가 만든 '라틴 사각형'이랑 퍼즐에서 유래한 것으로 현재 많은 인기를 누리고 있다. 이 게임은 아래 그림과 같이 가로, 세로 각각 9개씩 총 81개의 작은 칸으로 이루어진 정사각형 판 위에서 이뤄지는데, 게임 시작 전 몇 몇 칸에는 1부터 9까지의 숫자 중 하나가 쓰여 있다.

![img](https://www.acmicpc.net/upload/images/jF1kwmQaGGRM3t9ESvpTvW34kCnB2.png)

나머지 빈 칸을 채우는 방식은 다음과 같다.

1. 각각의 가로줄과 세로줄에는 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
2. 굵은 선으로 구분되어 있는 3x3 정사각형 안에도 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.

위의 예의 경우, 첫째 줄에는 1을 제외한 나머지 2부터 9까지의 숫자들이 이미 나타나 있으므로 첫째 줄 빈칸에는 1이 들어가야 한다.

![img](https://www.acmicpc.net/upload/images/iWqN5AZPf4h.png)

또한 위쪽 가운데 위치한 3x3 정사각형의 경우에는 3을 제외한 나머지 숫자들이 이미 쓰여있으므로 가운데 빈 칸에는 3이 들어가야 한다.

![img](https://www.acmicpc.net/upload/images/A9FWbU92T9v2Fjr9U6Qsg.png)

이와 같이 빈 칸을 차례로 채워 가면 다음과 같은 최종 결과를 얻을 수 있다.

![img](https://www.acmicpc.net/upload/images/fjCQBE3QI9BMGeiClrtwkHy3jeGPNi.png)

게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진 최종 모습을 출력하는 프로그램을 작성하시오.

#### 입력

아홉 줄에 걸쳐 한 줄에 9개씩 게임 시작 전 스도쿠판 각 줄에 쓰여 있는 숫자가 한 칸씩 띄워서 차례로 주어진다. 스도쿠 판의 빈 칸의 경우에는 0이 주어진다. 스도쿠 판을 규칙대로 채울 수 없는 경우의 입력은 주어지지 않는다.



- 입과테스트 때 너무 고통을 받은 나머지 (제출만 300번 넘게 한건 안자랑) 나름 행복하게 풀었다. 머리보다 손이 기억하는 경지랄까... 오타로 인해 몇 번 틀리긴 했지만 로직 자체는 이해를 하고 있었기 때문에 어렵지 않게 풀었던 문제.

- ```c++
  #include <iostream>
  #include <vector>
  using namespace std;
  bool flag;
  int arr[9][9],cnt;
  vector<pair<int, int> > v;
  
  bool ver(int num, int c){
  	for(int i=0;i<9;i++){
  		if(num==arr[i][c]) return false;
  	}
  	return true;
  }
  
  bool hor(int num, int r){
  	for(int i=0;i<9;i++){
  		if(num==arr[r][i]) return false;
  	}
  	return true;
  }
  
  bool squ(int num, int r,int c){
  	r=r/3;
  	c=c/3;
  	for(int i=r*3;i<(r*3)+3;i++){
  		for(int j=c*3;j<(c*3)+3;j++){
  			if(num==arr[i][j]) return false;
  		}
  	}
  	return true;
  }
  
  
  
  bool dfs(int depth){
  	if(flag)return 0;
  	if(depth==v.size()){
  		for(int i=0;i<9;i++){
  			for(int j=0;j<9;j++){
  				cout<<arr[i][j]<<" ";
  			}
  			cout<<"\n";
  		}
  		flag=true;
  		return 0;
  	}
  	for(int i=1;i<=9;i++){
  		int r=v[depth].first;
  		int c=v[depth].second;
  		if(ver(i,c)&&hor(i,r)&&squ(i,r,c)){
  			arr[r][c]=i;
  			dfs(depth+1);
  			arr[r][c]=0;
  		}
  	}
  	return 0;		
  }
  
  int main(){            
  	for(int i=0;i<9;i++){
  		for(int j=0;j<9;j++){
  			cin>>arr[i][j];
  			if(arr[i][j]==0){
  				v.push_back({i,j});
  			}
  		}
  	}	
  	dfs(0);
  	return 0;
  }
  
  
  ```

  