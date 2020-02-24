#include <iostream>
#include <math.h>
using namespace std;
long long n,ans;
int k,q;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k>>q;
	for(int i=0;i<q;i++){
		long long a,b;
		cin>>a>>b;
		ans=0;
		if(k==1) cout<<abs(a-b)<<"\n";	
		else{
			while(a!=b){
				ans++;
				if(a<b){
					b=(b-2)/k+1;
				}else{
					a=(a-2)/k+1;
				}
			}
			cout<<ans<<"\n";
		}
	}
}
