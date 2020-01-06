#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m,ans;
bool check[26];
string str[50];
void dfs(int start, int depth){
	if(depth==m-5){
		int cnt=0;
		for(int i=0;i<n;i++){
			bool flag=false;
			for(int j=0;j<str[i].length();j++){
				if(!check[str[i][j]-'a']){
					flag=true;
					break;
				}
			}
			if(!flag){
				cnt++;
			}
		}
		ans=max(ans,cnt);
		return;
	}
	for(int i=start;i<26;i++){
		if(!check[i]){
			check[i]=true;
			dfs(i,depth+1);
			check[i]=false;	
		}
	}
	return;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	if(m<5){
		cout<<0;
		return 0;
	}
	check['a'-'a']=true;
	check['c'-'a']=true;
	check['t'-'a']=true;
	check['i'-'a']=true;
	check['n'-'a']=true;
	
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	dfs(0,0);
	cout<<ans;
}

