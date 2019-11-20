### 9252 LCS2 ★

- [9251 LCS]( https://www.acmicpc.net/problem/9251 )와 똑같은 문제.

- 다만 마지막에 해당 수열까지 출력해 주어야한다.

- dp를 string으로 선언해 값을 저장하고, length()로 갯수를 출력한다.

- ```c++
  #include <iostream>
  using namespace std;
  string a,b;
  int arr1[1001],arr2[1001],ans;
  string dp[1001][1001];
  int main(){
  	cin>>a>>b;
  	for(int i=0;i<a.length();i++){
  		for(int j=0;j<b.length();j++){
  			if(a[i]==b[j]){
  				dp[i+1][j+1]=dp[i][j]+b[j];
  			}else{
  				if(dp[i][j+1].length()>dp[i+1][j].length()){
  					dp[i+1][j+1]=dp[i][j+1];
  				}else{
  					dp[i+1][j+1]=dp[i+1][j];
  				}
  			}
  		}
  	}
  	cout<<dp[a.length()][b.length()].length()<<"\n";
  	cout<<dp[a.length()][b.length()];
  }
  ```

  