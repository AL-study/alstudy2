/*
	LIS시리즈 문제인 가장 긴 증가하는 부분 수열 2 (https://www.acmicpc.net/problem/12015)
	과 소스코드가 같다. N이 최대 40,000으로 충분히 크기 때문에 N^2의 시간
	복잡도로는 풀 수 없다. 따라서 시간복잡도를 줄여야하고 이 부분을 이분탐색
	을 통해 nlgn으로 줄였다. 가장 긴 증가하는 부분 수열을 저장할 벡터를 선언
	하고 2가지 과정을 통해 수열의 길이를 구한다.

	1. 벡터의 마지막 값(가장 긴 증가하는 수열이기 때문에 마지막 값은 가장 큰 
	값이다.)보다 클 경우 push해준다.
	
	2. 크지 않을 경우, 이분 탐색을 통해 들어갈 자리를 찾고 해당 자리의 값을
	갱신한다.  
	
	벡터의 size가 가장 긴 증가하는 부분수열의 길이이다.
	과정을 보면 알겠지만, 가장 긴 증가하는 부분 수열은 길이를 보장할 뿐,
	해당 부분수열을 저장하고 있는 것은 아니다.
*/

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
