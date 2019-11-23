#include <iostream>
#include <map>
using namespace std;
int n,f,set[200002],fnum[200002];

int getparent(int x){
	if(x==set[x]){
		return x;
	}else{
		return set[x]=getparent(set[x]);
	}
}
int unionparent(int x,int y){
	x=getparent(x);
	y=getparent(y);
	if(x!=y){
		set[x]=y;
		fnum[y]+=fnum[x];
		fnum[x]=1;
	}
	return fnum[y];
}

int main(){
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>f;
		int cnt=1;
		for(int j=1;j<=f*2;j++){
			set[j]=j;
			fnum[j]=1;
		}
		map<string,int> parent;
		for(int j=0;j<f;j++){
			string a,b;
			cin>>a>>b;
			if(parent.count(a)==0){
				parent[a]=cnt++;
			}
			if(parent.count(b)==0){
				parent[b]=cnt++;
			}
			cout<<unionparent(parent[a],parent[b])<<"\n";
		}
	}
}
