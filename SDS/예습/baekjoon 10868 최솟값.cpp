#include <iostream>
#include <vector>
#include <cmath>
#define INF 1500000000
using namespace std;

int n,m,k;


long long initmin(vector<long long> &v, vector<long long> &tree, int node, int start, int end){
	if(start==end){
		return tree[node]=v[start];
	}else{
		return tree[node]=min(initmin(v,tree,node*2,start,(start+end)/2),initmin(v,tree,node*2+1,(start+end)/2+1,end));
	}
}

long long segmin(vector<long long> &tree, int node, int start, int end, int left, int right){
	if(right<start||end<left){
		return INF;
	}
	if(left<=start&&end<=right){
		return tree[node];
	}
	return min(segmin(tree,node*2,start,(start+end)/2,left,right),segmin(tree,node*2+1,(start+end)/2+1,end,left,right));
}


int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	vector<long long> v(n);
	int h=(int)ceil(log2(n));
	int tree_s=(1<<(h+1));
	vector<long long> treemin(tree_s);
	vector<long long> treemax(tree_s);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	initmin(v,treemin,1,0,n-1);

	for(int i=0;i<m;i++){
		long long a,b;
		cin>>a>>b;
		cout<<segmin(treemin,1,0,n-1,a-1,b-1)<<"\n";
	}	
}
