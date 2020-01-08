#include <iostream>
#include <cstdio>
using namespace std;
int root,tree[1000001][2];

void post(int node){
	if(!node) return;
	post(tree[node][0]);
	post(tree[node][1]);
	cout<<node<<"\n";
}

int main(){
	cin>>root;
	int value;
	while(cin>>value){
		int node=root;
		while(1){
			if(node<value){
				if(tree[node][1]!=0){
					node=tree[node][1];
				}else{
					tree[node][1]=value;
					break;
				}
			}else{
				if(tree[node][0]!=0){
					node=tree[node][0];
				}else{
					tree[node][0]=value;
					break;
				}
			}
		}
	}
	post(root);
	return 0;
}
