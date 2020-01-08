#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n,m;

long long init(vector<long long> &v, vector<long long> &tree, int node, int start, int end){
	if(end==start) return tree[node]=v[start];
	return tree[node]=init(v,tree,node*2,start,(start+end)/2)+init(v,tree,node*2+1,(start+end)/2+1,end);
} 

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right){
	if(right<start||end<left) return 0;
	if(start>=left&&right>=end) return tree[node];
	return sum(tree,node*2,start,(start+end)/2,left,right)+sum(tree,node*2+1,(start+end)/2+1,end,left,right);
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
	cin>>n>>m;
	vector<long long> v(n);
	int h=(int)ceil(log2(n));
	int tree_s=(1<<(h+1));
	vector<long long> tree(tree_s);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	init(v,tree,1,0,n-1);
	for(int i=0;i<m;i++){
		long long x,y,a,b;
		cin>>x>>y>>a>>b;
		if(x>y){
			swap(x,y);
		}
		cout<<sum(tree,1,0,n-1,x-1,y-1)<<"\n";
		long long diff=b-v[a-1];
		v[a-1]=b;
		update(tree,1,0,n-1,a-1,diff);
		
	}
	return 0;
}

