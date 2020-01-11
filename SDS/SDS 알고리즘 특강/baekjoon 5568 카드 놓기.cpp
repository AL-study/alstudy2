#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k,cnt,arr[10];
vector<int> v;
vector<string> v2;
bool check[100];
string str;

void dfs(int depth){
	if(depth==k){
		string temp="";
		for(int i=0;i<k;i++){
			temp+=to_string(arr[i]);
		}
		v2.push_back(temp);
		return;
	}
	for(int i=0;i<n;i++){
		if(!check[i]){
			check[i]=true;
			arr[depth]=v[i];
			dfs(depth+1);
			check[i]=false;
			int repeat=1;
			while(v[i]==v[i+repeat]){
				repeat++;
			}
			i+=repeat-1;
		}
	}
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	dfs(0);
	string s="";
	sort(v2.begin(),v2.end());
	for(int i=0;i<v2.size();i++){
		if(s!=v2[i]){
			cnt++;
			s=v2[i];
			//cout<<s<<"\n";
		}
	}
	cout<<cnt;
}
