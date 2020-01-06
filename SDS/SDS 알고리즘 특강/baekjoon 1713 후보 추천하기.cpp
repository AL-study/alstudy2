#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// �ش� ��ȣ�� ��õ�� 
int n,m,reco[101];
// �ð�, ��ȣ 
vector<pair<int,int> > v(100);

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int num;
		cin>>num;
		bool replace=true;
		reco[num]++;
		for(int j=0;j<n;j++){
			// ���ڰ� ����ִ� ��� 
			if(v[j].second==0){
				v[j].second=num;
				v[j].first=i;
				replace=false;
				break;
			}
			// ���ڿ� �̹� �ִ� ���
			if(v[j].second==num){
				replace=false;
				break;
			} 	
		}
		if(replace){
			// idx�� 0 ���� �����ϸ鼭 �� 
			int idx=0;
			for(int j=1;j<n;j++){
				//��õ���� ���� ���� �ð��� ������ ������ ���� 
				if(reco[v[j].second]==reco[v[idx].second]){
					if(v[j].first<v[idx].first){
						idx=j;
					}
				}
				//��õ���� �ٸ� ���� ��õ���� ���� ������ ���� 
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
