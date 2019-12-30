#include <iostream>
#include <vector>
#define INF 10000000
using namespace std;

int arr[101][101],n,m; 

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
		int a,b,c;
		cin>>a>>b>>c;
		if(arr[a][b]){
			arr[a][b]=min(arr[a][b],c);
		}else{
			arr[a][b]=c;
		}
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
			if(arr[i][j]==INF){
				cout<<0<<" ";
			}else{
				cout<<arr[i][j]<<" ";
			}
		}
		cout<<"\n";
	}
}



