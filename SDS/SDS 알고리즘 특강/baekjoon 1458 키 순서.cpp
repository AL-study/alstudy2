#include <iostream>
#include <vector>
#define INF 10000000
using namespace std;

int arr[501][501],n,m,d[501],ans; 

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				arr[i][j]=0;
			}else{
				arr[i][j]=INF;
			}
		}
	}
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		arr[a][b]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(arr[i][j]!=INF&&i!=j){
				d[i]++;
				d[j]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(d[i]==n-1)ans++;
	}
	cout<<ans;
}



