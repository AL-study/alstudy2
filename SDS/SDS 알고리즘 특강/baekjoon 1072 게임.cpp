#include <iostream>
using namespace std;
long long x,y,z,ans=1000000000,low,high=1000000000,mid;

int main(){
	cin>>x>>y;
	int z=100*y/x;
	if(z==100||z==99){
		cout<<-1;
		return 0;
	}
	while(low<=high){
		mid=(low+high)/2;
		long long temp=100*(y+mid)/(x+mid);
		if(temp>z){
			high=mid-1;
			ans=min(ans,mid);
		}else{
			low=mid+1;
		}
	}
	cout<<ans;
	return 0;
}


