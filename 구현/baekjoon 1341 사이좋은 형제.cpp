/*
 조건을 보면 b의 최대 값이 2^63이기때문에, 2^1-1~ 2^63-1의 값을 벡터에
 미리 저장해 두었다. 
 먼저, 길이가 60이상인 것은 -1을 출력해야하는데, 다음과 같다.
 1. b가 짝수이다.
 2. b가 홀수지만 2^n-1(n은 60이하)를 b로 나누었을 때 몫이 0이 아니다.
 
 십진수를 이진수를 바꾸는 방법으로 구현했다. 십진수를 계속 2로 나누어 
 나머지를 통해 이진수로 치환할 수 있는데, 거꾸로 출력해 하므로 스택에
 넣고 다시 pop하는 방식으로 구현했다. 

 가장 헤맨 부분은 문제이해를 잘못해서인데, 문제에서는 일단 영식이가 절반을 
 먹고라는 부분에서 영식이가 항상 먼저 먹는줄 알았는데, 민식이가 영식이보다
 먼저 먹는 경우까지 생각해줘야한다. 이 부분 때문에 reverse변수를 두어서
 해결했다.

 너무 더럽게 구현한 것 같다.
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
