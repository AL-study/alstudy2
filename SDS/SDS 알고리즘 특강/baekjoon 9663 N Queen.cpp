#include <iostream>
using namespace std;
int n,ans;
int arr[15];
bool check(int depth){
	for(int i=0;i<depth;i++){
		if(arr[i]==arr[depth] || abs(arr[i]-arr[depth])==abs(i-depth)){
			return false;
		}
	}
	return true;
}
void dfs(int depth){
	if(depth==n){
		ans++;
	}else{
		for(int i=0;i<n;i++){
			arr[depth]=i;
			if(check(depth)){
				dfs(depth+1);
			}
		}
	}
	
}
int main(){
	cin>>n;
	dfs(0);
	cout<<ans;
}

