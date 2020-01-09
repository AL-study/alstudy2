#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;
int n,ans;
bool c[4000001];

int main(){
	cin>>n;
	for(int i=2;i<=sqrt(n);i++){
		if(c[i])continue;
		for(int j=i+i;j<=n;j+=i){
			c[j]=true;
		}
	}
	for(int i=2;i<=n;i++){
		if(!c[i])v.push_back(i);
	}
	int s=0,e=0,sum=0;
	while(1){
		
		if(sum>=n){
			sum-=v[s++];
		}else if(e==v.size()){
			break;
		}else{
			sum+=v[e++];
		}
		if(sum==n){
			ans++;
		}
	}
	cout<<ans;
	
		
}
