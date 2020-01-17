#include <iostream>
using namespace std;

int dp[5][5][100001],ddr[100001],i;

int check(int foot,int next){
	if(foot==0){
		return 2;
	}
	if(abs(foot-next)==2){
		return 4;
	}else{
		return 3;
	}
}

int solve(int left, int right, int level){
	if(ddr[level]==0){
		return 0;
	}
	int &ret=dp[left][right][level];
	if(ret)return ret;
	
	if(left==ddr[level]||right==ddr[level]){
		ret=solve(left,right,level+1)+1;
	}else{
		ret=solve(ddr[level],right,level+1)+check(left,ddr[level]);
		ret=min(ret,solve(left, ddr[level], level+1)+check(right,ddr[level]));
	}
	return ret;
}

int main(){
	while(1){
		cin>>ddr[i];
		if(ddr[i]==0){
			break;
		}else{
			i++;
		}
	}
	cout<<solve(0,0,0);
}
