#include <iostream>
#include <algorithm>
using namespace std;

int n,m,arr[100001],low,high;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	cin>>m;
	for(int i=0;i<m;i++){
		int num;
		cin>>num;
		bool flag=false;
		low=0;high=n-1;
		while(low<=high){
			int mid=(low+high)/2;
			if(num==arr[mid]){
				flag=true;
				break;
			}else if(num<arr[mid]){
				high=mid-1;
			}else{
				low=mid+1;
			}
		}
		if(flag){
			cout<<"1\n";
		}else{
			cout<<"0\n";
		}
	}
	return 0;
}
