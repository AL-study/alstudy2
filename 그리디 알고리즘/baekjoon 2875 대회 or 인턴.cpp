#include <iostream>
using namespace std;
int n,m,k;
int main(){
	cin>>n>>m>>k;
	cout<<min(min(n/2,m),(n+m-k)/3);
}
