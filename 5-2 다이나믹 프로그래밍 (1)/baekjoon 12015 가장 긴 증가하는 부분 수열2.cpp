#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> v;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		if(v.empty()||v.back()<num){
			v.push_back(num);
		}else{
			vector<int>::iterator it=lower_bound(v.begin(),v.end(),num);
			*it=num;
		}
	}
	cout<<v.size();
}
