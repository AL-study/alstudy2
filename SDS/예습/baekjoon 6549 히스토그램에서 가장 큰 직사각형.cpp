#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;

void init(vector<long long> &v, vector<long long> &tree, int node, int start, int end){
	if(start==end){
		tree[node]=start;
	}else{
		init(v,tree,node*2,start,(start+end)/2);
		init(v,tree,node*2+1,(start+end)/2+1,end);
		if(v[tree[node*2]]<=v[tree[node*2+1]]){
			tree[node]=tree[node*2];
		}else{
			tree[node]=tree[node*2+1];
		}
	}
}

long long segfind(vector<long long> &v, vector<long long> &tree, int node, int start, int end, int left, int right){
	if(right<start||end<left){
		return -1;
	}
	if(left<=start&&end<=right){
		return tree[node];
	}
	long long m1=segfind(v,tree,node*2,start,(start+end)/2,left,right);
	long long m2=segfind(v,tree,node*2+1,(start+end)/2+1,end,left,right);
	if(m1==-1){
		return m2;
	}else if(m2==-1){
		return m1;
	}else{
		if(v[m1]<=v[m2]){
			return m1;
		}else{
			return m2;
		}
	}	
}

long long getmax(vector<long long> &v,vector<long long> &tree, int start, int end){
	int num=v.size();
	int m=segfind(v,tree,1,0,num-1,start,end);
	
	long long area=(long long)(end-start+1)*v[m];
	
	if(start<=m-1){
		long long temp=getmax(v,tree,start,m-1);
		area=max(area,temp);
	}
	if(m+1<=end){
		long long temp=getmax(v,tree,m+1,end);
		area=max(temp,area);
	}
	return area;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(1){
		cin>>n;
		if(n==0)return 0;
		vector<long long> v(n);
		int h=(int)ceil(log2(n));
		int tree_s=(1<<(h+1));
		vector<long long> tree(tree_s);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		init(v,tree,1,0,n-1);
		cout<<getmax(v,tree,0,n-1)<<"\n";
	}
}
