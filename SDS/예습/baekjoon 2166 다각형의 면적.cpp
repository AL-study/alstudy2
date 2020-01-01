#include <iostream>
#include <stdlib.h>
using namespace std;
int n;
long long ans;
typedef struct INFO{
	long long x,y;
};
INFO info[100001];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>info[i].x>>info[i].y;
	}
	for(int i=0;i<n;i++){
		int p1=i;
		int p2=(i+1)%n;
		ans+=(info[p1].x*info[p2].y-info[p2].x*info[p1].y);
	}
	if(ans<0){
		ans*=-1;
	}
	if(ans%2==0){
		cout<<ans/2<<".0";
	}else{
		cout<<ans/2<<".5";
	}
}
