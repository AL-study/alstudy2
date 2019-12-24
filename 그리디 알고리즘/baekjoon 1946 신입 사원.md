### 1946. 신입사원

- 서류순위와 면접순위가 적어도 하나가 다른 지원자보다 떨어지지 않는 자만 선발할 때 채용할 수 있는 인원의 수를 구하는 문제.

- 처음 그리디적인 접근을 했을 때, 서류순위를 기준으로 오름차순으로 정렬한 후 i번째의 면접순위와 i번째 이전의 면접순위들을 비교해 판별하는 방법을 생각했다. 이렇게 구현해도 답은 나온다. 하지만 테스트 케이스의 최대수가 20이고, 지원자의 수 n이 최대 10만이기 때문에 시간초과가 발생한다. O(n^2)으로는 문제를 해결할 수 없다는 뜻이다. 

- 어떻게 시간복잡도를 줄일 수 있을까? for문을 줄이는 방법을 생각해봤다. 생각해보니 i번째마다 처음부터 i-1번째까지 일일히 비교할 필요가 없었다. **처음부터 i-1번째까지의 값중 최솟값보다 작으면 어떤 지원자보다 면접순위가 높은것이 된다. 따라서 최솟값을 갱신하면서 그 최솟값만 비교해주면 O(n)만에 해결할 수 있다.**

- ```c++
  #include <iostream>
  #include <algorithm>
  #include <vector>
  using namespace std;
  int t,n,ans,num;
  vector<pair<int, int> > v;
  int main(){
  	ios_base :: sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	cin>>t;
  	for(int k=0;k<t;k++){
  		cin>>n;
  		ans=0;
  		num=0;
  		v.clear();
  		for(int i=0;i<n;i++){
  			int x,y;
  			cin>>x>>y;
  			v.push_back({x,y});
  		}
  		sort(v.begin(),v.end());
  		for(int i=0;i<n;i++){
  			if(num==0){
  				num=v[i].second;
  				ans++;
  				continue;
  			}
  			if(num>v[i].second){
  				ans++;
  				num=v[i].second;	
  			}
  		}
  		cout<<ans<<"\n";
  	}
  }
  ```

  