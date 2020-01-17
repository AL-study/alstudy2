#include <iostream>
#include <vector>
#include <cstring> 
#define ll long long
using namespace std;

int n;
vector<ll> v;
ll dp[2001][2001],ans;

// ���� �Լ��� ��� �����ϱ� ������ ���� 
// ���� ��������� �̵� 
ll ioi(int left,int right);
ll joi(int left,int right);

// ������ ȯ������ ������ִ� mod���� 
int plusnum(int x){
	return (x+1)%n;
}
// (x-1)%n ���Ͻ� ���� ��Ż 
int minusnum(int x){
	return (x+n-1)%n;
}

ll ioi(int left, int right){
	//Ż������ 
	if(minusnum(left)==right)return 0;
	//ioi�� �׸����ϰ� �����Ѵ�. 
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
	// ������ �������, �������� ��������� ��츦 ������ �ִ� ���� 
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
		//v[i]��ü�� joi���ʸ� �ǽ��Ѱ�. ���� ioi�� �� ���� ȣ�� 
		ans=max(ans,v[i]+ioi(i,i));
	}
	cout<<ans;
}
