### 9663. N Queen



#### 문제

N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

#### 입력

첫째 줄에 N이 주어진다. (1 ≤ N < 15)



- dfs의 hello world격 문제. dfs를 구현하면 되고 핵심은 대각선을 판별하는 조건문이었다.

- ```c++
  #include <iostream>
  using namespace std;
  int n,ans;
  int arr[15];
  bool check(int depth){
  	for(int i=0;i<depth;i++){
  		if(arr[i]==arr[depth] || abs(arr[i]-arr[depth])==abs(i-depth)){
  			return false;
  		}
  	}
  	return true;
  }
  void dfs(int depth){
  	if(depth==n){
  		ans++;
  	}else{
  		for(int i=0;i<n;i++){
  			arr[depth]=i;
  			if(check(depth)){
  				dfs(depth+1);
  			}
  		}
  	}
  	
  }
  int main(){
  	cin>>n;
  	dfs(0);
  	cout<<ans;
  }
  
  ```

  