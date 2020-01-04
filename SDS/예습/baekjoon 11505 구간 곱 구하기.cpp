#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int n,m,k;
long long init(vector<long long> &v, vector<long long> &tree, int node, int start, int end){
	if(start==end){
		return tree[node]*=v[start];
	}else{
		return tree[node]=(init(v,tree,node*2,start,(start+end)/2)*init(v,tree,node*2+1,(start+end)/2+1,end))%1000000007;
	}
}

long long query(vector<long long> &tree, int node, int start, int end, int left, int right){
	if(right<start||end<left){
		return 1;
	}
	if(left<=start&&end<=right){
		return tree[node];
	}
	return (query(tree,node*2,start,(start+end)/2,left,right)*query(tree,node*2+1,(start+end)/2+1,end,left,right))%1000000007;
}

long long update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
	if(index<start || index>end){
		return tree[node];
	}
	if(start==end){
		return tree[node]=diff;
	}
	if(start!=end){
		return tree[node]=(update(tree,node*2,start,(start+end)/2,index,diff)*update(tree,node*2+1,(start+end)/2+1,end,index,diff))%1000000007;
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>k;
	vector<long long> v(n);
	int h=(int)ceil(log2(n));
	int tree_s=(1<<(h+1));
	vector<long long>tree(tree_s);
	for(int i=0;i<tree_s;i++){
		tree[i]=1;
	}
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	init(v,tree,1,0,n-1);

	for(int i=0;i<m+k;i++){
		long long a,b,c;
		cin>>a>>b>>c;
		if(a==1){
			//v[b-1]=c;
			update(tree,1,0,n-1,b-1,c);

		}else{
			cout<<query(tree,1,0,n-1,b-1,c-1)<<"\n";
		}
	}
}
