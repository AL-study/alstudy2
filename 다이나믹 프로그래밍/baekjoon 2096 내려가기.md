### 2096. 내려가기

- 메모리제한(4MB)이 있는 특이한 문제. 

-  점화식은 어렵지 않게 세울수 있다.  먼저 dp를 정의해보자.
  `dp[i][j]=i번째줄의 j번째칸을 선택했을 때의 최대/최소값`
  따라서 다음과 같이 점화식을 세울수 있다.

  ```c++
  for(int i=1;i<=n;i++){
  		cin>>arr[0]>>arr[1]>>arr[2];
  		maxdp[i][0]=max(maxdp[i-1][0],maxdp[i-1][1])+arr[0];
  		mindp[i][0]=min(mindp[i-1][0],mindp[i-1][1])+arr[0];
  		
  		maxdp[i][1]=max(max(maxdp[i-1][0],maxdp[i-1][1]),maxdp[i-1][2])+arr[1];
  		mindp[i][1]=min(min(mindp[i-1][0],mindp[i-1][1]),mindp[i-1][2])+arr[1];
  		
  		maxdp[i][2]=max(maxdp[i-1][1],maxdp[i-1][2])+arr[2];
  		mindp[i][2]=min(mindp[i-1][1],mindp[i-1][2])+arr[2];
  	}
  ```

- 그러나 이렇게 접근하면 메모리제한으로 인해 메모리초과가 난다. n이 10만개이하이기 때문에 dp배열을 최솟값, 최댓값 각각 10만 x 3개씩 필요하기 때문이다. 

- 생각해보면 모든 dp배열을 따져야 하는 것이 아니다. i번째 dp배열을 계산할때 i-1디피배열의 값만 알고 있으면 되기 때문이다. 따라서 굳이 10만개를 선언하지 않아도 임시배열에 저장해 값을 갱신시키는 방식으로 풀 수 있다.

- ```c++
  #include <iostream>
  using namespace std;
  //maxtemp는 i-1번째, maxdp는 i번째 dp배열의 값을 저장한다.
  int maxtemp[3],maxdp[3];
  int mintemp[3],mindp[3];
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	int n,arr[3];
  	cin>>n;
  	cin>>arr[0]>>arr[1]>>arr[2];
  	for(int i=0;i<3;i++){
  		maxtemp[i]=arr[i];
  		mintemp[i]=arr[i];
  		maxdp[i]=arr[i];
  		mindp[i]=arr[i];
  	}
  	for(int i=2;i<=n;i++){
  		cin>>arr[0]>>arr[1]>>arr[2];
  		maxdp[0]=max(maxtemp[0],maxtemp[1])+arr[0];
  		mindp[0]=min(mintemp[0],mintemp[1])+arr[0];
  		maxdp[1]=max(max(maxtemp[0],maxtemp[1]),maxtemp[2])+arr[1];
  		mindp[1]=min(min(mintemp[0],mintemp[1]),mintemp[2])+arr[1];
  		maxdp[2]=max(maxtemp[1],maxtemp[2])+arr[2];
  		mindp[2]=min(mintemp[1],mintemp[2])+arr[2];
  		//값을 다시 갱신한다.
  		maxtemp[0]=maxdp[0];
  		mintemp[0]=mindp[0];
  		maxtemp[1]=maxdp[1];
  		mintemp[1]=mindp[1];
  		maxtemp[2]=maxdp[2];
  		mintemp[2]=mindp[2];
  
  	}
  	cout<<max(max(maxdp[0],maxdp[1]),maxdp[2])<<" "<<min(min(mindp[0],mindp[1]),mindp[2]);
  }
  ```

  