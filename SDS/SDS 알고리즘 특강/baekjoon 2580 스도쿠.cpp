#include <iostream>
#include <vector>
using namespace std;
bool flag;
int arr[9][9],cnt;
vector<pair<int, int> > v;

bool ver(int num, int c){
	for(int i=0;i<9;i++){
		if(num==arr[i][c]) return false;
	}
	return true;
}

bool hor(int num, int r){
	for(int i=0;i<9;i++){
		if(num==arr[r][i]) return false;
	}
	return true;
}

bool squ(int num, int r,int c){
	r=r/3;
	c=c/3;
	for(int i=r*3;i<(r*3)+3;i++){
		for(int j=c*3;j<(c*3)+3;j++){
			if(num==arr[i][j]) return false;
		}
	}
	return true;
}



bool dfs(int depth){
	if(flag)return 0;
	if(depth==v.size()){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<"\n";
		}
		flag=true;
		return 0;
	}
	for(int i=1;i<=9;i++){
		int r=v[depth].first;
		int c=v[depth].second;
		if(ver(i,c)&&hor(i,r)&&squ(i,r,c)){
			arr[r][c]=i;
			dfs(depth+1);
			arr[r][c]=0;
		}
	}
	return 0;		
}

int main(){            
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>arr[i][j];
			if(arr[i][j]==0){
				v.push_back({i,j});
			}
		}
	}	
	dfs(0);
	return 0;
}


