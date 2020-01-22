#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct DIR{
	int r,c;
};
DIR dir[8]={{1,0},{1,-1},{1,1},{0,1},{0,-1},{-1,0},{-1,1},{-1,-1}};

int n,arr[50][50],cnt,ans=987654321,sr,sc;
string str[50];
bool check[50][50];
vector<int> v;

int dfs(int r,int c,int mn,int mx){
	if(r<0||r>=n||c<0||c>=n||arr[r][c]>mx||arr[r][c]<mn||check[r][c]){
		return 0;
	}
	check[r][c]=true;
	int count =0;
	if(str[r][c]=='K'){
		count++;
	}
	for(int i=0;i<8;i++){
		int nr=dir[i].r+r;
		int nc=dir[i].c+c;
		count+=dfs(nr,nc,mn,mx);
	}
	return count;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(str[i][j]=='K')cnt++;
			if(str[i][j]=='P'){
				sr=i,sc=j;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			v.push_back(arr[i][j]);
		}
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int s=0,e=0;
	while(e<v.size()){
		memset(check,0,sizeof(check));
		if(dfs(sr,sc,v[s],v[e])==cnt){
			ans=min(ans,v[e]-v[s]);
			s++;
		}else{
			e++;
		}
	}
	cout<<ans;
	
}
