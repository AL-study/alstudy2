#include <iostream>
using namespace std;

int n,m,arr[1000001];


int getparent(int x){
	if(arr[x]==x){
		return x;
	}
	return arr[x]=getparent(arr[x]);
}

void unionparent(int x,int y){
	x=getparent(x);
	y=getparent(y);
	if(x<y){
		arr[y]=x;
	}else{
		arr[x]=y;
	}
}
void findparent(int x,int y){
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
		arr[i]=i;
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==0){
			unionparent(b,c);
		}else{
			findparent(b,c);
		}
	}
} 
