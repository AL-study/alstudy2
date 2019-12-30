#include <iostream>
using namespace std;
int n,k,cnt;
bool arr[1001],flag;
int main(){
	cin>>n>>k;
	for(int i=2;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			if(!arr[j]){
				cnt++;
				arr[j]=true;
				if(cnt==k)cout<<j;
			}
		}
	}
}
