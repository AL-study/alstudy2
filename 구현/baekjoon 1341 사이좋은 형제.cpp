/*
 ������ ���� b�� �ִ� ���� 2^63�̱⶧����, 2^1-1~ 2^63-1�� ���� ���Ϳ�
 �̸� ������ �ξ���. 
 ����, ���̰� 60�̻��� ���� -1�� ����ؾ��ϴµ�, ������ ����.
 1. b�� ¦���̴�.
 2. b�� Ȧ������ 2^n-1(n�� 60����)�� b�� �������� �� ���� 0�� �ƴϴ�.
 
 �������� �������� �ٲٴ� ������� �����ߴ�. �������� ��� 2�� ������ 
 �������� ���� �������� ġȯ�� �� �ִµ�, �Ųٷ� ����� �ϹǷ� ���ÿ�
 �ְ� �ٽ� pop�ϴ� ������� �����ߴ�. 

 ���� ��� �κ��� �������ظ� �߸��ؼ��ε�, ���������� �ϴ� �����̰� ������ 
 �԰��� �κп��� �����̰� �׻� ���� �Դ��� �˾Ҵµ�, �ν��̰� �����̺���
 ���� �Դ� ������ ����������Ѵ�. �� �κ� ������ reverse������ �ξ
 �ذ��ߴ�.

 �ʹ� ������ ������ �� ����.
*/
#include <iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

ll a,b;
vector<ll> v;
stack<char> s;
bool flag,reverse;

void solve(){
	while(a){
		if(a%2==1) s.push('*');		
		else s.push('-');
		a/=2;
	}
}

int main(){
	cin>>a>>b;
	ll num=1;
	for(int i=1;i<=63;i++){
		v.push_back((num<<i)-1);
	}
	if(b%2==0||b>v[59]){
		cout<<"-1";
		return 0;
	}
	for(int i=0;i<=59;i++){
		if(v[i]>=b&&v[i]%b==0){
			ll temp=v[i]/b;
			a*=temp;
			b*=temp;
			flag=true;
			if((b+1)/2>a){
				reverse=true;
				a=b-a;
			}
			break;
		}	
	}
	if(!flag){
		cout<<"-1";
		return 0;
	}
	solve();
	while(!s.empty()){
		if(reverse){
			if(s.top()=='*') cout<<'-';
			else cout<<'*';	
		}else cout<<s.top();
		s.pop();	
	}
}
