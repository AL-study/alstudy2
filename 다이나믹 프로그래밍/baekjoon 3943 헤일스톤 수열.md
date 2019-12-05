### 3943. 헤일스톤 수열

- 알고리즘 분류는 DP로 되어있지만 굳이 메모이제이션을 하지 않아도 풀 수 있는 문제였다.

- 단순하게 수을 입력받고 최대값을 갱신시키면서 짝수일 경우 2로 나눠주고 홀수일 경우 3을 곱하고 1을 더해주는 과정을 반복수행하면 된다. 아무리 수가 커도 곱하고 나누는 과정이 많지 않기때문이다.

- ```c++
  #include <iostream>
  using namespace std;
  int n;
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);	
  	cin>>n;	
  	for(int i=0;i<n;i++){
  		int num,heils,maxnum;
  		cin>>num;
  		heils=num;
  		maxnum=num;
  		while(heils!=1){
  			maxnum=max(maxnum,heils);
  			if(heils%2==0){
  				heils/=2;
  			}else{
  				heils=heils*3+1;
  			}
  		}
  		cout<<maxnum<<"\n";
  	}
  }
  ```

  