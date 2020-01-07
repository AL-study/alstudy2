#include <iostream>
using namespace std;

long long high,low,mid,ans;
int n,m,arr[1000001];

bool solve(){
	long long num=0;
	for(int i=0;i<n;i++){
		if(arr[i]>mid){
			num=num+arr[i]-mid;
		}
	}
	if(num>=m){
		return true;
	}else{
		return false;
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(high<arr[i]){
			high=arr[i];
		}
	}
	while(low<=high){
		mid=(low+high)/2;
		if(solve()){
			low=mid+1;
			ans=max(ans,mid);
		}else{
			high=mid-1;
		}
	}
	cout<<ans;
}


