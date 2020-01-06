#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
vector<char> v;
char arr[15];

//  시작, 깊이 ,자음, 모음 
void dfs(int start,int depth, int a,int b){
	if(depth==n){
		if(a>=1&&b>=2){
			for(int i=0;i<n;i++){
				cout<<arr[i];
			}
			cout<<"\n";
		}
	}
	for(int i=start;i<v.size();i++){
		arr[depth]=v[i];
		if(v[i]=='a'||v[i]=='e'||v[i]=='i'||v[i]=='o'||v[i]=='u'){
			dfs(i+1,depth+1,a+1,b);
		}else{
			dfs(i+1,depth+1,a,b+1);
		}
	}
	return;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		char a;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	dfs(0,0,0,0);
}
