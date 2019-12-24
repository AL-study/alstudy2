#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t,n,ans,num;
vector<pair<int, int> > v;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		ans=0;
		num=0;
		v.clear();
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			v.push_back({x,y});
		}
		sort(v.begin(),v.end());
		for(int i=0;i<n;i++){
			if(num==0){
				num=v[i].second;
				ans++;
				continue;
			}
			if(num>v[i].second){
				ans++;
				num=v[i].second;	
			}
		}
		cout<<ans<<"\n";
	}
}
