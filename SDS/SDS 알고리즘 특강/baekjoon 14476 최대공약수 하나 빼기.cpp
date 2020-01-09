#include <iostream>
#include <algorithm>
using namespace std;

long long n,arr[1000001],dp[1000001],dp2[1000001],ans,idx,num;

long long gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	dp[0]=arr[0];
	dp2[n-1]=arr[n-1];
	for(int i=1;i<n;i++){
		dp[i]=gcd(arr[i],dp[i-1]);
	}
	for(int i=n-2;i>=0;i--){
		dp2[i]=gcd(arr[i],dp2[i+1]);
	}
	if(arr[0]<dp2[1]||gcd(arr[0],dp2[1])!=dp2[1]){
		ans=dp2[1];
	}
	for(int i=1;i<n-1;i++){
		num=gcd(dp[i-1],dp2[i+1]);
		if(arr[i]<num||gcd(arr[i],num)!=num){
			if(ans<num){
				ans=num;
				idx=i;
			}
		}
	}
	if(arr[n-1]<dp[n-2]||gcd(arr[n-1],dp[n-2])!=num){
		if(ans<num){
			ans=dp[n-2];
			idx=n-2;
		}
	}	
	if(ans==0){
		cout<<-1;
	}else{
		cout<<ans<<" "<<arr[idx];
	}
}
