### 11266. 단절점



#### 문제

그래프가 주어졌을 때, 단절점을 모두 구해 출력하는 프로그램을 작성하시오.

단절점이란 그 정점을 제거했을 때, 그래프가 두 개 또는 그 이상으로 나누어지는 정점을 말한다. 즉, 제거했을 때 그래프의 connected component의 개수가 증가하는 정점을 말한다.

#### 입력

첫째 줄에 두 정수 V(1≤V≤10,000), E(1≤E≤100,000)가 주어진다. 이는 그래프가 V개의 정점과 E개의 간선으로 이루어져 있다는 의미이다. 다음 E개의 줄에는 간선에 대한 정보를 나타내는 두 정수 A, B가 주어진다. 이는 A번 정점과 B번 정점이 연결되어 있다는 의미이며, 방향은 양방향이다.

입력으로 주어지는 그래프는 연결 그래프가 아닐 수도 있다.



- 단절점의 개념과 구현을 연습할 수 있는 좋은 연습문제.

- DFS를 이용해 해당 노드와 연결되어 있는 노드의 순서를 탐색하는 과정을 재귀적으로 구현하는 과정을 잘 이해하고 익숙해지도록 연습하자.

- ```c++
  #include <iostream>
  #include <vector>
  #include <algorithm>
  
  using namespace std;
  
  vector<int> v[10001];
  int n,e,discovered[10001],num;
  bool ans[10001];
  
  int dfs(int x, bool root){
     discovered[x]=++num;
     int ret=discovered[x];
     int child =0;
     
     for(int i=0;i<v[x].size();i++){
        int y=v[x][i];
        if(discovered[y]){
           ret=min(ret,discovered[y]);
              continue;
        }
        child++;
        int prev=dfs(y,false);
        if(!root&&prev>=discovered[x])
           ans[x]=true;
        ret=min(ret, prev);
     }
     if(root)
        ans[x]=(child>=2);
     return ret;
  }
  
  int main(){
     cin>>n>>e;
     for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
     }
     for(int i=1;i<=n;i++){
        if(!discovered[i]) dfs(i,true);
     }
     int cnt=0;
     for(int i=1;i<=n;i++){
        if(ans[i])cnt++;
     }
     cout<<cnt<<"\n";
     for(int i=1;i<=n;i++){
        if(ans[i])cout<<i<<" ";
     }
  }
  ```

  