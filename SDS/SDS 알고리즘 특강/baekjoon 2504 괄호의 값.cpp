#include <iostream>
#include <stack>
using namespace std;

string str;
stack<char> s;
long long ans,num=1;

int main(){
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]=='('){
			s.push(str[i]);
			num*=2;
		}else if(str[i]=='['){
			s.push(str[i]);
			num*=3;
		}else if(str[i]==')'){
			char temp=str[i-1];
			if(s.empty()||s.top()!='('){
				cout<<0;
				return 0;
			}else{
				if(str[i-1]=='(') ans+=num;
				s.pop();
				num/=2;
			}
		}else if(str[i]==']'){
			char temp=str[i-1];
			if(s.empty()||s.top()!='['){
				cout<<0;
				return 0;
			}else{
				if(str[i-1]=='[') ans+=num;
				s.pop();
				num/=3;
			}
		}	
	}
	if(!s.empty()){
		cout<<0;
	}else{
		cout<<ans;
	}

}
