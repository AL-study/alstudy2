#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n,m,k;
long long init(vector <long long> &arr, vector<long long> &tree, int node, int start, int end){
	if(start==end){
		return tree[node]=arr[start];
	}else{
		return tree[node]=init(arr, tree, node*2,start,(start+end)/2)+init(arr, tree, node*2+1,(start+end)/2+1,end);
	}
}
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree,node*2, start, (start+end)/2, index, diff);
        update(tree,node*2+1, (start+end)/2+1, end, index, diff);
    }
}
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right){
	if(left>end||right<start){
		return 0;
	}
	if(left<=start&& end<=right){
		return tree[node];
	}
	return sum(tree, node*2,start,(start+end)/2,left,right)+sum(tree, node*2+1,(start+end)/2+1,end,left,right);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>k;
	vector<long long> v(n);
	int h=(int)ceil(log2(n));
	int tree_size=pow(2,h+1)-1;
	//int tree_size=(1<<(h+1));
	vector<long long> tree(tree_size);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int mk=m+k;
	init(v, tree, 1, 0, n-1);
	for(int i=0;i<mk;i++){
		long long a,b,c;
		cin>>a>>b>>c;
		if(a==1){
			b-=1;
			long long diff=c-v[b];
			v[b]=c;
			update(tree,1,0,n-1,b,diff);
		}else if(a==2){
			cout<<sum(tree,1,0,n-1,b-1,c-1)<<"\n";
		}
	}
	return 0;	
}
