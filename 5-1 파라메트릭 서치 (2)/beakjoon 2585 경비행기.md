### 2585 경비행기 ★★

- 이 문제 역시 이분 탐색속에 최소거리를 구하는 BFS를 이용해 가능/불가능을 판별하여 최소값(low) 출력

- 해당 노드의 값을 저장할 큐와 **해당 노드의 상태일 때 경유한 지점의 수를 저장할 큐** 총 2개를 이용

- ```c++
  #include <iostream>
  #include <queue>
  #include <vector>
  #include <cstring>
   
  using namespace std;
  
  int n,k;
  //크기를 1001로하면 런타임에러 
  pair<int,int> v[1010];
  bool check[1010];
  int main(){
   	cin>>n>>k;
   	for(int i=1;i<=n;i++){
   		cin>>v[i].first>>v[i].second;
  	}
   	v[n+1]={10000,10000};
      //최대 길이 (0,0)과 (10000,10000)사이의 거리
   	int low=1,high=14144;
  	while(low<=high){
          //해당 노드의 값을 저장할 큐와 해당 노드의 상태일 때 경유한 지점의 수를 저장할 큐
  		queue<int> q,cq;
   		int fl=0,mid=(low+high)/2;
   		for(int i=1;i<=n+1;i++) check[i]=false;
  		q.push(0),cq.push(0);
  		check[0]=true;
  		while(!q.empty()){
  			int cur=q.front(),cnt=cq.front();
  			q.pop(),cq.pop();
  			if(cur==n+1){
  				fl=1;
  				break;
  			}
  			if(cnt==k+1){
  				continue;
  			}
  			for(int i=1;i<=n+1;i++){
  				if(!check[i] && mid*mid>(v[cur].first-v[i].first)*(v[cur].first-v[i].first)+(v[cur].second-v[i].second)*(v[cur].second-v[i].second)){
  					check[i]=true;
  					q.push(i);
  					cq.push(cnt+1);
  				}
  			}
  		}
  		if(fl){
  			high=mid-1;
  		}else{
  			low=mid+1;
  		}
  	}
   	cout<<low/10+!(!(low%10));
  }
  ```

