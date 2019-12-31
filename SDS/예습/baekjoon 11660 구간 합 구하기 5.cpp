#include <iostream>
using namespace std;
int n,m,arr[1025][1025],sum[1025][1025];
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum[i][j]+=sum[i][j-1]+arr[i][j];
		}
	}
	for(int k=0;k<m;k++){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		int ans=0;
		for(int i=x1;i<=x2;i++){
			ans+=sum[i][y2]-sum[i][y1-1];
		}
		cout<<ans<<"\n";
	}
}


