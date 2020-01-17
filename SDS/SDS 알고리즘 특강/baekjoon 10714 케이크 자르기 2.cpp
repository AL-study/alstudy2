#include <iostream>
#include <vector>
#include <cstring> 
#define ll long long
using namespace std;

int n;
vector<ll> v;
ll dp[2001][2001],ans;

// 양쪽 함수가 모두 참조하기 때문에 선언 
// 서로 재귀적으로 이동 
ll ioi(int left,int right);
ll joi(int left,int right);

// 선형을 환형으로 만들어주는 mod연산 
int plusnum(int x){
	return (x+1)%n;
}
// (x-1)%n 리턴시 범위 이탈 
int minusnum(int x){
	return (x+n-1)%n;
}

ll ioi(int left, int right){
	//탈출조건 
	if(minusnum(left)==right)return 0;
	//ioi는 그리디하게 선택한다. 
	if(v[minusnum(left)]>v[plusnum(right)]){
		return joi(minusnum(left),right);
	}else{
		return joi(left,plusnum(right));
	}
}

ll joi(int left,int right){
	ll &ret=dp[left][right];
	if(ret!=-1){
		return ret;
	}
	if(minusnum(left)==right)return ret=0;
	// 왼쪽을 골랐을때, 오른쪽을 골랐을때의 경우를 선택해 최댓값 갱신 
	ll num1=v[minusnum(left)]+ioi(minusnum(left),right);
	ll num2=v[plusnum(right)]+ioi(left,plusnum(right));
	return ret=max(num1,num2);
}


int main(){
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++){
		//v[i]자체가 joi차례를 실시한것. 따라서 ioi는 그 이후 호출 
		ans=max(ans,v[i]+ioi(i,i));
	}
	cout<<ans;
}
