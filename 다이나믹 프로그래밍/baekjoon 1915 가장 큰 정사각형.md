### 1915. 가장 큰 정사각형 ★

- 처음 접해 보는 유형이여서 그런지 오랜시간 고민했음에도 감도 오지 않았다. 블로그를 참고 했고, 그림을 통해 이해했지만 쉽게 떠올리기 어려운 접근방법이었다. (이런 어려운문제가 실버라니...(solved.ac기준))

- dp의 정의는 다음과 같다.
  `dp[i][j]는 i,j를 마지막 좌표로(우측하단 좌표) 하는 가장 큰 정사각형의 한 변의 길이`

  해당 배열이 0인 경우는 무시하고, (1이 아니면 정사각형이 될 수 없으므로) 해당 배열의 왼쪽, 위, 대각의 최솟값+1과 해당 배열의 최댓값을 갱신해주면서 나아간다. dp 최댓값의 제곱이 답이된다. 왜 이렇게 되는지는 그림을 통해 이해하기로 하자.

- ![이미지 출처:  https://baejji-codingbox.tistory.com/entry/1915 ](https://t1.daumcdn.net/cfile/tistory/99CFC9425B026D7F2D)

- 쉽게 떠올리기 어려운 접근방법이다. 많은 문제를 풀면서 익숙해지자.

- ```c+
  #include <iostream>
  using namespace std;
  int n,m,dp[1001][1001],arr[1001][1001],ans;
  int main(){
  	cin>>n>>m;
  	for(int i=1;i<=n;i++){
  		string temp="";
  		cin>>temp;
  		for(int j=1;j<=m;j++){
  			arr[i][j]=temp[j-1]-48;
  			dp[i][j]=arr[i][j];
  		}
  	}
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=m;j++){
  			if(dp[i][j]==0)continue;
  			int num=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
  			dp[i][j]=max(num+1,dp[i][j]);
  			ans=max(ans,dp[i][j]);
  		}
  	}
  	cout<<ans*ans;
  }
  ```

- #### 참고 출처 :  https://baejji-codingbox.tistory.com/entry/1915 

  