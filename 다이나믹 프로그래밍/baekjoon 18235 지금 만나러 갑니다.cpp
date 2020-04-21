/*
 dp[location][day]에 메모이제이션해 값을 갱신시키며 bfs탐색 한다.
 day는 20을 넘지 못한다. 계속 이동거리가 2배씩 증가하기 때문에
 20일차에 최대 좌표인 50만을 넘기 때문이다. 

 bfs를 이용해 먼저 오리(a)를 전부 탐색시켜 dpa배열에 저장한다.
 이후 마찬가지로, 육리(b)를 전부 탐색시키며 dpb배열에 저장하는데,
 이 때 현재좌표와 날짜가 같다면 ans를 갱신해주어 출력한다.
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int a,b,n,dpa[500001][20],dpb[500001][20],d[2]={1,-1},ans=20;

void move_a(){
	queue<pair<int, int> > q;
	q.push({a,0});
	dpa[a][0]=0;
	while(!q.empty()){
		int cur=q.front().first;
		int day=q.front().second;
		int dist=1<<day;
		q.pop();
		for(int i=0;i<2;i++){
			int next=cur+(dist*d[i]);
			if(1<=next&&next<=n){
				if(dpa[next][day+1]==-1){
					dpa[next][day+1]=day+1;
					q.push({next,day+1});
				}
			}
		}		
	}
}
void move_b(){
	queue<pair<int, int> > q;
	q.push({b,0});
	dpb[b][0]=0;
	while(!q.empty()){
		int cur=q.front().first;
		int day=q.front().second;
		int dist=1<<day;
		q.pop();
		if(dpa[cur][day]!=-1&&dpa[cur][day]==dpb[cur][day]){
			ans=day;
			return;
		}
		for(int i=0;i<2;i++){
			int next=cur+(dist*d[i]);
			if(1<=next&&next<=n){
				if(dpb[next][day+1]==-1){
					dpb[next][day+1]=day+1;
					q.push({next,day+1});
				}
			}
		}		
	}
}

int main(){
	memset(dpa,-1,sizeof(dpa));
	memset(dpb,-1,sizeof(dpb));
	cin>>n>>a>>b;
	move_a();
	move_b();
	cout<<((ans==20)?-1:ans);
	return 0;
}
