#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<int> v,v2;
vector<pair<int, int > > ans(1000001);
stack<int> s;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		if(v.empty()||v[v.size()-1]<num){
			v.push_back(num);
			ans[i].first=num;
			ans[i].second=v.size()-1;
		}else{
			vector<int>::iterator it=lower_bound(v.begin(),v.end(),num);
			*it=num;
			ans[i].first=num;
			ans[i].second=it-v.begin();
			
		}
		
	}
	cout<<v.size()<<"\n";
	int idx=v.size()-1;
	
	for(int i=n-1;i>=0;i--){
		if(ans[i].second==idx){
			s.push(ans[i].first);
			idx--;
		}
	}
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	
}
