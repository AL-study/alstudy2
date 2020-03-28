#include <iostream>
#include <algorithm>
using namespace std;
int n,k,ans;

int main(){
	cin>>n>>k;
	int low=1;
	int high=k;
	while(low<=high){
		int mid=(low+high)/2;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=min(mid/i,n);
		}
		if(cnt<k) low=mid+1;
		else{
			ans=mid;
			high=mid-1;
		}
	}
	cout<<ans;
}
