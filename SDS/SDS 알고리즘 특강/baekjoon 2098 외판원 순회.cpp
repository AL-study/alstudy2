#include <iostream>
#define INF 987654321
using namespace std;

int n,dp[17][1<<16],arr[16][16];

int solve(int node, int visited){
	int &ret = dp[node][visited];
	if(visited==(1<<n)-1){
		if(arr[node][0]!=0){
			return arr[node][0];
		}else{
			return INF;
		}
	}
	if(ret)return ret;
	ret=INF;
	
	for(int next=0;next<n;next++){
		if(visited&(1<<next)||arr[node][next]==0){
			continue;
		}
		int temp=solve(next,visited+(1<<next))+arr[node][next];
		ret=min(ret,temp);
	}
	return ret;	
}


int main(){
	
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	
	cout<<solve(0,1);
	
}
