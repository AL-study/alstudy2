#include <iostream>
using namespace std;

int n,m,arr[100001],sum[100002];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];

	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+arr[i];
	}

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		cout<<sum[b]-sum[a-1]<<"\n";
	}

}
