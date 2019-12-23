#include <iostream>
using namespace std;
string a,b;
int minnum=100000;
int main(){
	cin>>a>>b;
	int num=b.length()-a.length();
	for(int i=0;i<=num;i++){
		int temp=0;
		for(int j=0;j<a.length();j++){
			if(b[j+i]!=a[j]){
				temp++;
			}
		}
		minnum=min(minnum,temp);
	}
	cout<<minnum;
}
