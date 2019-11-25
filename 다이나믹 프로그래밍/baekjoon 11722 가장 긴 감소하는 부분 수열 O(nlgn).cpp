#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,arr[1001];
vector<int> v;
vector<int>::iterator it;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	reverse(arr,arr+n);
	for(int i=0;i<n;i++){
		if(v.empty()||v.back()<arr[i]){
			v.push_back(arr[i]);
		}else{
			it=lower_bound(v.begin(),v.end(),arr[i]);
			*it=arr[i];
		}
	}
	cout<<v.size();
}
