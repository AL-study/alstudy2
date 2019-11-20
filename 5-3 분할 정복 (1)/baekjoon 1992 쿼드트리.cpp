#include<iostream>
using namespace std;
int n;
string arr[64];
void solve(int x,int r,int c){
	if(x==1){
		cout<<arr[r][c];
		return;
	}
	bool zero=true,one=true;
	for(int i=r;i<x+r;i++){
		for(int j=c;j<x+c;j++){
			if(arr[i][j]=='1'){
				zero=false;
			}else{
				one=false;
			}	
		}
	}
	if(zero){
		cout<<"0";
	}else if(one){
		cout<<"1";
	}else{
		cout<<"(";
		solve(x/2,r,c);
		solve(x/2,r,c+x/2);
		solve(x/2,r+x/2,c);
		solve(x/2,r+x/2,c+x/2);
		cout<<")";
	}
	return;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	solve(n,0,0);
}
