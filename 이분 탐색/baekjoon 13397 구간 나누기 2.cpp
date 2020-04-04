/*
	처음엔 투 포인터 방식으로 접근했다. m개의 구간에 대해 각각의 투 포인터를
	두어서 서로 간격을 조정하는 방식을 생각했다. 이 방식으로 접근했을 때의
	문제는 서로 어떤 구간의 포인터를 움직여야할지 모른다는 것 이었다.
	정확히 이해는 되지 않지만, 투 포인터문제는 반드시 파라메트릭 서치
	(이분 탐색)으로 풀 수 있다는 말을 알고리즘 오픈톡방에서 봤었고, 파라메트릭
	서치로 접근했지만 생각이 나지 않아 풀이 방법을 참고해 풀었다.

	구간점수의 최대값을 mid값으로 이분 탐색해 문제를 해결할 수 있다.
	생각하지 못한 부분은 어떻게 구간을 자를 것인가 였는데, 그냥 앞에서부터
	순차적으로 자르면된다. 오히려 너무 복잡하게 생각했던 것 같다.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,mid,high,low,ans,cnt;
vector<int> v,temp;

int score(){
	int min = *min_element(temp.begin(), temp.end());
	int max = *max_element(temp.begin(), temp.end());
	return max-min;
}
bool solve(){
	temp.clear();
	for(int i=0;i<n;i++){
		temp.push_back(v[i]);
		if(score()>mid){
			cnt++;
			temp.clear();
			temp.push_back(v[i]);
		}
	}
	return cnt<=m;
}

int main(){
	cin>>n>>m;
	v.resize(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	high = *max_element(v.begin(), v.end());
	ans=high;
	while(low<=high){
		cnt=1;
		mid=(high+low)/2;
		if(solve()){
			ans=mid;
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	cout<<ans;
}
