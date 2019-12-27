#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t,n,m,arr1[1000],arr2[1000];
long long ans;
vector<int> v1,v2;
int main(){
	cin>>t>>n;
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>arr2[i];
	}
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=arr1[j];
			v1.push_back(sum);
		}	
	}
	for(int i=0;i<m;i++){
		int sum=0;
		for(int j=i;j<m;j++){
			sum+=arr2[j];
			v2.push_back(sum);
		}	
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int p1=0, p2=v2.size()-1;
	while(1){
		if(v1[p1]+v2[p2]==t){
			long long cnt1=1;
			long long cnt2=1;
			while(p1+1<=v1.size()-1&&v1[p1+1]==v1[p1]){
				p1++;
				cnt1++;
			}
			while(p2-1>=0&&v2[p2-1]==v2[p2]){
				p2--;
				cnt2++;
			}
			ans+=cnt1*cnt2;
			p1++;
		}
		if(p1<=v1.size()-1&&p2>=0&& v1[p1]+v2[p2]<=t){
			p1++;
		}if(p1<=v1.size()-1&&p2>=0&&v1[p1]+v2[p2]>t){
			p2--;
		}if(p1>v1.size()-1||p2<0){
			break;
		}
	}
	cout<<ans;
}
