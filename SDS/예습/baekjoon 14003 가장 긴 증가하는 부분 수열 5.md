### 14003. 가장 긴 증가하는 부분 수열 5 ★★



#### 문제

수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {**10**, **20**, 10, **30**, 20, **50**} 이고, 길이는 4이다.

#### 입력

첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (-1,000,000,000 ≤ Ai ≤ 1,000,000,000)



- 가장 긴 증가하는 부분 수열 2와 매우 유사하다. 그러나 가장 긴 증가하는 부분 수열의 개수뿐만 아니라 해당 가장 긴 증가하는 부분 수열을 출력해야 한다. 따라서 가장 긴 증가하는 부분 수열 2처럼 푼다면 틀렸습니다를 보게 될 것이다. 벡터를 갱신하는 방법만 이용한다면 최종 벡터에는 해당 부분 수열을 저장하고 있지 않기 때문이다.

- 가장 긴 증가하는 부분 수열을 구하기 위해서 수를 입력받을 때 마다 해당 **수와 순서를 저장**한다. 예를 들어 배열이 1 6 2 5 7 3 5 6인 경우 다음과 같이 저장한다.

     first   ::  0 1 1 2 3 2 3 4

  second :: 1 6 2 5 7 3 5 6

- 수와 번호순으로 저장한 뒤에 마지막에서 부터 탐색하며 순서를 뽑는다. (역추적)

- 끝에서 부터 탐색했기 때문에 저장하고 출력하면 수가 반대로 출력된다. 따라서 추척하며 스택에 저장하고, 탐색이 끝났을 때 스택을 pop하며 출력한다.

- 가장 긴 증가하는 부분 수열 2와 매우 유사하지만 알고 보면 다른 문제였다. 수와 순서쌍의 저장, 역추적을 이용한 스택 사용 등 전혀 다른 방식의 접근법이 필요했기 때문이다.

- ```c++
  #include <iostream>
  #include <algorithm>
  #include <vector>
  #include <stack>
  using namespace std;
  int n,idx;
  vector<int> v;
  stack<int> s;
  pair<int, int> ans[1000001];
  int main(){
  	cin>>n;
  	for(int i=0;i<n;i++){
  		int num;
  		cin>>num;
  		if(v.empty()||v.back()<num){
  			v.push_back(num);
  			ans[i].first=num;
  			ans[i].second=v.size()-1;
  		}else{
  			vector<int>::iterator it=lower_bound(v.begin(),v.end(),num);
  			*it=num;
  			ans[i].first=num;
  			ans[i].second=it-v.begin();
  		}
  	}
  	cout<<v.size()<<"\n";
  	idx=v.size()-1;
  	for(int i=n-1;i>=0;i--){
  		if(ans[i].second==idx){
  			s.push(ans[i].first);
  			idx--;
  		}
  	}
  	while(!s.empty()){
  		cout<<s.top()<<" ";
  		s.pop();
  	}
  }
  ```

  