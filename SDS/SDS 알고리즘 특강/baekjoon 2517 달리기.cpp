#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;

bool compare(pair<long long, long long> a, pair<long long, long long> b){
	return a.second<b.second;
}

long long query(vector<long long> &tree, int node, int start, int end, int left, int right){
	if(end<left ||right<start ){
		return 0;
	}
	if(start>=left&&right>=end){
		return tree[node];
	}
	return query(tree,node*2,start,(start+end)/2,left,right)+query(tree,node*2+1,(start+end)/2+1,end,left,right);
}

void update(vector<long long> &tree, int node,int start, int end, int index){
	
	if(index<start||index>end){
		return;
	}
	tree[node]+=1;
	if(start!=end){
		update(tree,node*2,start,(start+end)/2,index);
		update(tree,node*2+1,(start+end)/2+1,end,index);
	}
}

int main(){
	cin>>n;
	vector<pair<long long, long long > > v(n);
	int h=(int)ceil(log2(n));
	int tree_s=(1<<(h+1));
	vector<long long> tree(tree_s);
	for(int i=0;i<n;i++){
		cin>>v[i].first;
		v[i].second=i;
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		v[i].first=i;
	}
	sort(v.begin(),v.end(),compare);
	for(int i=0;i<n;i++){
		
		int ans=i-query(tree,1,0,n-1,0,v[i].first)+1;
		cout<<ans<<"\n";
		update(tree,1,0,n-1,v[i].first);
	}
	
	
}
