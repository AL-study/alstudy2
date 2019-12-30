#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v;
int main(){
	cin>>n;
	while(n!=1){
		for(int i=2;i<=n;i++){
			if(n%i==0){
				v.push_back(i);
				n/=i;
				break;
			}
		}
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<"\n";
	}
}
