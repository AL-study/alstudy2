#include <iostream>
#include <cmath>
#include <vector>
#define MAX 1000000
using namespace std;

int n,m,k,tree_s;

long long query(vector<long long> &tree, int node, int start, int end, int num){
	if(start==end){
		return start;
	}
	if(num<=tree[node*2]){
		return query(tree,node*2,start,(start+end)/2,num);
	}else{
		
		return query(tree,node*2+1,(start+end)/2+1,end,num-tree[node*2]);
	}
}
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
	if(index<start || index>end){
		return;
	}
	tree[node]+=diff;
	if(start!=end){
		update(tree,node*2,start,(start+end)/2,index,diff);
		update(tree,node*2+1,(start+end)/2+1,end,index,diff);
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	int h=(int)ceil(log2(MAX));
	tree_s=(1<<(h+1));
	vector<long long> tree(tree_s);
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(a==1){
			int b;
			cin>>b;
			int temp=query(tree,1,0,MAX-1,b);
			cout<<temp<<"\n";
			update(tree,1,0,MAX-1,temp,-1);
		}else{
			int b,c;
			cin>>b>>c;
			update(tree,1,0,MAX-1,b,c);
		}
	}
	
	return 0;
}







