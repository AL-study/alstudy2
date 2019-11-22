#include <iostream>
using namespace std;
int parent[9];
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
int compare(int x,int y){
	x=getparent(x);
	y=getparent(y);
	if(x==y){
		return 1;
	}else{
		return 0;
	}
}
//1-2, 2-3, 3-4, 5-6, 6-7, 7-8 연 결 
int main(){
	for(int i=1;i<=8;i++){
		parent[i]=i;
	}
	unionparent(1,2);
	unionparent(2,3);
	unionparent(3,4);
	unionparent(5,6);
	unionparent(6,7);
	unionparent(7,8);
	cout<<"1과 5는 연결되었나?"<<compare(1,5)<<"\n";
	unionparent(1,5);
	cout<<"1과 5는 연결되었나?"<<compare(1,5)<<"\n";
}
