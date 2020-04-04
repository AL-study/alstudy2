/*
	ó���� �� ������ ������� �����ߴ�. m���� ������ ���� ������ �� �����͸�
	�ξ ���� ������ �����ϴ� ����� �����ߴ�. �� ������� �������� ����
	������ ���� � ������ �����͸� ������������ �𸥴ٴ� �� �̾���.
	��Ȯ�� ���ش� ���� ������, �� �����͹����� �ݵ�� �Ķ��Ʈ�� ��ġ
	(�̺� Ž��)���� Ǯ �� �ִٴ� ���� �˰��� ������濡�� �þ���, �Ķ��Ʈ��
	��ġ�� ���������� ������ ���� �ʾ� Ǯ�� ����� ������ Ǯ����.

	���������� �ִ밪�� mid������ �̺� Ž���� ������ �ذ��� �� �ִ�.
	�������� ���� �κ��� ��� ������ �ڸ� ���ΰ� ���µ�, �׳� �տ�������
	���������� �ڸ���ȴ�. ������ �ʹ� �����ϰ� �����ߴ� �� ����.

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
