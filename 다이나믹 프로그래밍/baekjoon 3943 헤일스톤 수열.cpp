#include <iostream>
using namespace std;
int n;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	cin>>n;	
	for(int i=0;i<n;i++){
		int num,heils,maxnum;
		cin>>num;
		heils=num;
		maxnum=num;
		while(heils!=1){
			maxnum=max(maxnum,heils);
			if(heils%2==0){
				heils/=2;
			}else{
				heils=heils*3+1;
			}
		}
		cout<<maxnum<<"\n";
	}
}
