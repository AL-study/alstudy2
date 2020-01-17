#include <iostream>
#include <cstring>
using namespace std;

int t,n,dp[1001][1001][2],arr[1001];

int card(int left, int right, bool turn){
	int &ret=dp[left][right][turn];
	if(ret!=-1)return ret;
	if(left>=right){ 
		if(!turn)return ret=arr[left];
		else return ret=0;
	}
	if(!turn){
		return ret=max(card(left+1,right,!turn)+arr[left],card(left,right-1,!turn)+arr[right]);
	}else{
		return ret=min(card(left+1,right,!turn),card(left,right-1,!turn));
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		memset(dp,-1,sizeof(dp));
		
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		cout<<card(1,n,0)<<"\n";
	}
}
