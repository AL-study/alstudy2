#include <iostream>
using namespace std;

int n,k,cnt;
bool c[1000];
int main(){
	cin>>n>>k;
	for(int i=2;i<=n;i++){
		if(!c[i]){
			c[i]=true;
			cnt++;
			if(cnt==k){
				cout<<i;
				return 0;
			}
			for(int j=i+i;j<=n;j+=i){
				if(!c[j]){
					c[j]=true;
					cnt++;
					if(cnt==k){
						cout<<j;
						return 0;
					}
				}
			}
		}
	}
}
