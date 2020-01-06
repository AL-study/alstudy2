#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 해당 번호의 추천수 
int n,m,reco[101];
// 시간, 번호 
vector<pair<int,int> > v(100);

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int num;
		cin>>num;
		bool replace=true;
		reco[num]++;
		for(int j=0;j<n;j++){
			// 액자가 비어있는 경우 
			if(v[j].second==0){
				v[j].second=num;
				v[j].first=i;
				replace=false;
				break;
			}
			// 액자에 이미 있는 경우
			if(v[j].second==num){
				replace=false;
				break;
			} 	
		}
		if(replace){
			// idx를 0 부터 갱신하면서 비교 
			int idx=0;
			for(int j=1;j<n;j++){
				//추천수가 같을 경우는 시간이 오래된 순으로 갱신 
				if(reco[v[j].second]==reco[v[idx].second]){
					if(v[j].first<v[idx].first){
						idx=j;
					}
				}
				//추천수가 다를 경우는 추천수가 적은 순으로 갱신 
				else if(reco[v[j].second]<reco[v[idx].second]){
					idx=j;
				}
			}
			reco[v[idx].second]=0;
			v[idx].first=i;
			v[idx].second=num;
		}
	}
	vector<int> ans;
	for(int i=0;i<n;i++){
		ans.push_back(v[i].second);
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	
}
