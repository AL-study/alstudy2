#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int n;
bool c[1000001];
vector<int> v;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=2;i<=sqrt(1000001);i++){
		for(int j=i+i;j<=1000001;j+=i){
			c[j]=true;
		}
	}

	while(1){
		cin>>n;
		if(!n){
			break;
		}else{
			for(int i=3;i<=1000001;i++){
				if(!c[i]&&!c[n-i]){
					cout<<n<<" = "<<i<<" + "<<n-i<<"\n";
					break;
				}
			}	
		}
	}
}
