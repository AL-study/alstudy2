/*
 dp[location][day]�� �޸������̼��� ���� ���Ž�Ű�� bfsŽ�� �Ѵ�.
 day�� 20�� ���� ���Ѵ�. ��� �̵��Ÿ��� 2�辿 �����ϱ� ������
 20������ �ִ� ��ǥ�� 50���� �ѱ� �����̴�. 

 bfs�� �̿��� ���� ����(a)�� ���� Ž������ dpa�迭�� �����Ѵ�.
 ���� ����������, ����(b)�� ���� Ž����Ű�� dpb�迭�� �����ϴµ�,
 �� �� ������ǥ�� ��¥�� ���ٸ� ans�� �������־� ����Ѵ�.
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
