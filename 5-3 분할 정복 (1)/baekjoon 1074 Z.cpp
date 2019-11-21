#include <iostream>
#include <math.h>
using namespace std;
int n,r,c,ans;
void dc(int x,int row,int col){
	if(x==2){
		if(row==r&&col==c){
			cout<<ans;
			return;
		}
		ans++;
		if(row==r&&col+1==c){
			cout<<ans;
			return;
		}
		ans++;
		if(row+1==r&&col==c){
			cout<<ans;
			return;
		}
		ans++;
		if(row+1==r&&col+1==c){
			cout<<ans;
			return;
		}
		ans++;
		return;
	}
	dc(x/2,row,col);
	dc(x/2,row,col+x/2);
	dc(x/2,row+x/2,col);
	dc(x/2,row+x/2,col+x/2);
}
int main(){
	cin>>n>>r>>c;
	int num=pow(2,n);
	int arr[num][num];
	dc(num,0,0);
}
