#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,arr[26],ans;
vector<int> v(26);
bool compare(int a,int b){
	return a>b;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		int num=1;
		for(int j=str.length()-1;j>=0;j--){
			v[str[j]-'A']+=num;
			num*=10;
		}
	}
	sort(v.begin(),v.end(),compare);
	int number=9;
	for(int i=0;i<10;i++){
		ans+=v[i]*number;
		number--;
	}
	cout<<ans;
}
