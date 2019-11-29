#include <iostream>
using namespace std;
int maxtemp[3],maxdp[3];
int mintemp[3],mindp[3];
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,arr[3];
	cin>>n;
	cin>>arr[0]>>arr[1]>>arr[2];
	for(int i=0;i<3;i++){
		maxtemp[i]=arr[i];
		mintemp[i]=arr[i];
		maxdp[i]=arr[i];
		mindp[i]=arr[i];
	}
	for(int i=2;i<=n;i++){
		cin>>arr[0]>>arr[1]>>arr[2];
		maxdp[0]=max(maxtemp[0],maxtemp[1])+arr[0];
		mindp[0]=min(mintemp[0],mintemp[1])+arr[0];
		maxdp[1]=max(max(maxtemp[0],maxtemp[1]),maxtemp[2])+arr[1];
		mindp[1]=min(min(mintemp[0],mintemp[1]),mintemp[2])+arr[1];
		maxdp[2]=max(maxtemp[1],maxtemp[2])+arr[2];
		mindp[2]=min(mintemp[1],mintemp[2])+arr[2];
		
		maxtemp[0]=maxdp[0];
		mintemp[0]=mindp[0];
		maxtemp[1]=maxdp[1];
		mintemp[1]=mindp[1];
		maxtemp[2]=maxdp[2];
		mintemp[2]=mindp[2];

	}
	cout<<max(max(maxdp[0],maxdp[1]),maxdp[2])<<" "<<min(min(mindp[0],mindp[1]),mindp[2]);
}
