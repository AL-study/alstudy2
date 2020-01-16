#include <iostream>
using namespace std;

int n,m,memo[101],cost[101],d[10001],sum;

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>memo[i];
	}
	for(int i=1;i<=n;i++){
		cin>>cost[i];
		sum+=cost[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=cost[i];j--){
			d[j]=max(d[j],d[j-cost[i]]+memo[i]);
		}
	}
	
	for(int i=0;i<=sum;i++){
		if(d[i]>=m){
			cout<<i;
			return 0;
		}
	}
	
	
	
}
