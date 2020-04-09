#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct DIR{
	int r,c;
};

int n,m,cnt,arr[300][300],map[300][300];
DIR dir[4]={{1,0},{-1,0},{0,-1},{0,1}};
bool check[300][300];

void bfs(int sr, int sc){
	queue<pair<int, int> > q;
	q.push({sr,sc});
	check[sr][sc]=true;
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nr=r+dir[i].r;
			int nc=c+dir[i].c;
			if(0<=nr&&nr<n&&0<=nc&&nc<m&&arr[nr][nc]!=0&&!check[nr][nc]){
				check[nr][nc]=true;
				q.push({nr,nc});
			}
		}
	}
}

int chk(){
	memset(check,false,sizeof(check));
	bool zero=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]!=0) zero=false;
		}
	}
	if(zero) return 0;
	bool flag=false;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]!=0&&!check[i][j]){
				if(!flag) {
					bfs(i,j);
					flag=true;
				}else return cnt;
			}
		}
	}
	return -1;
}


void solve(){
	memset(map,0,sizeof(map));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]!=0){
				for(int k=0;k<4;k++){
					int nr=i+dir[k].r;
					int nc=j+dir[k].c;
					if(0<=nr&&nr<n&&0<=nc&&nc<m&&arr[nr][nc]==0){
						map[i][j]++;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			arr[i][j]-=map[i][j];
			if(arr[i][j]<0) arr[i][j]=0;
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	while(true){
		int ans=chk();
		if(ans!=-1){
			cout<<ans;
			return 0;
		}
		solve();
		cnt++;
	}
	
} 
