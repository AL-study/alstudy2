#include <iostream>
#include <math.h>
using namespace std;
int n;
void dc(int target,int from,int to,int none){
	if(target==1){
		cout<<from<<" "<<to<<"\n";
	}
	else{
		dc(target-1,from,none,to);
		//dc(1,from,to,none);
		dc(target-1,none,to,from);
	}
}
int main(){
	cin>>n;
	int cnt=pow(2,n)-1;
	cout<<cnt<<"\n";
	dc(n,1,3,2);
}
