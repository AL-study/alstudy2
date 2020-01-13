#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,ans[9];
bool check[9];
vector<int> v;


void dfs(int depth){
	if(depth==m){
		for(int i=0;i<m;i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=0;i<n;i++){
		if(!check[i]){
			ans[depth]=v[i];
			check[i]=true;
			dfs(depth+1);
			check[i]=false;
			int repeat=1;
			while(v[i]==v[i+repeat]){
				repeat++;
			}
			i+=repeat-1;
		}
	}
	
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	dfs(0);	
}
