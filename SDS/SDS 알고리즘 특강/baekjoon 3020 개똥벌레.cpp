#include <iostream>
using namespace std;

int n,k,ans=987654321,cnt;
int input[200000],h[500000];

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>input[i];
		if(i%2==0){
			h[0]++;
			h[input[i]]--;
		}else{
			h[k-input[i]]++;
		}
	}
	for(int i=0;i<k;i++){
		h[i]+=h[i-1];
	}
	for(int i=0;i<k;i++){
		if(ans>h[i]){
			ans=h[i];
			cnt=1;
		}else if(ans==h[i]){
			cnt++;
		}
	}
	cout<<ans<<" "<<cnt;
}
