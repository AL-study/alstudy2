#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 1000000000
using namespace std;
int n,m;

int initmax(vector<int> &v, vector<int> &tree, int node, int start, int end){
	if(start==end){
		return tree[node]=v[start];
	}else{
		return tree[node]=max(initmax(v,tree,node*2,start,(start+end)/2),initmax(v,tree,node*2+1,(start+end)/2+1,end));
	}
}

int segmax(vector<int> &tree, int node, int start, int end, int left, int right){
	if(right<start||end<left){
		return 0;
	}
	if(left<=start&&end<=right){
		return tree[node];
	}
	return max(segmax(tree,node*2,start,(start+end)/2,left,right),segmax(tree,node*2+1,(start+end)/2+1,end,left,right));
}

int getidx(int x,vector<int> &v){
	return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	vector<int> v(n);
	vector<int> compress(n);
	int h=(int)ceil(log2(n));
	int tree_s=(1<<(h+1));
	vector<int> tree(tree_s);
	for(int i=0;i<n;i++){
		cin>>compress[i]>>v[i];
	}
	initmax(v,tree,1,0,n-1);
	cin>>m;
	for(int i=0;i<m;i++){
		int a,b;
		bool impossible=false;
		bool maybe=false;
		bool xc=true;
		bool yc=true;
		cin>>a>>b;

		int yidx=getidx(a,compress);
		if(compress[yidx]!=a){
			yc=false;
		}
		int xidx=getidx(b,compress);
		if(compress[xidx]!=b){
			xc=false;
		}
		int xnum,ynum,znum;
		xnum=v[xidx];
		ynum=v[yidx];
		
		if(yc&&!xc){
			znum=segmax(tree,1,0,n-1,yidx+1,xidx-1);
			if(ynum>znum){
				cout<<"maybe\n";
				continue;
			}
		}
		if(!yc&&xc){
			znum=segmax(tree,1,0,n-1,yidx,xidx-1);
			if(xnum>znum){
				cout<<"maybe\n";
				continue;
			}
		}
		if(!yc&&!xc){
			cout<<"maybe\n";
			continue;
		}
		
		if(yc&&xc){
			if(xnum<=ynum){
				znum=segmax(tree,1,0,n-1,yidx+1,xidx-1);
				if(xnum>znum){
					if(xidx-yidx==compress[xidx]-compress[yidx]){
						cout<<"true\n";

					}else{
						cout<<"maybe\n";
					}
					continue;
				}
			}
		}
		cout<<"false\n";	
	}
} 
