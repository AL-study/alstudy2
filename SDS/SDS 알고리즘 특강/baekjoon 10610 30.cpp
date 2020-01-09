#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string str;
int num;
bool c1;
vector<int> v;

bool compare(int a,int b){
	return a>b;
}

int main(){
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]=='0'){
			c1=true;	
		}
		num+=(int)str[i]-(int)'0';
	}
	if(num%3==0&&c1){
		for(int i=0;i<str.length();i++){
			v.push_back((int)str[i]-(int)'0');
		}
		sort(v.begin(),v.end(),compare);
		for(int i=0;i<v.size();i++){
			cout<<v[i];
		}		 
	}else{
		cout<<-1;
	}
}
