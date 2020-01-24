#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct DIR{
	int r,c;
};

DIR dir[4]={{1,0},{-1,0},{0,-1},{0,1}};

int n,m,x,y,ans,waternum;
string str[50];
vector<pair<int, int> > water,stone;
bool check[50][50];

void waterplus(){
	int num=water.size();
	for(int k=0;k<num;k++){
		int r=water[k].first;
		int c=water[k].second;
		for(int i=0;i<4;i++){
			int nr=r+dir[i].r;
			int nc=c+dir[i].c;
			if(0<=nr&&nr<n&&0<=nc&&nc<m&&str[nr][nc]=='.'){
				water.push_back({nr,nc});
				str[nr][nc]='*';	
			}
		}
	}
}

void solve(int start_x, int start_y){
	queue<pair<int, int> > q;
	queue<int> cnt;
	check[start_x][start_y]=true;
	q.push({start_x,start_y});
	cnt.push(1);
	
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		int count=cnt.front();
		if(waternum!=count){
			waterplus();
			waternum++;
		}
//		cout<<"\n";
//		for(int i=0;i<n;i++){
//			cout<<str[i]<<"\n";
//		}
//		cout<<"\n";
//		cout<<"시작: "<<r<<" "<<c<<" "<<count<<"\n";
		q.pop();
		cnt.pop();
		//waterplus();
		for(int i=0;i<4;i++){
			int nr=r+dir[i].r;
			int nc=c+dir[i].c; 
			if(0<=nr&&nr<n&&0<=nc&&nc<m&&str[nr][nc]!='*'&&str[nr][nc]!='X'&&!check[nr][nc]){
//				cout<<"탐색예정: "<<nr<<" "<<nc<<" "<<count<<"\n";
				if(str[nr][nc]=='D'){
					cout<<count;
					return;
				}
				q.push({nr,nc});
				check[nr][nc]=true;
				cnt.push(count+1);	
			}
		}
	}
	cout<<"KAKTUS";
	return;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<str[i].length();j++){
			if(str[i][j]=='S'){
				x=i,y=j;
			}else if(str[i][j]=='*'){ 
				water.push_back({i,j});
			}else if(str[i][j]=='X'){
				stone.push_back({i,j});
			}
		}
	}
	solve(x,y);
		
}
