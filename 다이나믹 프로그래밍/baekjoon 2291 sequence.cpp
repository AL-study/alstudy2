#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n,m,k,dp[221][11][221];
vector<int> v;

int dfs(int first, int len, int sum){
	if(len==1){
		if(first<=sum)	return 1;
		else return 0;
	}
	int &ret=dp[first][len][sum];
	if(ret!=-1) return ret;
	ret=0;
	for(int i=first;i<=sum;i++){
		ret+=dfs(i,len-1,sum-i);
	}
	return ret;	
}

void tracking(int first, int len, int sum, int knum){
	if(len==1){
		v.push_back(sum);
		return;
	}
	int ret=dfs(first,len-1,sum-first);	
	
	if(ret>=knum){
		v.push_back(first);
		tracking(first,len-1,sum-first,knum);
	}else{
		tracking(first+1,len,sum,knum-ret);
	}
}

int main(){
	cin>>n>>m>>k;
	memset(dp,-1,sizeof(dp));
	tracking(1,n,m,k);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
}
