#include <iostream>
using namespace std;
int n,m,dp[301][301],k,arr[301][301];
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=dp[i][j-1]+dp[i-1][j]+arr[i][j]-dp[i-1][j-1];
		}
	}
	cin>>k;
	for(int i=0;i<k;i++){
		int start_x,start_y,end_x,end_y;
		cin>>start_x>>start_y>>end_x>>end_y;
		cout<<dp[end_x][end_y]-dp[end_x][start_y-1]-dp[start_x-1][end_y]+dp[start_x-1][start_y-1]<<"\n";
	}
}
