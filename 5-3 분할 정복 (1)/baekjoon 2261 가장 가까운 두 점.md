### 2261. 가장 가까운 두 점 ★★

- n개의 점중 가장 가까운 두 점의 거리의 제곱을 구하는 문제.
- 가장 먼저 떠오른 방법은 완전 탐색이였다. O(n^2)의 시간복잡도가 나오기 때문에 바로 포기했다.

- 분할 정복을 활용하여 문제를 접근할 경우 다음과 같이 접근한다. 
  1. 모든점을 x좌표 기준으로 정렬한다.
  2. n/2번째와 n/2+1번째 점의 x좌표 평균을 기준 직선으로 잡는다.
  3. 이경우 총 3가지로 나뉜다.
     1. 가장 가까운 두 점 모두 왼쪽에 속한다.
     2. 가장 가까운 두 점 모두 오른쪽에 속한다.
     3. 양쪽에 한 점 씩 속한다.
        ![](https://casterian.net/wp-content/uploads/2018/04/%EA%B0%80%EC%9E%A5-%EA%B0%80%EA%B9%8C%EC%9A%B4-%EB%91%90-%EC%A0%90-1-300x242.png)
  4. 양쪽에 점에 있는 경우 O(n^2)이 걸리기 때문에 시간복잡도가 줄어들지 않는다. 따라서 절대 답이 되지 않는 쌍을 가지치기하고 남은 쌍에 대해서만 계산한다. 3-1.경우와 3-2.경우의 두 점사이의 거리의 최솟값을 d를 구하고, d보다 큰 쌍은 비교하지 않는다.

- 처음 접하는 유형이라서 나에겐 너무 어려운 문제였다. 이러한 유형을 풀어보지 않았다면 접근방법을 떠올리기 쉽지 않고, 접근방법을 이해해도 구현이 까다로웠기 때문이다. 비슷한 유형을 풀면서 익숙해져야 할 것 같다.

- ```c++
  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;
  struct POINT{
  	int x,y;
  };
  int n;
  vector<POINT> p;
  int dist(POINT a,POINT b){
  	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
  }
  bool compare(POINT a,POINT b){
  	if(a.x==b.x){
  		return a.y<b.y;
  	}else{
  		return a.x<b.x;
  	}
  }
  bool compare2(POINT a,POINT b){
  	if(a.y==b.y){
  		return a.x<b.x;
  	}else{
  		return a.y<b.y;
  	}
  }
  int closet(vector<POINT>::iterator it,int num){
  	if(num==2){
  		return dist(it[0],it[1]);
  	}
  	if(num==3){
  		return min(min(dist(it[0],it[1]),dist(it[1],it[2])),dist(it[2],it[0]));
  	}
  	int line=(it[num/2-1].x+it[num/2].x)/2;
  	int d=min(closet(it,num/2),closet(it+num/2,num-num/2));
  	vector<POINT> mid;
  	mid.reserve(num);
  	for(int i=0;i<num;i++){
  		int t=line-it[i].x;
  		if(t*t<d){
  			mid.push_back(it[i]);
  		}
  	}
  	sort(mid.begin(),mid.end(),compare2);
  	int mid_sz=mid.size();
  	for(int i=0;i<mid_sz-1;i++){
  		for(int j=i+1;j<mid_sz&&(mid[j].y-mid[i].y)*(mid[j].y-mid[i].y)<d;j++){
  			d=min(d,dist(mid[i],mid[j]));
  		}
  	}
  	return d;
  }
  int main(){
  
  	cin>>n;
  	for(int i=0;i<n;i++){
  		int x,y;
  		cin>>x>>y;
  		p.push_back({x,y});
  	}
  	sort(p.begin(),p.end(),compare);
  	
  	cout<<closet(p.begin(),n);
  	return 0;
  }
  ```

#### 참고출처 :  https://casterian.net/archives/92 



