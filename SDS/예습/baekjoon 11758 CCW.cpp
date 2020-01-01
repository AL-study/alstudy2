#include <iostream>
using namespace std;
int x1,x2,x3,y1,y2,y3;
int main(){
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	int temp=x1*y2+x2*y3+x3*y1;
	temp=temp-y1*x2-y2*x3-y3*x1;
	if(temp>0){
		cout<<1;
	}else if(temp==0){
		cout<<0;
	}else{
		cout<<-1;
	}
}
