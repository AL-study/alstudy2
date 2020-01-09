#include <iostream>
using namespace std;
int n,ans[1001];
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ans[1]=2;
	for(int i=2;i<=1000;i++){
		int cnt=0;
		for(int j=1;j<i;j++){
			if(gcd(i,j)==1){
				cnt++;
			}
		}
		ans[i]=ans[i-1]+cnt*2;
	}
	
	
	cin>>n;
	for(int k=0;k<n;k++){
		int num;
		cin>>num;
		cout<<ans[num]+1<<"\n";
		
	}
	
}
