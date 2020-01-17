#include <iostream>
#include <cstring>
#define INF 987654321
using namespace std;

int dp[1<<17],cost[17][17],light,cnt,p,n;
string str;

int solve(int num){
	
	int &ret=dp[num];
	if(cnt>=p)return ret=0;
	if(ret!=-1)return ret;
	cnt++;
	ret=INF;
	for(int i=0;i<n;i++){
		if(num&(1<<i)){
			for(int j=0;j<n;j++){
				if(!(num&(1<<j))){
					ret=min(ret,solve(num+(1<<j))+cost[i][j]);
					//ret=min(ret,solve(num|(1<<j))+cost[i][j]);
				}		
			}
		}
	}
	cnt--;
	return ret;
	
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>cost[i][j];
		}
	}

	cin>>str>>p;

	for(int i=0;i<str.length();i++){
		if(str[i]=='Y'){
			light+=1<<i;
			cnt++;
		}
	}
	int ans=solve(light);
	cout<<(ans==INF ? -1 :ans);
}
