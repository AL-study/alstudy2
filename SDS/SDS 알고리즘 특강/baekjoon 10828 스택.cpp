#include <iostream>
#include <stack>
using namespace std;

int n;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	stack<int> s;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		if(str=="push"){
			int num;
			cin>>num;
			s.push(num);
		}else if(str=="pop"){
			if(!s.empty()){
				cout<<s.top()<<"\n";
				s.pop();
			}else{
				cout<<"-1\n";
			}
		}else if(str=="size"){
			cout<<s.size()<<"\n";
		}else if(str=="empty"){
			cout<<s.empty()<<"\n";
		}else if(str=="top"){
			if(!s.empty()){
				cout<<s.top()<<"\n";
			}else{
				cout<<"-1\n";
			}
			
		}
		
	}
}
