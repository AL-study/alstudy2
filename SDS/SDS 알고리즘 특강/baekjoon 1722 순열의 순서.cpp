#include <iostream>
#include <vector>
using namespace std;

int n,k;
long long f[21];
bool check[21];


int main(){
	cin>>n>>k;
	f[0]=1;
	for(int i=1;i<=20;i++){
		f[i]=f[i-1]*i;
	}
	
	if(k==1){
		long long c;
		cin>>c;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			for(int j=1;j<=n;j++){
				if(check[j])continue;
				
				if(c>f[n-1-i]){
					c-=f[n-1-i];
				}else{
					v[i]=j;
					check[j]=true;
					break;
				}
			}
		}
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" ";
		}
	}else{
		long long ans=1;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<n;i++){
			for(int j=1;j<v[i];j++){
				if(!check[j]){
					ans+=f[n-1-i];
				}
			}
			check[v[i]]=true;
		}
		cout<<ans;
	}

}
