#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,arr1[4000],arr2[4000],arr3[4000],arr4[4000];
vector<int> v1,v2;
long long ans;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr1[i]>>arr2[i]>>arr3[i]>>arr4[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int sum=0;
			sum=arr1[i]+arr2[j];
			v1.push_back(sum);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int sum=0;
			sum=arr3[i]+arr4[j];
			v2.push_back(sum);
		}
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	
	
	int p1=0,p2=v2.size()-1;
	
	while(1){
		if(v1[p1]+v2[p2]==0){
			long long cnt1=1;
			long long cnt2=1;
			while(p1+1<=v1.size()-1&&v1[p1]==v1[p1+1]){
				p1++;
				cnt1++;
			}
			while(p2-1>=0&&v2[p2]==v2[p2-1]){
				p2--;
				cnt2++;
			}
			ans+=cnt1*cnt2;
			p1++;
		}
		if(p1<=v1.size()-1&&p2>=0&&v1[p1]+v2[p2]<0){
			p1++;
		}
		if(p1<=v1.size()-1&&p2>=0&&v1[p1]+v2[p2]>0){
			p2--;
		}
		if(p1>v1.size()-1||p2<0){
			break;	
		}
	}
	
	cout<<ans;

}
