#include <iostream>
using namespace std;

int n,dp[1001][1001],m,car_number[1001][1001];
pair<int, int> pos[1001];

// 거리 
int dist(pair<int, int> a, pair<int, int> b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}

int solve(int x,int y){
	int level=max(x,y)+1;
	//maxlevel 
	if(level==m+2){
		return 0;
	}
	int &ret = dp[x][y];
	if(ret)return ret;
	
	//x가 해결한다.
	ret=solve(level,y)+dist(pos[x],pos[level]);
	
	//y가 해결한다. 
	int ycar=solve(x,level)+dist(pos[level],pos[y]);
	
	//y가 작을 경우 
	if(ycar<ret){
		ret=ycar;
		car_number[x][y]=1;
	}
	return ret;
}

int main(){
	cin>>n>>m;
	for(int i=2;i<m+2;i++){
		cin>>pos[i].first>>pos[i].second;
	}
	pos[0]={1,1};
	pos[1]={n,n};
	cout<<solve(0,1)<<"\n";
	
	for(int x=0,y=1;max(x,y)+1<m+2;){
		cout<<car_number[x][y]+1<<"\n";
		if(car_number[x][y]) y=max(x,y)+1;
		else x=max(x,y)+1;
	}
	
}
