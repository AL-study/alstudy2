### 1072. Z

- 분할 정복의 개념을 이해하기 좋은 문제.

- 각 구역을 4구역으로 나누고 시작 인덱스를 4등분하여 탐색한다.

- 종료조건을 n==1일경우로 정의하면 시간초과가 난다. 4배만 큼을 더 분기하기 때문이다. 따라서 n==2일경우 바로 리턴해야 한다.

- ```c++
  #include <iostream>
  #include <math.h>
  using namespace std;
  int n,r,c,ans;
  void dc(int x,int row,int col){
  	if(x==2){
  		if(row==r&&col==c){
  			cout<<ans;
  			return;
  		}
  		ans++;
  		if(row==r&&col+1==c){
  			cout<<ans;
  			return;
  		}
  		ans++;
  		if(row+1==r&&col==c){
  			cout<<ans;
  			return;
  		}
  		ans++;
  		if(row+1==r&&col+1==c){
  			cout<<ans;
  			return;
  		}
  		ans++;
  		return;
  	}
  	dc(x/2,row,col);
  	dc(x/2,row,col+x/2);
  	dc(x/2,row+x/2,col);
  	dc(x/2,row+x/2,col+x/2);
  }
  
  int main(){
  	cin>>n>>r>>c;
  	int num=pow(2,n);
  	int arr[num][num];
  	dc(num,0,0);
  }
  ```