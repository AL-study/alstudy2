#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
int n,m,arr[51][51],map[51][51],ans=987654321;
vector<pair<int, int > > home,chick;

void solve(){
	int num=0;
	for(int k=0;k<home.size();k++){
		int minnum=987654321;
		int r=home[k].first;
		int c=home[k].second;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(map[i][j]==2){
					minnum=min(minnum,abs(r-i)+abs(c-j));
				}
			}
		}
		num+=minnum;
	}
	ans=min(ans,num);
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cin>>arr[i][j];
			if(arr[i][j]==1){
				home.push_back({i,j});
			}else if(arr[i][j]==2){
				chick.push_back({i,j});
			}
		}
	}
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			map[i][j]=arr[i][j];
		}
	}
	vector<int> v;
	for(int i=0;i<m;i++){
		v.push_back(1);
	}
	for(int i=0;i<chick.size()-m;i++){
		v.push_back(0);
	}
	sort(v.begin(),v.end());
	do{	
		int num=0;
		int minnum=987654321;
		for(int k=0; k<v.size(); k++){
			int r=chick[k].first;
			int c=chick[k].second;
			if(v[k]==0){
				map[r][c]=0;
			}else{
				map[r][c]=2;
			}
		}
		solve();
	}while(next_permutation(v.begin(),v.end()));
	cout<<ans;
	return 0;
}
