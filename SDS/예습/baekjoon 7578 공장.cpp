#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n,check[1000001];
long long ans;
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
	cin>>n;
	vector<long long> v(n);
	int h=(int)ceil(log2(n));
	int tree_size=(1<<(h+1));
	vector<long long> tree(tree_size);
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		check[a]=i;
	}
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		v[i]=check[a];
	}
	for(int i=0;i<n;i++){
		int temp=v[i];
		ans+=sum(tree,1,0,n-1,temp+1,n-1);
		update(tree,1,0,n-1,temp,1);
	}
	cout<<ans;
}
