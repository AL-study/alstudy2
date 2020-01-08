#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n,k;
long long ans;
vector<pair<int, int> > v;
vector<int> bag;
priority_queue<int> pq;

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
	for(int i=0;i<k;i++){
		int a;
		cin>>a;
		bag.push_back(a);
	}
	sort(v.begin(),v.end());
	sort(bag.begin(),bag.end());
	
	for(int i=0,j=0;i<bag.size();i++){
		while(bag[i]>=v[j].first&&j<v.size()){
			pq.push(v[j++].second);
		}
		if(!pq.empty()){
			ans+=pq.top();
			pq.pop();
		}
	}
	cout<<ans;
	
}
