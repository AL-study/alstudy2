#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int n,k;
long long arr[100];
long long num,maxnum;
priority_queue<long long,vector<long long>, greater<long long> > pq;
map<long long, bool> m;

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		//pq.push(arr[i]);
	}
	pq.push(1);
	while(k){
		num=pq.top();
		pq.pop();
		for(int i=0;i<n;i++){
			long long value=num*arr[i];
			if(pq.size()>k&&value>maxnum){
				continue;
			}
			if(!m[value]){
				pq.push(value);
				m[value]=true;
				maxnum=max(maxnum,value);
			}
		}
		k--;
	}
	cout<<pq.top();

	
}
