#include <iostream>
using namespace std;
int parent[1000001],n,m;
int getparent(int x){
	if(parent[x]==x){
		return x;
	}else{
		return parent[x]=getparent(parent[x]);
	}
}
void unionparent(int x,int y){
	x=getparent(x);
	y=getparent(y);
	if(x<y){
		parent[y]=x;
	}else{
		parent[x]=y;
	}
}
void findunion(int x,int y){
	x=getparent(x);
	y=getparent(y);
	if(x==y){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
	return;
}
int main(){
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
	std::cout.tie(NULL);

	cin>>n>>m;
	for(int i=0;i<=n;i++){
		parent[i]=i;
	}
	for(int i=0;i<m;i++){
		int num,x,y;
		cin>>num>>x>>y;
		if(num==0){
			unionparent(x,y);
		}else{
			findunion(x,y);
		}
		
	}
	
}
