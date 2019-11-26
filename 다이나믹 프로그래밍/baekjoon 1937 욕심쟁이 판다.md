### 1937. 욕심쟁이 판다 ★★

- 해당 배열에서 더 큰 값으로 이동할 수 있을때 최대 경로의 길이를 구하는 문제.

- dfs로 탐색하되, 전부 구하지않고, dp를 이용하여 가지를 친다.

- 해당 배열`arr[i][j]`를 탐색할때, 다음칸`arr[i+x][j+y]`의 값이 `arr[i][j]`보다 크다면 `dp[i][j]=max(dp[i][j],dfs(i+x,j+y)+1)`이다.

- dp값이 존재한다면 return해 가지치기하고, 탐색을 할 때 방문하지 않았다면 (dp값이 0일경우) dp값을 1로 표시해 방문표시한다.

- dfs+dp를 응용해 접근하는 과정이 어려웠던 문제.

- ```c++
  #include <iostream>
  using namespace std;
  int n,dp[501][501],arr[501][501],ans;
  typedef struct DIR{
  	int r,c;
  }DIR;
  DIR dir[4]={{1,0},{-1,0},{0,1},{0,-1}};
  int dfs(int r,int c){
  	if(dp[r][c]){
  		return dp[r][c];
  	}
  	dp[r][c]=1;
  	for(int i=0;i<4;i++){
  		int mr=r+dir[i].r;
  		int mc=c+dir[i].c;
  		if(0<=mr&&mr<n&&0<=mc&&mc<n){
  			if(arr[r][c]<arr[mr][mc]){
  				dp[r][c]=max(dp[r][c],dfs(mr,mc)+1);
  			}		
  		}
  	}
  	return dp[r][c];
  }
  int main(){
  	cin>>n;
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			cin>>arr[i][j];
  		}
  	}
  	for(int i=0;i<n;i++){
  		for(int j=0;j<n;j++){
  			ans=max(ans,dfs(i,j));
  		}
  	}
  	cout<<ans;
  } 
  ```

  