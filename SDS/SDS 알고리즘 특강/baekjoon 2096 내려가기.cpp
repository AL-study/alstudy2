#include <iostream>
using namespace std;

int dp1[3],dp2[3],arr[3],temp1[3],temp2[3],n;

int main(){
	cin>>n;

	cin>>arr[0]>>arr[1]>>arr[2];
	
	for(int i=0;i<3;i++){
		dp1[i]=arr[i];
		dp2[i]=arr[i];
		temp1[i]=arr[i];
		temp2[i]=arr[i];
	}

	for(int i=2;i<=n;i++){
		cin>>arr[0]>>arr[1]>>arr[2];
		dp1[0]=max(temp1[0]+arr[0],temp1[1]+arr[0]);
		dp1[1]=max(max(temp1[0]+arr[1],temp1[1]+arr[1]),temp1[2]+arr[1]);
		dp1[2]=max(temp1[1]+arr[2],temp1[2]+arr[2]);
		
		dp2[0]=min(temp2[0]+arr[0],temp2[1]+arr[0]);
		dp2[1]=min(min(temp2[0]+arr[1],temp2[1]+arr[1]),temp2[2]+arr[1]);
		dp2[2]=min(temp2[1]+arr[2],temp2[2]+arr[2]);
		
		for(int j=0;j<3;j++){
			temp1[j]=dp1[j];
			temp2[j]=dp2[j];
		}
		
	}
	
	cout<<max(max(dp1[0],dp1[1]),dp1[2])<<" "<<min(min(dp2[0],dp2[1]),dp2[2]);
	
}
