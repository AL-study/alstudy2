### 1062. 가르침



#### 문제

남극에 사는 김지민 선생님은 학생들이 되도록이면 많은 단어를 읽을 수 있도록 하려고 한다. 그러나 지구온난화로 인해 얼음이 녹아서 곧 학교가 무너지기 때문에, 김지민은 K개의 글자를 가르칠 시간 밖에 없다. 김지민이 가르치고 난 후에는, 학생들은 그 K개의 글자로만 이루어진 단어만을 읽을 수 있다. 김지민은 어떤 K개의 글자를 가르쳐야 학생들이 읽을 수 있는 단어의 개수가 최대가 되는지 고민에 빠졌다.

남극언어의 모든 단어는 "anta"로 시작되고, "tica"로 끝난다. 남극언어에 단어는 N개 밖에 없다고 가정한다. 학생들이 읽을 수 있는 단어의 최댓값을 구하는 프로그램을 작성하시오.

#### 입력

첫째 줄에 단어의 개수 N과 K가 주어진다. N은 50보다 작거나 같은 자연수이고, K는 26보다 작거나 같은 자연수 또는 0이다. 둘째 줄부터 N개의 줄에 남극 언어의 단어가 주어진다. 단어는 영어 소문자로만 이루어져 있고, 길이가 8보다 크거나 같고, 15보다 작거나 같다. 모든 단어는 중복되지 않는다.



- dfs를 응용해 풀 수 있는 문제. 여러 조건이 있는데 anta로 시작되고 tica로 끝난 다는 것은 결국 a, c, i ,n, t를 모두 포함해야 한다는 점이다. 그렇다면 5개 이하인 경우는 기본적인 알파벳도 못 들어가기 때문에 0이 될 것이다. 항상 이 알파벳들을 포함해야 하고 그에 따른 dfs의 깊이도 설정해주어야 한다는 점을 염두에 두고 풀어보자.

- ```c++
  #include <iostream>
  #include <algorithm>
  #include <cstring>
  using namespace std;
  int n,m,ans;
  bool check[26];
  string str[50];
  void dfs(int start, int depth){
  	if(depth==m-5){
  		int cnt=0;
  		for(int i=0;i<n;i++){
  			bool flag=false;
  			for(int j=0;j<str[i].length();j++){
  				if(!check[str[i][j]-'a']){
  					flag=true;
  					break;
  				}
  			}
  			if(!flag){
  				cnt++;
  			}
  		}
  		ans=max(ans,cnt);
  		return;
  	}
  	for(int i=start;i<26;i++){
  		if(!check[i]){
  			check[i]=true;
  			dfs(i,depth+1);
  			check[i]=false;	
  		}
  	}
  	return;
  }
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	cin>>n>>m;
  	if(m<5){
  		cout<<0;
  		return 0;
  	}
  	check['a'-'a']=true;
  	check['c'-'a']=true;
  	check['t'-'a']=true;
  	check['i'-'a']=true;
  	check['n'-'a']=true;
  	
  	for(int i=0;i<n;i++){
  		cin>>str[i];
  	}
  	dfs(0,0);
  	cout<<ans;
  }
  
  ```

  