#include <iostream>
using namespace std;

int dp[3000][3000],n,arr[51],num,m;
double per[51];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		num+=arr[i];
	}
	cin>>m;
	double ans=0;
	for(int i=1;i<=n;i++){
		if(arr[i]<m)continue;
		double temp=1;
		for(int j=0;j<m;j++){
			temp*=(double)(arr[i]-j)/(num-j);
		}
		per[i]=temp;
	}
	for(int i=1;i<=n;i++){
		ans+=per[i];
	}
	printf("%.15lf",ans);
	//cout<<(double)ans1/dp[num][m];
}
