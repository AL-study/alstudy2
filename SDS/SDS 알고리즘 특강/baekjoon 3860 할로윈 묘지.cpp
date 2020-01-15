#include <iostream>
#include <cstring>
#include <vector>
#define INF 987654321
using namespace std;

typedef struct Hole{
	int from,to,cost;
};

typedef struct DIR{
	int x,y;
};

DIR dir[4]={{0,1},{1,0},{-1,0},{0,-1}};

int n,m,g,e,arr[30][30],d[900],num;
vector<Hole> ev;
bool cycle,stone[30][30],hole[30][30];

void bellman(){
	// 정점들을 연결하는 과정 
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(stone[i][j]||hole[i][j]||(i==m-1&&j==n-1))continue;
			for(int k=0;k<4;k++){
				int mr=i+dir[k].x;
				int mc=j+dir[k].y;
				if(0<=mr&&mr<m&&0<=mc&&mc<n&&!stone[mr][mc]){
					ev.push_back({i*n+j,mr*n+mc,1});
				}
				
			}
		}
	}
	int num=n*m-g; 
	
	for(int i=0;i<num-1;i++){
		for(int j=0;j<ev.size();j++){
			if(d[ev[j].from]!=INF&&d[ev[j].to]>d[ev[j].from]+ev[j].cost){
				d[ev[j].to]=d[ev[j].from]+ev[j].cost;
			}
		}
	}
	for(int j=0;j<ev.size();j++){
		if(d[ev[j].from]!=INF&&d[ev[j].to]>d[ev[j].from]+ev[j].cost){
			cycle=true;
			break;
		}
	}

	if(cycle)cout<<"Never\n";
	else if(d[n*m-1]==INF)cout<<"Impossible\n";
	else cout<<d[n*m-1]<<"\n";
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(1){
		//n=열, m=행 
		cin>>n>>m;
		if(!n&&!m) break;
		ev.clear();
		cycle=false;
		memset(hole,false,sizeof(hole));
		memset(stone,false,sizeof(stone));
		for(int i=0;i<n*m;i++){
			d[i]=INF;
		}
		d[0]=0;
		
		cin>>g;
		for(int i=0;i<g;i++){
			int a,b;
			cin>>b>>a;
			stone[a][b]=true;
		} 
		cin>>e;
		for(int i=0;i<e;i++){
			int x1,y1,x2,y2,t;
			cin>>y1>>x1>>y2>>x2>>t;
			ev.push_back({x1*n+y1,x2*n+y2,t});
			hole[x1][y1]=true;
		}
		
		bellman();	
		
	}
}
